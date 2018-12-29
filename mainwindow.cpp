#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCursor>

/*
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->validConnection = false;  // we arent connected yet

    this->timerId = startTimer(250);  // timer is used to repeatedly check for port data until we are connected

    this->inputs = std::vector<float>(this->numInputs); // initialize the input vector to hold the input values from the port

    connect(&port, &PORT::request, this, &MainWindow::showRequest);     // when the port recieves data it will emit PORT::request thus calling MainWindow::showRequest
    connect(this, &MainWindow::response, &port, &PORT::L_processResponse);  // whn the set button is clicked, it will emit MainWindow::response thus calling PORT::L_processResponse

    ui->outputTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);   // have the table resize with the window

    // need to ensure the files are opened in the correct directory
    QString execDir = QCoreApplication::applicationDirPath();
    QDir::setCurrent(execDir);
    QDir newDir = QDir::current();
    newDir.cdUp();  // go one directory up so we dont place our output next to the dependencies
    QDir::setCurrent(newDir.path());

    this->excelFileName = "excelFile.xlsx";
    this->csvFileName   = "data.csv";

    // ensure the excel file does not already exit, if it does we will delete it
    if( QFile::exists(this->excelFileName) )
    {
        QFile oldFile(this->excelFileName);
        oldFile.remove();
    }

    /* give the excel file column headers */
    this->xldoc.write( 1 , 1, "Time");
    this->xldoc.write( 1 , 2, "Percent On");
    this->xldoc.write( 1 , 3, "Temperature");
    this->xldoc.write( 1 , 4, "Filtered Temperature");
    this->xldoc.write( 1 , 5, "Set Point");

    // open the csv file and give it a header
    this->csvdoc.setFileName(this->csvFileName);
    if( this->csvdoc.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Text) )
    {
        QTextStream stream(&this->csvdoc);
        stream << "Time, percent on, Temp, Temp filtered, Set Point\n";
    }
    else
    {
        /* todo: figure out how to handle this #p2 */
        qDebug() << " Failed to open data.csv \n";
    }

    /*
     * setup the plot
     */


    // the set point must have a specil scatterstyle so it doesnt connect the lines
    ui->plot->addGraph();
    ui->plot->graph(0)->setName("Set Point");
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, QColor("orange"), 5));
    ui->plot->graph(0)->setPen(QPen(Qt::white)); // so we dont see the line connecting the dots

    ui->plot->addGraph();
    ui->plot->graph(1)->setName("Temperature");
    ui->plot->graph(1)->setPen(QPen(Qt::green));

    ui->plot->addGraph();
    ui->plot->graph(2)->setName("Temperature Filtered");
    ui->plot->graph(2)->setPen(QPen(Qt::blue));


    ui->plot->addGraph();
    ui->plot->graph(3)->setName("Percent Heater on");
    ui->plot->graph(3)->setPen(QPen(QColor("purple"))); // line color for the first graph
    ui->plot->graph(3)->setValueAxis(ui->plot->yAxis2);
    /*
     * If we want the user to be able to interact with graph
     */
    //    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables); // dont want user interactions

    ui->plot->xAxis2->setVisible(true);  // show x ticks at top
    ui->plot->xAxis2->setVisible(false); // dont show labels at top
    ui->plot->yAxis2->setVisible(true);  // right y axis labels
    ui->plot->yAxis2->setTickLabels(true);  // show y ticks on right side for % on

    ui->plot->yAxis2->setLabel("Heater [%]");
    ui->plot->yAxis->setLabel("Temperature [C]");
    ui->plot->xAxis->setLabel("Time [min]");

    // setup the legend
    ui->plot->legend->setVisible(true);
    ui->plot->legend->setFont(QFont("Helvetica", 8));
    ui->plot->legend->setRowSpacing(-4);  // less space between words
    ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);


}



MainWindow::~MainWindow()
{
    if( this->port.L_isConnected())
    {

        /*
         * Wont add a chart as I cant seem to make it look nice
         */
        // Add a scatterchart and save the excel file
//        int numRows = ui->outputTable->rowCount();
//        Chart *scatterchart = this->xldoc.insertChart(8, 5, QSize(600,400));
//        scatterchart->setChartType(Chart::CT_Scatter);
//        scatterchart->addSeries(CellRange(2,1,numRows, 2));
//        scatterchart->addSeries(CellRange(3,1,numRows, 3));
//        scatterchart->addSeries(CellRange(4,1,numRows, 4));
//        scatterchart->setAxisTitle(Chart::Bottom, "Time" );
//        scatterchart->setAxisTitle(Chart::Left, "Temperatures" );
//        this->xldoc.saveAs(this->excelFileName);



        // ensure a backupfile directory exists, create one if it doesnt
        QDir backupDir("backupFiles");
        if( !backupDir.exists() )
             backupDir.mkpath(".");
        QDir::setCurrent("backupFiles");

        QDateTime currentTime(QDateTime::currentDateTime());
        QString dateStr = currentTime.toString("d-MMM--h-m-A");  // create a date title for the backup file
        dateStr.append(".csv"); // the 's' cant be used when formatting the time string
        this->csvdoc.copy(dateStr); // save a backup file of the csv file
    }
    this->csvdoc.close();

        delete ui;
}

