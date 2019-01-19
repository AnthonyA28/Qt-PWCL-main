/*
Copyright (C) 2019  Anthony Arrowood

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCursor>



/*
*   Called when the application is first opened.
*   Configures main window, log files, and more..
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    // timer is used to repeatedly check for port data until we are connected
    this->timerId = startTimer(250);  // timer is used to repeatedly check for port data until we are connected
    // indicates when we are connected to the port AND the correct arduino program is being run
    this->validConnection = false;
    // initialize the input vector to hold the input values from the port
    this->inputs = std::vector<float>(this->numInputs); // initialize the input vector to hold the input values from the port
    // have the table resize with the window
    ui->outputTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);   // have the table resize with the window
    // deafault the tab widget on manual, and disable any input (until we are connected)
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(0,false);
    ui->tabWidget->setTabEnabled(1,false);

    /*
    *  Connect functions from the PORT class to functions declared in the MainWIndow class and vice versa.
    */
    connect(&port, &PORT::request, this, &MainWindow::showRequest);     // when the port recieves data it will emit PORT::request thus calling MainWindow::showRequest
    connect(&port, &PORT::disconnected, this, &MainWindow::disonnectedPopUpWindow);
    connect(this, &MainWindow::response, &port, &PORT::L_processResponse);  // whn the set button is clicked, it will emit MainWindow::response thus calling PORT::L_processResponse


    /*
    *  Prepare data logging files. One in excel format named this->excelFileName
    *  and two in csv file format named this->csvFileName, another csv file
    *  with titled with the current date will copy the contents of this->csvFileName.
    */
    // Move to the directy above the executable
    QString execDir = QCoreApplication::applicationDirPath();
    QDir::setCurrent(execDir);
    QDir newDir = QDir::current();
    newDir.cdUp();  // go one directory up so we dont place our output next to the dependencies
    QDir::setCurrent(newDir.path());

    // create the media player
    this->player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(execDir+"/alarm.wav"));


    this->excelFileName = "excelFile.xlsx";
    this->csvFileName   = "data.csv";

    if (QFile::exists(this->excelFileName)) {
        QFile oldFile(this->excelFileName);
        oldFile.remove();
    }

    // give the excel file column headers
    this->xldoc.write( 1 , 1, "Time");
    this->xldoc.write( 1 , 2, "Percent On");
    this->xldoc.write( 1 , 3, "Temperature");
    this->xldoc.write( 1 , 4, "Filtered Temperature");
    this->xldoc.write( 1 , 5, "Set Point");

    // open the csv file and give it a header
    this->csvdoc.setFileName(this->csvFileName);
    if (this->csvdoc.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&this->csvdoc);
        stream << "Time, percent on, Temp, Temp filtered, Set Point\n";
    }
    else
        qDebug() << " Failed to open data.csv \n";


    /*
    * Set up the live plot on the GUI/
    * The set point must have a special scatterstyle so it doesnt connect the lines
    */
    ui->plot->addGraph();
    ui->plot->graph(0)->setName("Set Point");
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, QColor("orange"), 8));
    ui->plot->graph(0)->setPen(QPen(Qt::white)); // so we dont see the line connecting the dots
    ui->plot->graph(0)->setValueAxis(ui->plot->yAxis2);

    ui->plot->addGraph();
    ui->plot->graph(1)->setName("Temperature");
    ui->plot->graph(1)->setPen(QPen(Qt::green));
    ui->plot->graph(1)->setValueAxis(ui->plot->yAxis2);

    ui->plot->addGraph();
    ui->plot->graph(2)->setName("Temperature Filtered");
    ui->plot->graph(2)->setPen(QPen(Qt::blue));
    ui->plot->graph(2)->setValueAxis(ui->plot->yAxis2);

    ui->plot->addGraph();
    ui->plot->graph(3)->setName("Percent Heater on");
    ui->plot->graph(3)->setPen(QPen(QColor("purple"))); // line color for the first graph


    ui->plot->xAxis2->setVisible(true);  // show x ticks at top
    ui->plot->xAxis2->setVisible(false); // dont show labels at top
    ui->plot->yAxis2->setVisible(true);  // right y axis labels
    ui->plot->yAxis2->setTickLabels(true);  // show y ticks on right side for temperature

    ui->plot->yAxis->setLabel("Heater [%]");
    ui->plot->yAxis2->setLabel("Temperature [C]");
    ui->plot->xAxis->setLabel("Time [min]");

    // we dont want a legend
    ui->plot->legend->setVisible(false);

}



