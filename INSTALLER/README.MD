# Packaging the Application

## Organizing the Package

* Ensure that the Arduino programs are in ./org.qtproject.ifw.example/Arduino_code

* Ensure that the desktop application and the dependencies is in ./org.qtproject.ifw.example/Program
  * The dependencies are already in there so you should be able to just replace the .exe files and it should work. You can test by trying to run the .exe files from that directory. 

Once all that is complete, you can run the binary creator from your command line. 



## Running the Binary Creator 

This is a Qt application that creates an installer for the application. It is run from the command line. 

This is the command that works for me but you will have to adjust your directories accordingly:

C:\Qt\Tools\QtInstallerFramework\3.2\bin\binarycreator.exe --offline-only -c C:\INSTALLER\config\config.xml -p D:\INSTALLER\packages C:\INSTALLER\PWCL_Installer.exe

**Explanation:** 
C:\Qt\Tools\QtInstallerFramework\3.2\bin\binarycreator.exe : Call the binary creator application. 
--offline-only: produce an installer that conatins the application instead of searching for a url to install from. 
-c C:\INSTALLER\config\config.xml: set the configuration file 
-p D:\INSTALLER\packages: set the package directory
C:\INSTALLER\PWCL_Installer.exe: Set the installer name to PWCL_Installer.exe


If you do not have the QtInstallerFramework directory, open the Qt Maintanence tool and install it. Go to the 'Add or remove components' then find 'Qt Installer Framework' and install it. 

