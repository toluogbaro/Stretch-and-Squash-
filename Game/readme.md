# Introduction

This is the **ROOT** folder for the unreal game project.

_NOTE - Unreal has blur enabled by default, disable this in project settings if you don't want blur._



# Adding UE5 Game Project

1. Open unreal, select a template, and create the project template anywhere.
2. Open the **ROOT** folder of the UE5 project you just created and copy `yourgame.uproject`, `Content`, `Config`, and `Source` into this folder.
3. If your `yourgame.uproject` file and `Content`, `Config`, `Source` folders are in the same directory as the repositories `.gitignore` file, then your setup is correct.

Once you've completed the above steps you're ready to open the project and start working.



# Opening The Project: For Programmers

If you're a programmer and plan on doing work in C++ you should right click the `yourgame.uproject` file and select the `Generate Visual Studio project files` option. When this is complete double click the `yourgame.sln` file and run the game from Visual Studio by clicking `Local Windows Debugger`. Whenever you code in C++ you should close UE5 and recompile it from VS.

If you are not doing anything in C++, then you can open the project straight from double clicking `yourgame.uproject`. Make sure you click yes on the prompt asking to compile. UE5 will take awhile to open because it's compiling C++ binaries in the background.

If UE5 is bing weird delete all the cache files/folders & generated files/folders, then lauch it from Visual Studio so it's forced to compile everything correctly and you will catch any compile-time bugs if anything is wrong.