/**
*   Called when the window is closed.
*   Creates and saves a backup file of logged data.
*/
MainWindow::~MainWindow()
{
    if (this->port.L_isConnected()) {
        // ensure a backupfile directory exists, create one if it doesnt
        QDir backupDir("backupFiles");
        if( !backupDir.exists() )
             backupDir.mkpath(".");
        QDir::setCurrent("backupFiles");

        // Create a backup file titles with the current date and time
        QDateTime currentTime(QDateTime::currentDateTime());
        QString dateStr = currentTime.toString("d-MMM--h-m-A");
        dateStr.append(".csv"); // the 's' cant be used when formatting the time string
        this->csvdoc.copy(dateStr);
    }
    this->csvdoc.close();

        delete ui;
}



/**
*   Called when data was read from the port.
*   Fills a new row in the output table. Updates the graph, and any parameters shown in the GUI.
*/
void MainWindow::showRequest(const QString &req)
{
    if (req.contains('!')) {
        ui->emergencyMessageLabel->setText(req);
        if(req.contains("overheat")) {
            player->setVolume(100);
            player->play();
        }
        return;
    }

    if (this->deserializeArray(req.toStdString().c_str(), this->numInputs, this->inputs)) {

        if (!this->validConnection) {
            this->validConnection = true;  // String was parsed therefore the correct arduino program is uploaded
            // enable the tab widgets so the user an input vales
            ui->tabWidget->setTabEnabled(0,true);
            ui->tabWidget->setTabEnabled(1,true);
            ui->emergencyMessageLabel->clear();
        }

        double time       = static_cast<double>(inputs[i_time]);
        double percentOn  = static_cast<double>(inputs[i_percentOn]);
        double temp       = static_cast<double>(inputs[i_temperature]);
        double tempFilt   = static_cast<double>(inputs[i_tempFiltered]);
        double setPoint   = static_cast<double>(inputs[i_setPoint]);
        double fanSpeed   = static_cast<double>(inputs[i_fanSpeed]);
        double kc         = static_cast<double>(inputs[i_kc]);
        double tauI       = static_cast<double>(inputs[i_tauI]);
        double tauD       = static_cast<double>(inputs[i_tauD]);
        double tauF       = static_cast<double>(inputs[i_tauF]);
        bool inAutoMode   = static_cast<bool>(inputs[i_autoMode]);  // true if we are in automatic mode
        bool positionForm = static_cast<bool>(inputs[i_positionForm]);
        bool filterAll    = static_cast<bool>(inputs[i_filterAll]);

        /*
        *  Update the output table with the last parameters read from the port.
        */
        ui->outputTable->insertRow(ui->outputTable->rowCount()); // create a new row

        // add a string of each value into each column at the last row in the outputTable
        // the 'new' tablewidget items are NOT memory leaks becuse the tablewiget takes ownership of the item, see: https://stackoverflow.com/questions/21997025/qtablewidget-memory-leak-or-not
        ui->outputTable->setItem(ui->outputTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(time ,'f',2)));
        ui->outputTable->setItem(ui->outputTable->rowCount()-1, 1, new QTableWidgetItem(QString::number(percentOn,'f',2)));
        ui->outputTable->setItem(ui->outputTable->rowCount()-1, 2, new QTableWidgetItem(QString::number(temp,'f',2)));
        ui->outputTable->setItem(ui->outputTable->rowCount()-1, 3, new QTableWidgetItem(QString::number(tempFilt,'f',2)));
        if ( inAutoMode) ui->outputTable->setItem(ui->outputTable->rowCount()-1, 4,new QTableWidgetItem(QString::number(setPoint,'f',2)));
        else ui->outputTable->setItem(ui->outputTable->rowCount()-1, 4,new QTableWidgetItem(""));
        ui->outputTable->setItem(ui->outputTable->rowCount()-1, 5, new QTableWidgetItem(QString::number(fanSpeed,'f',0)));
        if (!ui->outputTable->underMouse())
            ui->outputTable->scrollToBottom();   // scroll to the bottom to ensure the last value is visible

        // add each value into the excel file
        this->xldoc.write(ui->outputTable->rowCount(), 1, time);
        this->xldoc.write(ui->outputTable->rowCount(), 2, percentOn);
        this->xldoc.write(ui->outputTable->rowCount(), 3, temp);
        this->xldoc.write(ui->outputTable->rowCount(), 4, tempFilt);
        if ( inAutoMode ) this->xldoc.write(ui->outputTable->rowCount(), 5, setPoint);
        this->xldoc.saveAs(this->excelFileName); // save the doc in case we crash

        /*
        *  Update the csv file with the last data read from the port
        */
        char file_output_buffer[200]   = "";
        if (inAutoMode) {  // Only write the setpoint if in automatic mode
            snprintf(file_output_buffer, sizeof(file_output_buffer),"%6.2f,%6.2f,%6.2f,%6.2f,%6.2f\n",time, percentOn, temp, tempFilt, setPoint);
        } else {
            snprintf(file_output_buffer, sizeof(file_output_buffer),"%6.2f,%6.2f,%6.2f,%6.2f,\n",time, percentOn, temp, tempFilt);
        }

        QTextStream stream(&this->csvdoc);
        stream << file_output_buffer;   // write the file_output_buffer to the csvdoc file
        stream.flush();  // so it writes immediately


        /*
        *  Show the current values from the port in the current parameters area
        */
        QString ModeString = " "; // holds a string for current mode ex. "Automatic, velocity form, Filtering all terms"
        if (inAutoMode) {
            ui->kcLabel->setText(QString::number(kc, 'f', 3));
            ui->tauiLabel->setText(QString::number(tauI, 'f', 3));
            ui->taudLabel->setText(QString::number(tauD, 'f', 3));;
            ui->taufLabel->setText(QString::number(tauF, 'f', 3));;
            ModeString.append("Automatic\n");
            if ( positionForm  ) ModeString.append("Position Form ");
            else ModeString.append("Velocity Form");
            if ( filterAll ) ModeString.append("\nFiltering all terms");
        } else {
            ModeString.append("Manual");
            // When in manual mode, clear the automatic parameters to avoid confusion/
            ui->kcLabel->clear();
            ui->tauiLabel->clear();
            ui->taudLabel->clear();
            ui->taufLabel->clear();
        }
        ui->modeTextLabel->setText(ModeString);


        /*
        *  Place the latest values in the graph
        */
        ui->plot->graph(3)->addData(time, percentOn);
        ui->plot->graph(1)->addData(time, temp);
        ui->plot->graph(2)->addData(time, tempFilt);
        if( inAutoMode ) ui->plot->graph(0)->addData(time, setPoint);
        ui->plot->replot( QCustomPlot::rpQueuedReplot );
        ui->plot->rescaleAxes(); // should be in a button or somethng

    }
    else{
        qDebug() << "ERROR Failed to deserialize array \n";
        if (!this->validConnection)
            ui->emergencyMessageLabel->setText("Possible incorrect arduino program uploaded.");
    }
}



