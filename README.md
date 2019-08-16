# PWCL-main

## GUI for an arduino based Process Controller

Provides a graphical user interface for changing parameters and logging/graphing data from an Arduino based process controller. 

Uses the [QXlsx library](https://github.com/j2doll/QXlsx) for logging data to Excel. 

Uses the [ QCustomPlot ](http://www.qcustomplot.com/) library for live graphing. 



## Installation
  Go to releases and download the [latest release] (https://github.com/AnthonyA28/Qt-PWCL-main/releases)

## Building from source 

   Qt version 4 or greator is required.

  * Clone the repository. 
  * Open the *qt_PWCL_main.pro* file with Qt creator. 

## todo:
* Feed forward: 
	1) manual, Automatic FB, Automatic FB FF
	Parameters (3) :
 		- K_ff
 		- T_lead
 		- T_lag

* Evidently the export as Excel File option does not work on Ubuntu builds. 
