#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtDebug>
#include <QtSerialPort/QSerialPortInfo>
#include <QTextCursor>
#include <QTableWidget>
#include <vector>
#include <QAbstractItemView>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QMessageBox>
#include <QtMath>
#include <QLineEdit>

#include<tuple>

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
    const unsigned int i_mode          = 0;       // for input & output
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