/**
*   Called when the user clicks the set button.
*   creates a string from the values in the textboxes and sends it to the port.
*/
void MainWindow::on_setButton_clicked()
{
    if (port.L_isConnected()) {

        QString response; // is sent to the port

        /*
        *  Lambda expression used to automate filling the output array from input in the textboxes
        *  Ensures the value inputted in the textBox is within range min and max
        *  returns '_' if the value is no good. When the arduino recieves '_' it wont change the value.
        */
        auto fillArrayAtNextIndex = [&response]( QString name, QLineEdit* textBox, float min = NAN, float max = NAN)
        {
            QString valStr = textBox->text();   // 'valStr' is a string holding what the user inputted in the texbox
            bool isNumerical = false;
            valStr.remove(' ');  // remove any extra spaces
            if(!valStr.isEmpty()) {
                float val = valStr.toFloat(&isNumerical);    // convert to a float value
                if(!isNumerical) {
                    QMessageBox msgBox;
                    msgBox.setText(name + " is not valid" );
                    msgBox.exec();
                    textBox->clear();
                    response.append("_");
                    return;
                } else {
                    // ensure the value is within range
                    if ( max != NAN && val > max ){  // max is NAN if it is unconstrained
                        QMessageBox msgBox;
                        msgBox.setText(name + " of " + QString::number(static_cast<double>(val)) + " is over the maximum of " + QString::number(static_cast<double>(max)) );
                        msgBox.exec();
                        textBox->clear();
                        response.append("_");
                        return;
                    }
                    if  ( min != NAN && val < min ){  // min is NAN if it is unconstrained
                        QMessageBox msgBox;
                        msgBox.setText(name + " of " + QString::number(static_cast<double>(val)) + " is below the minimum of " + QString::number(static_cast<double>(min)) );
                        msgBox.exec();
                        textBox->clear();
                        response.append("_");
                        return;
                    }
                    response.append(valStr);
                    return;
                }
            }
            response.append("_");
            return;
        };

        /*
        *  use the 'fillArrNextIndex' to place the value from the text box
        *  into the array if it is different than the last recieved value,
        *  otherwise it will send an underscore signifying not to change the val
        */
        response = "[";

        bool autoMode = ( ui->tabWidget->currentIndex() ==  1 ); // the first index of the tabwidget is the automatic one

        if (autoMode) {
            response.append( "1," ); // automatic mode
            fillArrayAtNextIndex("Set Point ", ui->setPointTextBox, 10, 60);  response.append(",");
            response.append("_,");  // percent on
            fillArrayAtNextIndex("Kc", ui->kcTextBox); response.append(",");
            fillArrayAtNextIndex("TauI", ui->tauiTextBox, 0); response.append(",");
            fillArrayAtNextIndex("tauD", ui->taudTextBox, 0); response.append(",");
            fillArrayAtNextIndex("TauF", ui->taufTextBox, 0); response.append(",");
            fillArrayAtNextIndex("Fan Speed", ui->A_fanSpeedTextBox, 0, 255); response.append(",");
        } else {
            response.append("0,");  //manual mode
            response.append("_,");  //setpoint
            fillArrayAtNextIndex("Percent Heater On", ui->percentOntTextBox, 0, 100); response.append(",");
            response.append("_,");  // kc
            response.append("_,");  // taui
            response.append("_,");  //taud
            response.append("_,");  //tauf
            fillArrayAtNextIndex("Fan Speed", ui->M_fanSpeedTextBox, 0, 255); response.append(",");
        }

        // these two have a different order in the test program but its okay
        // todo: consider fixing that #p2
        response.append( ui->filterAllCheckBox->isChecked() ? "1," : "0," );
        response.append( ui->posFormCheckBox->isChecked()   ? "1]" : "0]" );

        emit this->response(response);
    }
    else{
        /*
        *  if we arent connect then emit a signal as if the user clicked the first option in the combobox
        *  and therefore a connection will be attempted.
        */
        emit this->on_portComboBox_activated(0);
    }

}



