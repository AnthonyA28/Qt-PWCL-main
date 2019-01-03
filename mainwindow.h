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


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;

#include "port.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void showRequest(const QString & req);
    bool disonnectedPopUpWindow();
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void response(const QString &response);

private slots:

    void on_portComboBox_activated(int index);
    void on_setButton_clicked();
    void on_posFormCheckBox_stateChanged(int arg1);
    void on_filterAllCheckBox_stateChanged(int arg1);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    bool deserializeArray(const char* const input, unsigned int output_size, std::vector<float>& output);
    int timerId; // for setting up and destroying a timer used to frquently check if port is connected until connected
    void timerEvent(QTimerEvent *event);
    PORT port;
    bool validConnection;

    QString csvFileName;
    QString excelFileName;

    QXlsx::Document xldoc;
    QFile csvdoc;

    /*  Some values shared between the arduino code and the this program */
    // specific for the game
    const unsigned int i_autoMode      = 0;       // for input & output
    const unsigned int i_setPoint      = 1;       // for input & output
    const unsigned int i_percentOn     = 2;       // for input & output
    const unsigned int i_kc            = 3;       // for input & output
    const unsigned int i_tauI          = 4;       // for input & output
    const unsigned int i_tauD          = 5;       // for input & output
    const unsigned int i_tauF          = 6;       // for input & output
    const unsigned int i_fanSpeed      = 7;       // for input & output
    const unsigned int i_filterAll     = 8;       // for input & output
    const unsigned int i_positionForm  = 9;       // for input & output
    const unsigned int i_temperature   = 10;      // for input
    const unsigned int i_tempFiltered  = 11;      // for input
    const unsigned int i_time          = 12;      // for input
    const unsigned int numInputs       = 13;

    std::vector<float> inputs;
};

#endif // MAINWINDOW_H
