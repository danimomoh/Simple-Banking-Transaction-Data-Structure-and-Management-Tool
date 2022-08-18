"# Simple-Banking-Transaction-Data-Structure-and-Management-Tool" 
*** A system (to be developed as a program written in C++ and using the command line for output) is required that allows the user to create and edit a list containing a number of initially unordered Banking Transaction objects. The Banking Transaction objects represent various types of currency withdrawals by debit card, cashpoint machine, direct debit, and deposits by transfer, creditpoint machine and interest payment. The Banking Transaction objects will be entered by the user and stored in a linked list (consisting of a List class and a Link class) ***
The Banking Transaction objects will have a Transaction base class that has the derived classes: Debit, Cashpoint, DirectDebit, Transfer, Creditpoint and Interest.
Transaction will be an abstract class and its subclasses will be concrete classes.
All Transaction derived classes will have a type, date, time and amount (in pounds and pence). In addition:
• Class Debit will have attributes to store the card number used, retailer name, retailer location, authorisation method (online, phone, mail order).
• Class Cashpoint will have attributes to store the location id of the cashpoint machine, and the card used.
• Class DirectDebit will have an attribute to store a reference.
• Class Transfer will have attributes to store the account number and bank sort code from where the transfer originated.
• Class Creditpoint will have an attribute to store the type of payment (cheque or cash).
• Class Interest will have an attribute to store the type of interest (daily, monthly or annual).
The user will be able to set the attributes of the Banking Transaction objects only when they are created and not after addition to the link list. The type of Banking Transaction should not need to be stored as a class attribute to record what the type of derived class is (e.g. typeid can be used to identify the type of derived class), but the program will need to be store the type in the file output.
The user interface will be a menu having the following options:
Q - Quit: The program should end without saving the Banking Transaction objects.
I - Insert an object: The user should be prompted to enter a Banking Transaction object type and its attributes, and place the Banking Transaction object at the top (start) of the linked list.
D - Delete an object: The Banking Transaction object at the top of the linked list is deleted.
C - Contents of the list: Display a list of all the Banking Transaction objects, their type and their attributes.
U – Contents of the upper objects: Display a list of the first ten Banking Transaction objects, their type and their attributes.
S - Save to file: Ask the user for a filename and append (add to the end of the file) all the Banking Transaction objects, from the linked list, and their attributes in that file. The same text format should be used in this file as in the supplied test file TestData.txt (see below).
L - Load from file: Ask the user for a filename and load the Banking Transaction objects and their attributes from that file into the program’s linked list. The Banking Transaction objects are added to those already in the program’s linked list. The file saved in ‘S’ should be able to be loaded in ‘L’.
N – Linear Search: Perform a linear search through the link list to find all Banking Transaction objects with a specified date (i.e. any time on that date) and display its attribute values. The linear search algorithm used should be from lecture 11 and lab 11.
T – Sort: Sort the Linked List so that the date attribute of each Banking Transaction object is decreasing (getting further back in time) from the top of the link list. The sort algorithm used should be from lecture 11 and lab 11.
After completion of each choice, other than Quit, the system waits for the user to press a key to return to the menu again.
Your report section ‘Evaluation of the program’ (see below) should include an evaluation of the speed of the linear search and sort operations on the supplied data file ‘TestData.txt’ for either: Stage 1 the linked list; or Stage 2 the linked list compared with the STL stack.