void MainWindow::showRequest(const QString &req)
{
    if(this->deserializeArray(req.toStdString().c_str(), this->numInputs, this->inputs))
    {

        this->validConnection = true;  // we can parse the string therfore it must be the correct arduino file uploaded

        bool inAutoMode = (inputs[i_mode]);  // true if we are in automatic mode

        ui->outputTable->insertRow(ui->outputTable->rowCount()); // create a new row

        /* add a string of each value into each column at the last row in the outputTable */
        ui->outputTable->setItem(ui->outputTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(inputs[i_time])));
        ui->outputTable->setItem(ui->outputTable->rowCount()-1, 1, new QTableWidgetItem(QString::number(inputs[i_percentOn])));
        ui->outputTable->setItem(ui->outputTable->rowCount()-1, 2, new QTableWidgetItem(QString::number(inputs[i_temperature])));
        ui->outputTable->setItem(ui->outputTable->rowCount()-1, 3, new QTableWidgetItem(QString::number(inputs[i_tempFiltered])));
        if ( inAutoMode) ui->outputTable->setItem(ui->outputTable->rowCount()-1, 4,new QTableWidgetItem(QString::number(inputs[i_setPoint])));
        else ui->outputTable->setItem(ui->outputTable->rowCount()-1, 4,new QTableWidgetItem(""));
        ui->outputTable->setItem(ui->outputTable->rowCount()-1, 5, new QTableWidgetItem(QString::number(inputs[i_fanSpeed])));
        ui->outputTable->scrollToBottom();   // scroll to the bottom to ensure the last value is visible

        /* add each value into the excel file  */
        this->xldoc.write(ui->outputTable->rowCount(), 1, inputs[i_time]);
        this->xldoc.write(ui->outputTable->rowCount(), 2, inputs[i_percentOn]);
        this->xldoc.write(ui->outputTable->rowCount(), 3, inputs[i_temperature]);
        this->xldoc.write(ui->outputTable->rowCount(), 4, inputs[i_tempFiltered]);
        if ( inAutoMode ) this->xldoc.write(ui->outputTable->rowCount(), 5, inputs[i_setPoint]);
        this->xldoc.saveAs(this->excelFileName); // save the doc in case we crash

        // for writing to csv file
        char file_output_buffer[200]   = ""; // create a string to be sent to the file
        if( inAutoMode )      // if in automatic mode then write the set  point
        {
            snprintf(file_output_buffer, sizeof(file_output_buffer),"%6.2f,%6.2f,%6.2f,%6.2f,%6.2f\n",
                inputs[i_time], inputs[i_percentOn], inputs[i_temperature], inputs[i_tempFiltered], inputs[i_setPoint]);
        }
        else  // if in manual mode then write the set point
        {
            snprintf(file_output_buffer, sizeof(file_output_buffer),"%6.2f,%6.2f,%6.2f,%6.2f,\n",
                inputs[i_time], inputs[i_percentOn], inputs[i_temperature], inputs[i_tempFiltered]);
        }

        QTextStream stream(&this->csvdoc);
        stream << file_output_buffer;
        stream.flush();


        // Show the current values from the port in the current parameters area
        ui->kcLabel->setNum(inputs[i_kc]);
        ui->tauiLabel->setNum(inputs[i_tauI]);
        ui->taudLabel->setNum(inputs[i_tauD]);
        ui->taufLabel->setNum(inputs[i_tauF]);
        QString ModeString = " ";
        if ( inputs[i_mode])
        {
            ModeString.append("Automatic\n");
            if ( inputs[i_positionForm]  ) ModeString.append("Position Form ");
            else ModeString.append("Velocity Form");
            if ( inputs[i_filterAll] ) ModeString.append("\nFiltering all terms");
        }
        else ModeString.append("Manual");
        ui->modeTextLabel->setText(ModeString);


        /*
         * update the graph
         *
         */
        ui->plot->graph(3)->addData(inputs[i_time], inputs[i_percentOn]);
        ui->plot->graph(1)->addData(inputs[i_time], inputs[i_temperature]);
        ui->plot->graph(2)->addData(inputs[i_time], inputs[i_tempFiltered]);
        if( inAutoMode ) ui->plot->graph(0)->addData(inputs[i_time], inputs[i_setPoint]);
        ui->plot->replot( QCustomPlot::rpQueuedReplot );
        ui->plot->rescaleAxes(); // should be in a button or somethng

    }
    else
        qDebug() << "ERROR Failed to deserialize array \n";
}



