/* PLAGIARISM DECLARATION
“I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct
and dealt with accordingly.  I understand that if I lend this piece of work to another
student and they copy all or part of it, either with or without my knowledge or
permission, I shall be guilty of collusion.  In submitting this work I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.”
“Name:  Ugbede Daniel Momoh     ID No:  N0953313” */
#include "List.h"

//definition of constructor for list class
List::List()
{
	//head points to o initially and when the list is empty
	//otherwise head points to most recently added object
	head = 0;
	numofObjs = 0;
}

//insert new object to linked list
int List::add(Transaction& x)
{
	//pointer 'temp' used to instatiate objects to add to list
	Link* temp;

	//memory allocated and the object is given a value
	temp = new Link(x);
	if (temp == 0)//check new succeeded
	{
		return 0;
	}
	//the pointer in the object is set to whatever head is pointing to
	temp->Next = head;
	//head is redirected to point to the last created object
	head = temp;
	numofObjs++;

	return 1;
}

//Delete object from the top of the list
int List::remove()
{
	Link* temp;

	if (head == 0)	//check if list is empty
	{
		cout << "Empty transaction list, no items to delete" << endl;
		return 0;
	}

	temp = head;
	head = head->Next;
	cout << "...Deleting object..." << endl;
	delete temp;

	return 1;
}

//definition of display method for list content
void List::display()
{
	//pointer used to iterate through the list
	Link* temp;

	if (head == 0) { cout << "No more contents in list" << endl; }
	//for loop to iterate through entire list
	for (temp = head; temp != 0; temp = temp->Next)
	{
		temp->X->printout();
	}
}

//display method for first ten transactions in list
void List::displayTen()
{
	//pointer used to iterate through the list
	Link* temp;

	temp = head;
	for (int i = 0; i < 10; i++)
	{
		if (temp == 0) { cout << "No more contents in list" << endl;  break; }
		temp->X->printout();
		temp = temp->Next;
	}
}

//save list contents to file
void List::writetoFile()
{
	Link* temp;	//pointer to iterate through list
	string file_name;
	cout << "Enter the name of file you wish to append your transactions (in the format name.txt): ";
	cin >> file_name;
	ofstream outfile(file_name.c_str(), ios::app);
	if (outfile.is_open())	//check if file was successfully created
	{
		cout << "Saving to file..." << endl;
		//for loop to iterate through entire list
		for (temp = head; temp != 0; temp = temp->Next)
		{
			temp->X->savetofile(outfile);
		}
		outfile.close();
	}
	else { cout << "Unable to open file" << endl; }
}

//size function definition
int List::size()
{
	return numofObjs;
}

//get object function definition
Transaction* List::getObj(int loc)
{
	Link* temp = head;
	if (head == 0) { cout << "List is currently empty" << endl; return 0; }

	for (int i = 0; i < loc; i++)
	{
		temp = temp->Next;
	}

	return temp->get();
}

//definition of setobj function
void List::setObjLoc(int loc, Transaction* obj)
{
	Link* temp = head;
	for (int i = 0; i < loc; i++)
	{
		temp = temp->Next;
	}
	temp->X = obj;
}


//list destructor definition
List::~List()
{
	cout << "Destructor called" << endl;
	//List::clear();
}