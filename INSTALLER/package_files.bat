echo off

rm S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\packages\org.qtproject.ifw.example\data\Program\Game.exe
rm S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\packages\org.qtproject.ifw.example\data\Program\Main.exe
rm S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\packages\org.qtproject.ifw.example\data\Program\Test.exe


ping 127.0.0.1 -n 1 > nul

copy S:\ANTH_GD\Development\Process_Control\build-qt_PWCL_main-Desktop_Qt_5_12_6_MinGW_64_bit-Release\release\Main.exe S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\packages\org.qtproject.ifw.example\data\program\
copy S:\ANTH_GD\Development\Process_Control\build-qt_PWCL_test-Desktop_Qt_5_12_6_MinGW_64_bit-Release\release\Test.exe S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\packages\org.qtproject.ifw.example\data\program\
copy S:\ANTH_GD\Development\Process_Control\build-qt_PWCL_game-Desktop_Qt_5_12_6_MinGW_64_bit-Release\release\Game.exe S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\packages\org.qtproject.ifw.example\data\program\


ping 127.0.0.1 -n 2 > nul

echo on
S:\Qt\QtIFW-3.1.1\bin\binarycreator.exe --offline-only -c S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\config\config.xml -p packages S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\PWCL_Installer.exe


ping 127.0.0.1 -n 2 > nul


certutil -hashfile PWCL_Installer.exe > hash.txt


rem echo off

rem rm S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\packages\org.qtproject.ifw.example\data\Program\Game.exe
rem rm S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\packages\org.qtproject.ifw.example\data\Program\Main.exe
rem rm S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\packages\org.qtproject.ifw.example\data\Program\Test.exe


rem ping 127.0.0.1 -n 1 > nul

rem copy S:\ANTH_GD\Development\Process_Control\build-qt_PWCL_main-Desktop_Qt_5_12_6_MinGW_64_bit-Release\release\Main.exe S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\packages\org.qtproject.ifw.example\data\program
rem copy S:\ANTH_GD\Development\Process_Control\build-qt_PWCL_test-Desktop_Qt_5_12_6_MinGW_64_bit-Release\release\Test.exe S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\packages\org.qtproject.ifw.example\data\program
rem copy S:\ANTH_GD\Development\Process_Control\build-qt_PWCL_game-Desktop_Qt_5_12_6_MinGW_64_bit-Release\release\Game.exe S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\packages\org.qtproject.ifw.example\data\program


rem ping 127.0.0.1 -n 2 > nul

rem echo on
rem S:\Qt\QtIFW-3.1.1\bin\binarycreator.exe --offline-only -c S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\config\config.xml -p packages S:\ANTH_GD\Development\Process_Control\RELEASE\INSTALLER\PWCL_Installer.exe


rem ping 127.0.0.1 -n 2 > nul


rem certutil -hashfile PWCL_Installer.exe > hash.txt