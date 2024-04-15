echo off

rem Getting parent folder
FOR %%A IN ("%~dp0.") DO SET ParentDIR=%%~dpA

del %ParentDIR%\*.sln
rmdir /s /q %ParentDIR%\.vs
rmdir /s /q %ParentDIR%\Binaries
rmdir /s /q %ParentDIR%\Intermediate
rem rmdir /s /q %ParentDIR%\Saved
rmdir /s /q %ParentDIR%\DerivedDataCache


set UVS="C:\Program Files (x86)\Epic Games\Launcher\Engine\Binaries\Win64\UnrealVersionSelector.exe"
set UBT="C:\Program Files\Epic Games\UE_5.1\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe"

set FullPath="%ParentDIR%\YarnTheoryGame"

%UVS% /projectfiles %FullPath%.uproject

%UBT% Development Win64 -Project=%FullPath%.uproject -TargetType=Editor -Progress -NoEngineChanges -NoHotReloadFromIDE

%FullPath%.uproject

pause