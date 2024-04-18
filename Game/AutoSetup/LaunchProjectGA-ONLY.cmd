echo off

rem Unzipping plugins folder
"C:\Program Files\7-Zip\7z.exe" x Plugins.zip

rem Getting parent folder
FOR %%A IN ("%~dp0.") DO SET ParentDIR=%%~dpA

xcopy /s /y Plugins %ParentDIR%\Plugins

@RD /S /Q Plugins

call DontTouch.cmd

