# Vending Machine
This project is a simple object oriented design problem. The goal is to encourage and explore the use of a formal process even when working on a small project. This readme serves as a platform for my documentation throughout the project.
## Process
### Project Workflow
1. Understand general problem statement
1. Document a process and rough schedule
1. Generate requirements
1. Architect a solution using class / other UML diagrams
1. Implement code and tests (see below for details on the coding process)
1. If code cannot be completed in the allotted time, document work completed and remaining steps  
1. Release deliverables for end of project
### Code Developement
Code will be written in a Test Driven Development manner (TDD). This will be my first project doing official TDD so it will likely slow my initial progress down to some extent but I expect to save time debugging and come out with cleaner interfaces.
## Environment
The project will be written in C++ and will be developed in Visual Studio. We'll try to leverage as many tools as possible within VS, but some features (like architecture diagrams) are not supported in the free version.
* Visual Studio Community 2019
** Test Adapter for Google Test (Visual Studio component)
** CodeMaid (code style-izer extension)
* Draw.io (for architecture diagrams)
## Schedule
### 20 Hour Project
**( Planned | Executed)**
* ( 1.0 hour | 1.0 hour ): Initial process documentation
* ( 1.0 hour | 0.5 hour ): Initial requirements
* ( 1.0 hour | 1.0 hour ): Environment setup
* ( 3.0 hour | 4.5 hour ): Initial architecture
* ( 5.0 hour | 4.0 hour ): Coding block 1
* ( 3.0 hour | 4.0 hour ): Revisit requirements and architecture
* ( 4.0 hour | 3.0 hour ): Coding block 2
* ( 1.0 hour | 1.0 hour ): Release prep
* ( 1.0 hour | 1.0 hour ): Documentation wrap up and release
## Design Thoughts - Initial
Since there are many different types of vending machines we'll try to make the application as custom as possible. For example, we should allow different implementation for vending mechanism, temperature control, inventory management, payment system, etc. We should separate our application logic from this driver logic. We can also try our hand at some dependency inversion here and we will have the application and drivers depend on abstracted interfaces. 

In a simple machine a user could just look through the plexi-glass to find the item and then check the slot number. In a more complex machine (like one that might dispense pharmaceuticals for nurses at a hospital) the user might interact with a display to find the item they want and select the item itself. In these two cases the mechanism for getting the slot number is different; the former has the user enter the number directly and the latter gets the number based on the item. The focus for this project will be to implement something that supports the more complex design since it requires more of an object-oriented design. The stretch goal would allow for the application to support simpler vending machine implementations as well.
## Requirements
These requirements are written a bit more like features, but the idea is just to capture a bulleted list of the objectives for our software.
* Software shall allow a user to insert money to pay for items.
* Software shall allow a user to select an item.
* Software shall alert the user if an item is out of stock.
* Software shall support temperature control.
* Software shall support ability to drive a vending mechanism.
* Software shall support restocking items.
* Software shall be modular to allow components to be hot-swapped without recompiling.
* Software shall be multi-threaded.
## Architecture
An architecture diagram will be uploaded to the repo, but we'll supplement that diagram with some notes here. Note that this code is written as if it is being developed for a Windows platform. Obviously your typical vending machine is not going to be running Windows but this will give us an easy way to try out dynamic linking with DLL's.
* Support flexibility by implementing drivers as DLL's
* Drivers will refer to the Hardware Abstraction Layer (e.g. our vending machine logic should not care about how an item is dispensed, just that a mechanism is provided to dispense an item)
* Higher level application and drivers will depend on common interface (dependency inversion)
* Application code will also be implemented as a library to support unit testing of application logic
* A runner will be provided to execute the vending machine application
* Consider how we should handle cases where we cannot load a driver
## Design Thoughts - Approaching 20 Hour Mark
### Time Analysis
A majority of the time has been spent on development of the architecture. Since I did not have experience with developing DLL's, I spent a while learning about them and their pitfalls. Admittedly, I considered completely scrapping the DLL idea at one point because it felt like it was getting cumbersome to setup. It may not be the most practical design for a vending machine but I'm glad I continued down this path for the sake of trying something new. I would've liked to have more of the implementation complete at this point, but I'm happy with the design and think I did well to setup the code for extension.
In retrospect, I wish I had planned to implement a single-threaded, blocking application on first pass then move to something multi-threaded. I spent a couple hours researching clean ways of doing thread-safe transactions with DLL's but ultimately decided to stick with single threaded for the 20 hour mark. This cost me some time and did not add value (yet!) to the project.
### Pros and Cons of Chosen Design
#### Pro
* Modular and extensible. Once the interfaces are setup to use the asynchronous callbacks it would be easy for a developer to write a new module as a library and not have to change any of the vending machine logic.
* DLL's hide logic from the vending machine that the machine shouldn't care about. Many of the modules represent some kind of hardware interface which could make sense to represent as a 'singleton'. Perhaps we write another application that needs to ensure temperature is controlled properly; both the vending machine and the other app could get access to the same object without the apps needing to know about each other.
#### Con
* A lot of project overhead. In order to fully unit test each of the modules, I chose to create both static and dynamic libraries for each one. The static libraries are just used for unit testing while the projects for the dynamic libraries just provide a mechanism for getting an instance of the object in a DLL-friendly way. It fits with the Single Responsibility Principle, but 20 hours in and I already have 10 projects in my solution...
* Do you really want your vending machine running Windows? :) This one is kind of moot since we could always make the libraries into shared object files, but still worth noting because I haven't done much research on the differences between the two
### Preview of Next Steps
1. Database mechanism for tracking items (JSON file most likely)
1. Ability to restock items (via application, prior to this I could edit the file directly)
1. Method to switch between restocking and purchasing
1. Payment mechanism
1. Convert interfaces to asynchronous + multithreaded
1. Load DLL's based on filename prefix (e.g. "TemperatureController_") to allow true hotswapping
### Unfortuante Oversight
After talking over my design with another software engineer, I realized that DLL's would not be accomplishing exactly what I thought they would. My assumption was that if multiple applications / processes tried to load a DLL, they would be loading it from a shared memory space. That is not the case. Every application that loads a DLL will load it at most one time and load it into the context of the calling process' memory. I would likely need to change some other aspects of my design to acheive what I'm ultimately looking for. For example, let's say that we added another process to the system that is running the vending machine software and that process also needs to know the status of the temperature control mechanism. The processes would not be accessing the same temperature control object in memory which means the DLL cannot use mutexes and other thread guards to manage access to a HAL resource; we would need to use other mechanisms instead. If it were a Unix system with device files we could use file access errors to manage the shared resource.

I may not take this change into account if I progress futher in the project but wanted to specifically call it out for future reference.
## References
* Draw.io - https://www.draw.io/
* Learning about DLL's - https://docs.microsoft.com/en-us/windows/win32/dlls/dynamic-link-libraries
* Creating example DLL - https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=vs-2019
