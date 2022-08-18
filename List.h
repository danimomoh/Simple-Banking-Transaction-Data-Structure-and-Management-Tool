/* PLAGIARISM DECLARATION
“I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct
and dealt with accordingly.  I understand that if I lend this piece of work to another
student and they copy all or part of it, either with or without my knowledge or
permission, I shall be guilty of collusion.  In submitting this work I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.”
“Name:  Ugbede Daniel Momoh     ID No:  N0953313” */
#pragma once
#include "Link.h"
#include <fstream>
class List
{
	Link* head;
	int numofObjs;
public:
	List();	//declare a constructor for list class
	~List();
	int add(Transaction&);	//declare method to add new object to the list
	int remove();	//delete an object from the top of the list
	void display();		//display content of list
	void displayTen();	//display first ten transactions in list
	void writetoFile();	//save contents of the list to file
	int size();	//return number of elements in list
	Transaction* getObj(int);	//get object at position
	void setObjLoc(int, Transaction*);	//replace object a specific position
};