void MainWindow::on_setButton_clicked()
{
    // send data to port now
    if ( port.L_isConnected() )
    {   // we are connected so we can send the data in the textbox

        QString response;

        /*
         * Lambda expression used to automate filling the output array from input in the textboxes
         */
        auto fillArrayAtNextIndex = [&response]
                (double oldVal, QString name, QLineEdit* textBox, double min = NAN, double max = NAN)
        {
            QString valStr = textBox->text();
            bool isNumerical = false;
            valStr.remove(' ');
            if( !valStr.isEmpty() )
            {
                float val = valStr.toFloat(&isNumerical);    // convert to a float value
                if( !isNumerical )
                {
                    QMessageBox msgBox;
                    msgBox.setText(name + " is not valid" );
                    msgBox.exec();
                    textBox->clear();
                    response.append("_");
                    return;
                }
                else{
                    // ensure the value is with range
                    if ( max != NAN && val > max )
                    {
                        QMessageBox msgBox;
                        msgBox.setText(name + " of " + QString::number(val) + " is over the maximum of " + QString::number(max) );
                        msgBox.exec();
                        textBox->clear();
                        response.append("_");
                        return;
                    }
                    if  ( min != NAN && val < min )
                    {
                        QMessageBox msgBox;
                        msgBox.setText(name + " of " + QString::number(val) + " is below the minimum of " + QString::number(min) );
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

            /* use the fillArrNextIndex to place the value from the text box
               into the array if it is different than the last recieved value,
               otherwise it will send an underscore signifying not to change the val
            */

        response = "[";

        bool autoMode = ( ui->tabWidget->currentIndex() ==  1 );

        if( autoMode )
        {
            response.append( "1," ); // automatic mode
            fillArrayAtNextIndex(inputs[i_setPoint], "Set Point ", ui->setPointTextBox, 10, 60);  response.append(",");
            response.append("_,");  // percent on
            fillArrayAtNextIndex(inputs[i_kc],   "Kc", ui->kcTextBox); response.append(",");
            fillArrayAtNextIndex(inputs[i_tauI], "TauI", ui->tauiTextBox, 0); response.append(",");
            fillArrayAtNextIndex(inputs[i_tauD], "tauD", ui->taudTextBox, 0); response.append(",");
            fillArrayAtNextIndex(inputs[i_tauF], "TauF", ui->taufTextBox, 0); response.append(",");
            fillArrayAtNextIndex(inputs[i_fanSpeed], "Fan Speed", ui->A_fanSpeedTextBox, 0, 255); response.append(",");
        }
        else
        {
            response.append("0,");  //manual mode
            response.append("_,");  //setpoint
            fillArrayAtNextIndex(inputs[i_percentOn], "Percent Heater On", ui->percentOntTextBox, 0, 100); response.append(",");
            response.append("_,");  // kc
            response.append("_,");  // taui
            response.append("_,");  //taud
            response.append("_,");  //tauf
            fillArrayAtNextIndex(inputs[i_fanSpeed], "Fan Speed", ui->M_fanSpeedTextBox); response.append(",");
        }

        response.append( ui->filterAllCheckBox->isChecked() ? "1," : "0," );
        response.append( ui->posFormCheckBox->isChecked()   ? "1]" : "0]" );

        emit this->response(response);
    }
    else
    {  // if we arent connect then emit a signal as if the user clicked the first option in the combobox
        emit this->on_portComboBox_activated(0);
    }

}


void MainWindow::timerEvent(QTimerEvent *event)
{
    /**
      Check if any ports are available and if the port is connected, if its not, then attempt to connect
     */

    if( !port.L_isConnected() )
    {
        QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();
        if(  ui->portComboBox->count() != portList.size() )
        {
            ui->portComboBox->clear();
            for(int i = 0; i < portList.size(); i ++)
            {
               ui->portComboBox->addItem(portList.at(i).portName());
            }
        }
    }
    else
    {
        killTimer(this->timerId); // no reason for the timer anymore
        if( ui->setButton->text() != "Set")   // change connect button to set button
        {
            ui->setButton->setText("Set");
//            ui->setButton->setEnabled(false);
//            ui->portComboBox->setEnabled(false);
        }
    }

}


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
        if ( is_a_number )
        {
           output[i] = strtof(p, &pEnd); // strtof can returns nan when parsing nans,
           // strod returns 0 when parsing nans
           p = pEnd;
        }
        while (*p != ',' && *p != ']' && *p)
            p++;
        p++;
    }
    p = input;
    return true;

}


void MainWindow::on_posFormCheckBox_stateChanged(int arg1)
{
    emit on_setButton_clicked();
}

void MainWindow::on_filterAllCheckBox_stateChanged(int arg1)
{
    emit on_setButton_clicked();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (!this->validConnection) return; // if we havent connected to the orrect port then stop

    bool autoModeTab = ( index == 1 ); // we are in the automatic tab
    if( autoModeTab )
    {
        ui->kcTextBox->setText(QString::number(inputs[i_kc]));
        ui->tauiTextBox->setText(QString::number(inputs[i_tauI]));
        ui->taufTextBox->setText(QString::number(inputs[i_tauF]));
        ui->taudTextBox->setText(QString::number(inputs[i_tauD]));
        ui->setPointTextBox->setText(QString::number(inputs[i_temperature]));
        ui->A_fanSpeedTextBox->setText(QString::number(inputs[i_fanSpeed]));
    }
    else {
        ui->percentOntTextBox->setText(QString::number(inputs[i_percentOn]));
        ui->M_fanSpeedTextBox->setText(QString::number(inputs[i_fanSpeed]));
    }

    emit on_setButton_clicked();
}