/**
*   Called by the timer ever 250 ms, until the timer is killed.
*   Checks if a connection is active, if no connection is active,
*   search for available ports and open a connection.
*/
void MainWindow::timerEvent(QTimerEvent *event)
{
    if (!port.L_isConnected()) {
        QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();
        // todo: check what hapens if the socket changes. This may be an issue if we change the COM before establishing a connection  #p2
        if (ui->portComboBox->count() != portList.size()) {
            ui->portComboBox->clear();
            for (int i = 0; i < portList.size(); i ++) {
               ui->portComboBox->addItem(portList.at(i).portName());
            }
        }
    } else {
        killTimer(this->timerId); // no reason for the timer anymore
        ui->setButton->setText("Set"); // change connect button to set button
    }

}



/**
*   called when the user pressed on the combobox
*   connects to the port selected.
*/
void MainWindow::on_portComboBox_activated(int index)
{
    if ( !port.L_isConnected() )
    {
        // the port is not conneted yet so we should connect
        QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();
        if(portList.size() != 0)
        {
            port.openPort(portList.at(index));
        }
    }
}



/**
*   Called after new data is recieved from the port to parse the string recieved.
*   fills 'output' of five 'output_size' with the vlues in 'input' string.
*/
bool MainWindow::deserializeArray(const char* const input, unsigned int output_size,  std::vector<float> &output)
{
    /*
    Ensure that the input string has the correct format and number of numbers to be parsed
    */
    const char*  p = input;
    unsigned int num_commas     = 0;
    unsigned int num_brackets   = 0;
    unsigned int num_values     = 0;

    while (*p)
    {
      if (*p == '[') { num_brackets++;
      } else if ( *p == ']' ) {num_brackets++; num_values++;
      } else if ( *p == ',' ) {num_commas++; num_values++;
      } p++;
    }
    if (num_brackets != 2) {
        qDebug() << "(M) Parse error, not valid array\n";
        return false;
    }
    if (num_values != output_size) {
        qDebug() << "(M) Parse error, input size incorrect\n";
        return false;
    }


    char* pEnd;
    p = input + 1;
    for ( unsigned int i = 0; i < output_size; i ++ )
    {

        bool is_a_number = false;
        const char* nc = p; // nc will point to the next comma or the closing bracket
        while(*nc != ',' && *nc != ']' && *nc)
        {
            if ( (int)*nc >= 48 && (int)*nc <= 57 )
                is_a_number = true;
            nc++;
        }
        float num_ = output[i] = strtof(p, &pEnd); // strtof can returns nan when parsing nans,
           // strod returns 0 when parsing nans
        p = pEnd;
        if ( is_a_number || num_ == NAN)
            output[i] = num_;
        while (*p != ',' && *p != ']' && *p)
            p++;
        p++;
   }
   p = input;
   return true;
}

