# PWCL-main

## GUI for an Arduino based Process Controller

Provides a graphical user interface for changing parameters and logging/graphing data from an Arduino based process controller. 

Uses the Qt API https://www.qt.io/.

Uses the [QXlsx library](https://github.com/j2doll/QXlsx) for logging data to Excel. 

Uses the [ QCustomPlot ](http://www.qcustomplot.com/) library for live graphing. 



## Installation

Go to the [releases page](https://github.com/AnthonyA28/Qt-PWCL-main/releases), download the installer and follow the directions in the installer. 



## Building from Source

### Install Qt

#### What is Qt

Qt is an C++ API for cross-platform software development. It allows you to write programs using it's API that can be compiled for Windows/*nix/Mac. It is free under the following licenses:  LGPL version 3, GPL version 2 and GPL version 3. This program is licensed under **GPL version 3**. Go to https://www.qt.io/download-open-source for more information regarding the license. 

#### Installation

Navigate to https://www.qt.io/download-open-source, scroll down to the bottom and click *Download the Qt Online Installer*. You will need an account to proceed with the installer so make an account if you do not have one.  When the option is available to choose which components, mark the box next to Qt 5.12x Mingw x64

### Download the Source Code

Download the source code or clone the repository from the latest release . Finally open the qt_PWCL_main.pro file with the qt application. Click Run.