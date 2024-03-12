# Introduction

This is a Unreal Engine template for 5.1 or greater.

The template was made by **Rian Rutherford** _(rr262471)_. To make the template, I used the pervious UE4 template as a starting point.

`Documentation` is an optional folder, it can be deleted if you don't want it.

If you want, you can rename the `Game` folder to something else. What is important is to make sure whatever the folder name, it has the original `.gitignore` and `.gitattributes` file inside.

If you are using Unreal Engine for the first time, or a first time UE5 C++ programmer, you need to read the [Project Root Readme](Game/readme.md). It has information for setting up your Unreal Engine 5 project with the template, and opening the project as a programmer for coding in C++.



# Table of Contents

1. [Project Root Readme](Game/readme.md)
2. [Learning Resources](Documentation/learning-resources.md)
    1. [Beginners Guide to Unreal](Documentation/learning-resources.md#beginners-guide-to-unreal)
    2. [Getting Started with Unreal C++](Documentation/learning-resources.md#getting-started-with-unreal-c)
    3. [Multiplayer in Unreal](Documentation/learning-resources.md#multiplayer-in-unreal)
3. [Bugs & Compile Errors](Documentation/bugs-&-compile-errors.md)



# WARNING!!!

Do not put in development or completed project assets in this repository. When you import assets into unreal they're taken into unreal and changed into `.uasset` files. Because of this it's wasteful to put the original development assets in the game repository. Doing so bloats the project and increases cloning times of the project for everyone.

Instead you should have another repo that uses the [art-lfs-repo](https://github.falmouth.ac.uk/Games-Academy/art-lfs-repo) template. This is where you put your development assets like your models and textures while working on them, including your completed ones. Then when you're done, you import them into Unreal Engine (and UE5 will store the files internally in its own format).



# UE5 Stucture & Organisation

1. [UE5 Directory Structure](https://docs.unrealengine.com/5.1/en-US/unreal-engine-directory-structure/)
2. [UE5 Asset Naming Conventions](https://docs.unrealengine.com/5.1/en-US/recommended-asset-naming-conventions-in-unreal-engine-projects/)



# Other Useful Links

1. [UE5 Command-Line Arguments](https://docs.unrealengine.com/latest/en-US/command-line-arguments-in-unreal-engine/)
2. [C++ UPROPERTY Specifiers](https://docs.unrealengine.com/latest/en-US/unreal-engine-uproperties/)
3. [C++ UFUNCTION Specifiers](https://docs.unrealengine.com/latest/en-US/ufunctions-in-unreal-engine/)
4. [C++ UCLASS Specifiers](https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/GameplayArchitecture/Classes/)
5. [C++ API Reference](https://docs.unrealengine.com/latest/en-US/API/)