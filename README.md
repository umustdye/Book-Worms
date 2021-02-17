# Library System
Authors: [Heidi Dye](https://github.com/umustdye), [Sebastian Hall](https://github.com/Sebastian-Hall), [Christopher R Alexman](https://github.com/ChristopherCE)

## Project Description
### Project Importance
  - This project grabbed at our interest because of the versatility of implementing a library system. The system allows for users to search for items, in this case books, CDs and DVDS, and rent based on the quantity left. An admin account can add, delete, and edit inventory. The library system can be used as a template for a store's online shopping system for customers. So, this program could have personal use as well as professional use.
  
### Languages, Tools, and Technologies
  - C++17 - Written in C++ 17
  - [Qt 6](https://www.qt.io/product/qt6) - C++ based gui library
  - [SQLite](https://sqlite.org/index.html) - SQLite database
  - [Valgrind](https://www.valgrind.org/) - Memory error detector
  - [Git](https://github.com) - Version control software
  
### Input / Output
  - Input: 
    - User Information (Account Name, Account Password)
    - Library Item Information (Book/CD/DVD Title, Book/CD/DVD Quantity on Hand, Book/CD/DVD Genre/Sub-genre, Item Type)
    - Library Item Changes (Add/Edit/Remove Item)
  - Output: 
    - User Displays (Books currently borrowed, Account Debt, Available Books/CDs/DVDs, Recommended Books/CDs/DVDs)

### Design Patterns
  - Design 1: Composite Pattern
    - We picked the Composite Pattern for its simplicity and its ability to treat primitives and composites uniformly. We intend to use it to implement items in our library like Books, DVDs, and CDs that have genres / sub-genres. The problem we anticipate in the project is in both adding more items / collections of items to the library and in searching through them to create user recommendations. The composite pattern will allow us to use a single interface to easily add more primitives and composites to the libary and then search through the tree of items for our various reasons. 
  - Design 2: Strategy Pattern
    - We picked the Strategy Design Pattern for its ability to easily allow algorithms to vary independently when being used by the client. We intend to use this design pattern to allow the admin to update, add, and delete library items in the library system. The problem we anticipate is adding and updating items when library items can be of different types, such as books, CDs, DVDs, and Collections. The strategy pattern will allow us to implement udp multipleate and add functions for each of the types of items with only one update and add function in the admin class.
  - Design 3: Mediator Pattern
    - We picked the Mediator pattern for its ability to allow objects to interact with each other. We intend to use it to connect the user account class and the library item component class and to notify when a library item is either checked out or returned by a user. The problem we are solving with this design pattern is having this notification feature without having to connect the two classes directly, instead they interact through the mediator. This is a good solution to this feature as the interactions are encapsulated in a mediator object, it has loose coupling, and it makes it easier to modify or add new features later.


 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 

 ![Library item UML](https://github.com/cs100/final-project-final-project-hdye001-shall016-calex025/blob/master/images/LibraryItemUML.png?raw=true)
  - Library Item Composite Pattern
    - A library item can consist of a book, dvd, cd, or a collection which consists of multiple books, dvds, and/or cds. A collection could be the Lord of the Rings Trilogy for example. So the Book, DVD, and CD classes, which are our leafs, represent the type of library item that the item is and the Library Item Collection class, which is our composite, represents multiple books, dvds, and/or cds. The Lbrary item Component class, which is our component, represents any item in the library system. It holds all the values that are true to all items in the libary sytems such as return due date and the year it was released. This class is what is derivative to the client. 
 
![Admin Strategy UML](https://github.com/cs100/final-project-final-project-hdye001-shall016-calex025/blob/master/images/admin_strategy_uml.png?raw=true)
  - Admin strategy pattern for modifying library content. An admin has the ability to add, update, and remove four different items through a singular interface that allows. There are three different strategy patterns, one for each of the major types of modifications that an admin can make.

 ![Mediator OMT](https://github.com/cs100/final-project-final-project-hdye001-shall016-calex025/blob/master/images/mediator-design-pattern.png?raw=true)
   - User Account and Library Item Mediator Design Pattern
    - The main function of the mediator design pattern is to connect the user account and library item classes. It will create a notification when the user account either checks out or returns a library item to the library, these are functions in their respective classes. For the structure the Library class is an abstract base class and interface that communicates with the abstract Communicator class. The Coordinator class inherits from the Library class and
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
