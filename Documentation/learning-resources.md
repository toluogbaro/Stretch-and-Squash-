# All Materials are Good

Unreal Engine 4 and Unreal Engine 5 are very similar. Most of the features are still the same and a lot of the UE4 tutorials are still relevant in UE5. You only want a UE5 tutorial if it's a new feature that was intoduced in UE5 or if it was completely reworked.

This especially true for C++ and Blueprints, almost nothing has changed between versions for programmers.

These are the main differences between UE4 and UE5:
1. The UI was updated, but a lot of stuff is still in the same place as before.
2. There was internal engine refactoring which doesn't affect you.
3. Addition of Lumen - A new lighting system.
4. Addition of Nanite - A new system for rendering high poly static meshes.
5. Addition of Enhanced Input Subsystem - This is replacing the old input system, but the old system is still available for now so you can still follow old tutorials fine.

UE4 learning materials are still relevant, and sometimes the only thing available for older subjects that haven't changed for years.

_You can also find a lot of official learning materials made by Epic Games on their community website: [https://dev.epicgames.com/community/unreal-engine/learning](https://dev.epicgames.com/community/unreal-engine/learning)_



# Beginners Guide to Unreal

### Learning List
1. [Your First Hour in Unreal Engine 5](https://dev.epicgames.com/community/learning/courses/ZpX/your-first-hour-in-unreal-engine-5-0/RPwK/your-first-hour-in-unreal-engine-5-0-overview)
2. [UE5 Asset Naming Conventions](https://docs.unrealengine.com/5.1/en-US/recommended-asset-naming-conventions-in-unreal-engine-projects/) - Most people working in Unreal use this naming convention. It's something you should use too when working in Unreal Engine. 
3. [50 Unreal Engine 5 Tips](https://www.youtube.com/watch?v=iayPiX8tBmQ) - Highly recommend everyone watches this, it also has a list of additional YouTubers that make good Unreal Engine content.
4. [Unreal Slackers](https://unrealslackers.org/) - The biggest Unreal Engine Discord community. They're officially listed on [unrealengine.com](https://unrealengine.com) in the community tab at the top.
5. [Unreal Engine Build a Detective's Office Game Environment](https://dev.epicgames.com/community/learning/courses/WK/unreal-engine-build-a-detective-s-office-game-environment/YOr/unreal-engine-introduction-to-the-detective-s-office-course)
6. [Welcome to Game Development](https://dev.epicgames.com/community/learning/paths/OR/welcome-to-game-development) - Collection of resources by Epic Games.
7. [Mathew Wadstein](https://www.youtube.com/@MathewWadsteinTutorials) - This guy has videos for most blueprint nodes. Type: `unreal wtf <nodenamehere>` into youtube and he will usually have a video on the node.
8. [Introduction to AI with Blueprints](https://dev.epicgames.com/community/learning/courses/67R/unreal-engine-introduction-to-ai-with-blueprints/mX27/introduction-to-ai-with-blueprints)


### Version Control

Be careful when working on files in Unreal Engine. `.ini` config files and code files can have their changes merged. All other files in Unreal, typically with the file extentsion `.umap` or `.uasset`, cannot be merged like text files can be. These are binary files, so you can't merge the work from 2 different people on the same file. To my knowlegde almost everything you create inside the Unreal Engine Editor will be a binary file, so be careful.

Your teams need to maintain good communication to ensure you don't loose work from two people working on the same asset at the same time, and then having to trash someones work because of the merge conflict.



# Art in Unreal

1. [Becoming an Environment Artist in Unreal Engine](https://dev.epicgames.com/community/learning/courses/Gm/becoming-an-environment-artist-in-unreal-engine/VP2/introduction-to-becoming-an-environment-artist-in-unreal-engine)
2. [Unreal Engine Editor Fundamentals - Materials](https://dev.epicgames.com/community/learning/courses/nDz/unreal-engine-unreal-editor-fundamentals-materials/RWR/introduction-to-physically-based-rendering)
3. [Unreal Engine Lighting Essential Concepts and Effects](https://dev.epicgames.com/community/learning/courses/Xwp/unreal-engine-lighting-essential-concepts-and-effects/0ax/lighting-essential-concepts-and-effects-introduction)



# Getting Started with Unreal C++

### C++ Programming Course - Beginner to Advanced

[C++ Programming Course - Beginner to Advanced](https://www.youtube.com/watch?v=8jLOx1hD3_o) - This is a 31 hour video going over all the programming and C++ concepts. Use the `MSVC` compiler, don't use the other options they show like `Mingw` or `Clang LLVM`.


### Unreal Engine Modules

If you want to use C++ in your projects you will need to be familiar with adding modules to your project. Unfortunately this isn't taught very well despite how simple it is. Not knowing how to add modules will cause linker errors at compile-time preventing the project from compiling.

I can't find any simple learning materials. For anyone getting started learning Unreal C++ reach out to me _(`rr262471`/`Rian Rutherford`)_ while I'm at the GA and I might be able to give you a quick 5 minute crash course while I'm there if I have the time.

1. [Build.cs & Target.cs](https://unrealcommunity.wiki/build.cs-hv582z08)
2. [Improving Code Structure with Unreal Engine's C++ Modules](https://dev.epicgames.com/community/learning/tutorials/xJ/improving-code-structure-with-unreal-engine-s-c-modules) - This goes way too indepth and you don't need to know 90% of the content in the video, but it's a good watch if you want to learn how to make you own Unreal Engine modules and what they are.


### Opening The Project: For Programmers

If you're a programmer and plan on doing work in C++ you should right click the `<yourgame>.uproject` file and select the `Generate Visual Studio project files` option. When this is complete double click the `<yourgame>.sln` file and run the game from Visual Studio by clicking `Local Windows Debugger`. Whenever you code in C++ you should close UE5 and recompile it from VS.

If you are not doing anything in C++, then you can open the project straight from double clicking `<yourgame>.uproject`. Make sure you click yes on the prompt asking to compile. UE5 will take awhile to open because it's compiling C++ binaries in the background.

If UE5 is being weird, delete all the cache files/folders & generated files/folders, then reopen the project from Visual Studio so it's forced to compile everything correctly and you will catch any compiler errors if anything is wrong.


### I don't know how to setup VS2022 for Unreal Engine 5

Follow this guide: [Setting Up Visual Studio Environment for C++](https://docs.unrealengine.com/5.1/en-US/setting-up-visual-studio-development-environment-for-cplusplus-projects-in-unreal-engine/)


### Garbage Collection

[Garbage Collection](https://unrealcommunity.wiki/garbage-collection-36d1da) When using pointers on class member variables, that contains a type inheriting from `UObject`, you need to have a `UPROPERTY` macro attached to the variable. This is because `UPROPERTY` helps with tracking memory for the garbage collector. 



# Multiplayer in Unreal

_Note - You can do multiplayer programming in Blueprints or C++. For basic applications Blueprints are fine, but they do have limitations because they don't have access to everything multiplayer like C++ does._

1. [Unreal Docs - Networking and Multiplayer](https://docs.unrealengine.com/5.1/en-US/networking-and-multiplayer-in-unreal-engine/)
2. Wizard Cell:
    1. [Unreal Engine Multiplayer Tips and Tricks](https://wizardcell.com/unreal/multiplayer-tips-and-tricks/)
    2. [Unreal Engine Persistent Data Compendium](https://wizardcell.com/unreal/persistent-data/)
3. [Replicated Properties vs RPCs](https://forums.unrealengine.com/t/replicated-properties-vs-rpcs/264973) - Article written by Alex K. (An Unreal Engine Staff Member).
4. [Multiplayer Network Compendium](https://cedric-neukirchen.net/docs/category/multiplayer-network-compendium/)
5. [Unreal Engine - Correct stateful replication](https://vorixo.github.io/devtricks/stateful-events-multiplayer/)
6. [Understanding replication atomicity in Unreal Engine](https://vorixo.github.io/devtricks/atomicity/)
7. [Send inputs immediately to server or in an input cache periodically in network game?](https://stackoverflow.com/questions/28017244/send-inputs-immediately-to-server-or-in-an-input-cache-periodically-in-network-g)
8. [Fast-Paced Multiplayer (Part III): Entity Interpolation](https://www.gabrielgambetta.com/entity-interpolation.html)
9. [Fix Your Timestep!](https://gafferongames.com/post/fix_your_timestep/)
10. [Netcode done right with Jay Mattis of High Horse Entertainment // Between II Servers EP10 - YouTube](https://www.youtube.com/watch?v=fFP7c59ezjo)
11. [How Multiplayer Games Work - YouTube](https://www.youtube.com/watch?v=KBBJqPL5-eU)
12. [Everything you need to know about Tick Rate, Lag, Netcode, Interpolation and Etc. - Reddit](https://www.reddit.com/r/Blackops4/comments/9qkode/everything_you_need_to_know_about_tick_rate_lag/)
13. [Overwatch Gameplay Architecture and Netcode - YouTube GDC](https://www.youtube.com/watch?v=zrIY0eIyqmI)
14. [It IS Rocket Science! The Physics of Rocket League Detailed - YouTube GDC](https://www.youtube.com/watch?v=ueEmiDM94IE)
15. [Networked Movement in the Character Movement Component - UE5 Docs](https://docs.unrealengine.com/5.1/en-US/understanding-networked-movement-in-the-character-movement-component-for-unreal-engine/)
16. [The right way to Lerp in Unity (with examples)](https://gamedevbeginner.com/the-right-way-to-lerp-in-unity-with-examples/) - This is still relevant in Unreal Engine.



# Fun Reading

1. [The ShooterGame vulnerability that was spread to many games](https://vorixo.github.io/devtricks/shootergame-vulnerability/)