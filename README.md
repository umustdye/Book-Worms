 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Library System
Authors: [Heidi Dye](https://github.com/umustdye), [Sebastian Hall](https://github.com/Sebastian-Hall), [Christopher R Alexman](https://github.com/ChristopherCE)
 
 > You will be forming a group of **THREE** students and working on an interesting project. A list of proposed project ideas that have been successful in previous quarters is given in the project specifications link on iLearn. You can select an idea from the list and decide which design patterns you will use to implement it. If you want to propose your own original idea, you will have to contact an instructor to discuss the project and obtain written permission before you submit your project proposal. Your project needs to implement two design patterns.The project work should be divided almost equally among team members and each member is expected to work on at least one design pattern (more than one partner may work on a pattern) and some of its test cases. You can of course help each other, but it needs to be clear who will be responsible for which patterns and for which features.
 
 > ## Expectations
 > * Incorporate **at least two** distinct design patterns. You need to include at least *one* design pattern that we will teach this session:
 >   * Composite, Strategy, Abstract Factory, Visitor, or Decorator
 > * All design patterns need to be linked together (it can't be two distinct projects)
 > * Your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group.

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
  - Design 2: Observer
    - We picked Observer for our design pattern because of its ability to vary subjects and observers independently. We intend to use an observer to implement the administrative accounts for the library system. The problem we anticipate within our program is the admin account editing items, for example the quantity of a book. The oberserver will allow us to have an interface that updates a library component, which will be our observer, when the admin account(s), which is our subject, makes such changes. 

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
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
 
