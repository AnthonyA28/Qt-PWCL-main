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



/***** main.cpp

    *   sets up the log file which outputs debug information during runtime.
    *   Initializes the mainwindow.

    int main(int argc, char *argv[]) is the entry point of the entire program.

*****/

#include "mainwindow.h"
#include <QApplication>

bool release = false;

FILE *pFile= fopen("log", "w");

/**
*   A function used to write 'msg' to pFile.
*/
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED( type ) Q_UNUSED( context ) // to ignore the unused parameter warning

    QByteArray localMsg = msg.toLocal8Bit();
    fprintf(pFile, "%s", localMsg.constData());
    fflush(pFile);

}

/**
*   Entry point of the program.
*/
int main(int argc, char *argv[])
{
        /* Install the message hander to use the function myMessageOutput() */
    /* This redirects all messages to qDebug() to myMessageOutput() */
    if(release) qInstallMessageHandler(myMessageOutput); // Install the handler

    /* Tell the program it can scale the Dpi. */
    /* This prevents the program from looking blurry and scaling weird */
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    /* Initialize the application and mainwindow and show it to the user. */
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /* Close the pFile, since we dont need it anymore. */
    if(release) fclose (pFile);

    return a.exec();

}
