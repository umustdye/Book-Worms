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
    - User Information (Account Username, Account Password)
    - Library Item Information (Book/CD/DVD Title, Book/CD/DVD Quantity on Hand, Book/CD/DVD Genre/Sub-genre, Item Type)
    - Library Item Changes (Add/Edit/Remove Item)
  - Output: 
    - User Displays (Books currently borrowed, Available Books/CDs/DVDs)

### Design Patterns
  - Design 1: Composite Pattern
    - We picked the Composite Pattern for its simplicity and its ability to treat primitives and composites uniformly. We intend to use it to implement items in our library like Books, DVDs, and CDs that have genres / sub-genres. The problem we anticipate in the project is in both adding more items / collections of items to the library and in searching through them to create user recommendations. The composite pattern will allow us to use a single interface to easily add more primitives and composites to the libary and then search through the tree of items for our various reasons. 
  - Design 2: Factory Pattern
    - We picked the Factory Pattern for its object creation-focus design that allows for creating objects from an interface. We intend to use it to determine if we create a book, cd, dvd, or collection object. The problem we intend to solve is in being able to select a product to create an object simply. It is a benefit that our product classes above are consistent apart from a few variables.

## Class Diagram

 ![Library item OMT](https://github.com/cs100/final-project-final-project-hdye001-shall016-calex025/blob/master/images/LibraryItemOMT.png?raw=true)
  - Library Item Composite Pattern
    - A library item can consist of a book, dvd, cd, or a collection which consists of multiple books, dvds, and/or cds. A collection could be the Lord of the Rings Trilogy for example. So the Book, DVD, and CD classes, which are our leafs, represent the type of library item that the item is and the Library Item Collection class, which is our composite, represents multiple books, dvds, and/or cds. The Lbrary item Component class, which is our component, represents any item in the library system. It holds all the values that are true to all items in the libary sytems such as return due date and the year it was released. This class is what is derivative to the client. 
 
![Factory Pattern OMT](https://github.com/cs100/final-project-final-project-hdye001-shall016-calex025/blob/master/images/factory-pattern.png?raw=true)
  - Factory Pattern
    - In terms of structure above we have a concrete factory called LibraryItemFactory that can create objects of the classes of either Book, Cd, Dvd, or LibraryItemCollection. These four are the concrete products . The abstract product they all inherit from is the LibraryItemComponent class. The factory pattern lets the user create these different library objects and allows them to be modified this way as well.
 
 ## Screenshots
 ![Screenshot 1](https://github.com/cs100/final-project-final-project-hdye001-shall016-calex025/blob/master/images/screenshot-1.png?raw=true)
 ![Screenshot 2](https://github.com/cs100/final-project-final-project-hdye001-shall016-calex025/blob/master/images/screenshot-2.png?raw=true)
 ![Screenshot 3](https://github.com/cs100/final-project-final-project-hdye001-shall016-calex025/blob/master/images/screenshot-3.png?raw=true)
 ![Screenshot 4](https://github.com/cs100/final-project-final-project-hdye001-shall016-calex025/blob/master/images/screenshot-4.png?raw=true)
 ![Screenshot 5](https://github.com/cs100/final-project-final-project-hdye001-shall016-calex025/blob/master/images/screenshot-5.png?raw=true)
 ![Screenshot 6](https://github.com/cs100/final-project-final-project-hdye001-shall016-calex025/blob/master/images/screenshot-6.png?raw=true)
 ![Screenshot 7](https://github.com/cs100/final-project-final-project-hdye001-shall016-calex025/blob/master/images/screenshot-7.png?raw=true)
 ![Screenshot 8](https://github.com/cs100/final-project-final-project-hdye001-shall016-calex025/blob/master/images/screenshot-8.png?raw=true)
 
 ## Installation/Usage
 The first thing to do in order to run this project yourself is to create an account for and download Qt.
 It is free and open source. We used the latest version, here it is ->[Qt 6](https://www.qt.io/download-open-source).
 You can just download the default / recommended option. This includes SQLite for you.
 
 Once that is installed on your machine, go ahead and download this repo from GitHub onto your local machine.
 Either do a `git clone https://github.com/cs100/final-project-final-project-hdye001-shall016-calex025.git` or use the same green code dropdown tab to download the .zip file. Unzip the file if you went this route.
 
 Open the Qt program and go to Open a project. Navigate to where you stored the project file above and click on the `.pro` file to open the project in Qt. From here click the big green play button on the bottom left of the screen in Qt to start the program, Qt will load in everything automatically if you followed the steps above.
  
 ## Testing
 For testing this project we used the `google test` unit testing library.
 The C++ gui application we used, Qt 6, has support for google test and is able to run it inside their project window. This is because Qt uses for example QVector instead of std::vector and QString instead of std::string. We can run it using the command line or inside the Qt window. Valgrind is also included in Qt and can be run inside the Qt window.
 
