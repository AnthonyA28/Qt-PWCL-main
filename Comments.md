# Explanation of each file

To compile the project, use Qt version 5.12.

| File Name or Directory | Explanation                                                  |
| ---------------------- | :----------------------------------------------------------- |
| /PWCL_main             | The arduino code.                                            |
| /header                | The header files used by the QXlsx library which is the library that allows writing to excel files. |
| /Source                | The source files used by the QXlsx library.                  |
| .gitignore             | A list of file types my version control system ignores. This file has no effect on the actual program. |
| about.cpp              | The source file for the about window (opened "About" is clicked). |
| about.h                | The header file for the about window.                        |
| about.ui               | The configuration for the about window.                      |
| alarm.wav              | The sound that is played when an overheat occurs.            |
| gator_icon.ico          | A picture of the gator engineering icon. Used by the program for the desktop shortcut and the taskbar icon. |
| License.txt            | A copy of the GPL v3 license. Which all the files here are licensed under. |
| main.cpp               | The very first lines of code executed.                       |
| mainwindow.cpp         | The source code for the mainwindow - specifies what happens when buttons are clicked and such. |
| mainwindow.h           | The header file for the mainwindow - where the variables are declared. |
| mainwindow.ui          | The configuration file for mainwindow. Should only be opened in Qt_Creator |
| port.cpp               | The source code for the port class.                          |
| port.h                 | The header file for the port class.                          |
| qcustomplot.cpp        | The source file for the plotter class.                       |
| qcustomplot.h          | The header file for the plotter class.                       |
| qt_main_resource.rc    | The resrouce file for the project, places the resources - such as the garor_icon.ico. In the final release. |
| qt_PWCL_main.pro       | The project file for qt_PWCL_main - keeps track of which files are in the project. |
| QXlsx.pri              | The subproject file for QXlsx library.                       |
| QXlsx.pro              | The project file for QXlsx library.                          |


# List of Important Files

As is apparent from the list above. Many of the file are either used either used by the library, or have nothing to do with the functioning of the program. Just to emphasize what is important, here is a list of important file. The primary functionality of the program is within these files. Listed in order of importance.

* qt_PWCL_main.pro

* main.cpp

* mainwindow.ui

* mainwindow.h

* mainwindow.cpp

* port.h

* port.cpp

# Commenting Format Explained

Each file will start with the license at the top of the file, then there will be a general comment to explain the file .

A general comment to explain the purpose of a file will be in the following format:
    /***** filename
                Information for the file filename
    *****/

Each function will have a comment explaining it in the following format:
    /**
    *   An example function used to demonstrate comments.
    */
​	void example(){ return; }

The remainder of the comments will be in the following format:
    /* Explaining that something that occurs in the lines below */
​	// Or it may look like this.
​    something_happening();

In the Arduino Code, I will prefix my comments with AJA
    /**AJA example comment*/


