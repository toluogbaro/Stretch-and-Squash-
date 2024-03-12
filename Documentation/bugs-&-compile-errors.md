# Visual Studio/C++ & Unreal Engine Issues

### I'm Getting Compiler Errors When Run Unreal Engine for Visual Studio

If you are trying to run UE5 from Visual Studio, then close any other UE5 executable windows you have open. If Unreal is already running when you launch it from Visual Studio then it will sometimes prevent Visual Studio from being able to correctly compile your C++ files, which results in a compiler error.

To fix this close all open instances of Unreal Engine. Once you've done that everything will be fine and you should be able to run Unreal from Visual Studio.



### I'm Getting an Error with the Build.bat in the Visual Studio Output Console

This happens when certain executables are already running in the background and haven't shutdown when they're meant to. To fix this open task manager and close `HUB for UE5 runtime traces...` and close every instance of `Runtime Broker` you can find.

Once you've done this, Visual Studio will work again and you can compile code.

`Runtime Broker` controls file permissions on windows and `HUB for UE5 runtime traces...` can sometimes have a file or folder open. From what I know this is a Games Academy specific issue mostly - my guess is that it probably has something to do with the configuration of the University computers. I've not really seen this issue for people who're not using Falmouth Uni/GA computers.



### Stucture's are Unknown when Packaging

If you get an error in the packaging log that looks like this:
```log
PackagingResults: Error: FStructProperty::Serialize Loading: Property 'StructProperty /Game/Game/VisualNovel/BP_VisualNovelManager.BP_VisualNovelManager_C:VisualNovelData.VisualNovelData'. Unknown structure.
PackagingResults: Error: FStructProperty::Serialize Loading: Property 'StructProperty /Game/Game/VisualNovel/BP_VisualNovelManager.BP_VisualNovelManager_C:Dialogue'. Unknown structure.
PackagingResults: Error: FStructProperty::Serialize Loading: Property 'StructProperty /Game/Game/VisualNovel/BP_VisualNovelManager.BP_VisualNovelManager_C:ExecuteUbergraph_BP_VisualNovelManager:CallFunc_Array_Get_Item'. Unknown structure.
PackagingResults: Error: Unknown Cook Failure
```

The the way to fix this is to rename the blueprint structure file(s) it's complaining about. Any name will do. Save all the file(s) that need saving including levels and blueprints that you haven't changed manually.

This will force unreal to update all the references to the blueprint stucture file, and fix the issue.



# Fixing UE5 Setup

### dotnet is not recognized as an internal or external command

If you get an error similar to this one when generating visual studio project files or opening the project for the first time, it's because `.NET 6` is not installed or its environment path is not set.

To fix this locate `C:\program files\dotnet`, and delete the `dotnet` folder if it exists. If it doesn't exist, then don't do anything.

Next download the .NET 6 SDK ([.NET 6 download here](https://dotnet.microsoft.com/en-us/download/dotnet/6.0)) and install it. _(do not download `ASP.NET Core Runtime`, `.NET Desktop Runtime`, `.NET Runtime`, or any other SDK - just the plain `.NET 6` SDK that has everything included)_

This will fix the dotnet error.