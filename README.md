# PWCL-main

## GUI for an arduino based Process Controller

Provides a graphical user interface for changing parameters and logging/graphing data from an Arduino based process controller. 

Uses the [QXlsx library](https://github.com/j2doll/QXlsx) for logging data to Excel. 

Uses the [ QCustomPlot ](http://www.qcustomplot.com/) library for live graphing. 



## Installation
  * Download the latest release from the releases tab. 
  * unzip the files into any directory you prefer. 
  * Do **NOT** move the executables (main.exe, test.exe, game.exe) outside of the folder they are in by default. They must be in the same folder as the *.dll* files.  
  * (optional but recommended) create shortcuts to each of the executables by right clicking on each and clicking create shortcut.
  * Now double click on one of the executables, or a shortcut to it, to start the program. 

## Building from source 

   Qt version 5 or greator is required. Tested in Qt 5.9.2.

  * Clone the repository. 
  * Open the *qt_PWCL_main.pro* file with Qt creator. 


## todo: 
 * reduce number of significant figures for score. 
 * add a beep when overheat. 
 * make dots bigger for setpoint. 
* game.exe, you have earned rating of professional crash test dummy .  
* filt temp not temp filt 
