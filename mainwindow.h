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
#include <QMediaPlayer>

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;

#include "port.h"
#include "com.h"

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

    void on_actionExport_Excel_File_triggered();

private:
    COM com;


    Ui::MainWindow *ui;

    int timerId; // for setting up and destroying a timer used to frquently check if port is connected until connected
    void timerEvent(QTimerEvent *event);
    PORT port;
    bool validConnection;

    QString csvFileName;
    QString excelFileName;
    QXlsx::Document xldoc;
    QFile csvdoc;
    QMediaPlayer* player;

    bool deserializeArray(const char* const input, unsigned int output_size, std::vector<float>& output);
    float Tmax = 60; // maximum safe temperature

    float nominalPercentOn = 0;

protected:
    bool event(QEvent *event);

};

#endif // MAINWINDOW_H