/**
*   Called when a the mode tabs are changed,
*   Will fill the textboxes with the last recorded parameters
*/
void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (!this->validConnection) return; // if we havent connected to the correct port then stop

    bool autoModeTab = ( index == 1 );  // tab index 1 is the automatic tab
    if (autoModeTab){ // changed from manual to automatic

        double temp       = static_cast<double>(inputs[i_temperature]);
        double fanSpeed   = static_cast<double>(inputs[i_fanSpeed]);
        double kc         = static_cast<double>(inputs[i_kc]);
        double tauI       = static_cast<double>(inputs[i_tauI]);
        double tauD       = static_cast<double>(inputs[i_tauD]);
        double tauF       = static_cast<double>(inputs[i_tauF]);

        // Fill the automatic textboxes with the last recorded parameters
        ui->kcTextBox->setText(QString::number(kc, 'f', 3));
        ui->tauiTextBox->setText(QString::number(tauI, 'f', 3));
        ui->taufTextBox->setText(QString::number(tauF, 'f', 3));
        ui->taudTextBox->setText(QString::number(tauD, 'f', 3));
        ui->setPointTextBox->setText(QString::number(temp, 'f', 2));
        ui->A_fanSpeedTextBox->setText(QString::number(fanSpeed, 'f', 1));
    } else {  // changed to the manual tab
        double percentOn  = static_cast<double>(inputs[i_percentOn]);
        double fanSpeed   = static_cast<double>(inputs[i_fanSpeed]);
        // Fill the manual textboxes with the last recorded parameters
        ui->percentOntTextBox->setText(QString::number(percentOn, 'f', 1));
        ui->M_fanSpeedTextBox->setText(QString::number(fanSpeed, 'f', 1));
    }
    emit on_setButton_clicked(); // simulate the user presing the set button so new parameters are sent to the port.
}


/**
*   Called when the user clicks the position form checkbox
*/
void MainWindow::on_posFormCheckBox_stateChanged(int arg1)
{
    emit on_setButton_clicked();    // as if the user just clicked the setbutton (triggers sending parameters to port)
}


/**
*   Called when the user clicks the Filter all terms checkbox
*/
void MainWindow::on_filterAllCheckBox_stateChanged(int arg1)
{
    emit on_setButton_clicked();    // as if the user just clicked the setbutton (triggers sending parameters to port)
}




/**
*    function called when the port is disconnected
*/
bool MainWindow::disonnectedPopUpWindow()
{
    qDebug() << "(disconnected popup window )\n";
    QMessageBox::critical(this,
                          "Error",
                          "Fatal Error, device disconnected.\n"
                          "Close and restart the application to continue.\n",
                          QMessageBox::Ok
                          );
}

/**
 * called when the user presses enter or return
 * // thank you numbat: https://www.qtcentre.org/threads/26313-MainWindow-Button
 */
bool MainWindow::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *ke = static_cast<QKeyEvent *>(event);
        if (ke->key() == Qt::Key_Enter || ke->key() == Qt::Key_Return) {
            emit on_setButton_clicked();
            return true;
        }
    }
    return QMainWindow::event(event);
}
