/* PLAGIARISM DECLARATION
“I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct
and dealt with accordingly.  I understand that if I lend this piece of work to another
student and they copy all or part of it, either with or without my knowledge or
permission, I shall be guilty of collusion.  In submitting this work I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.”
“Name:  Ugbede Daniel Momoh     ID No:  N0953313” */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <typeinfo>


// including header files for all classes
#include "CashPoint.h"
#include "CreditPoint.h"
#include "Debit.h"
#include "DirectDebit.h"
#include "Interest.h"
#include "Transaction.h"
#include "Transfer.h"
#include "TransactionOwner.h"
#include "Link.h"
#include "List.h"

using namespace std;

//start of the main program
int main()
{
	char user_choice;	//takes user input to determine what transaction to initiate
	//Implementation of the abstract factory design pattern for creating objects - initialising pattern class
	TransactionOwner transactionOwner;
	
	//initialise linked list to be used in the program
	List transaction_list;

	//Display intro message
	cout << "-----------Welcome to Felon 360's Banking App, I hope you enjoy using our system---------" << endl;

	//Program control
	do
	{
		cout << "Please select the type of transaction you wish to perform from the following options: " << endl;
		cout << "Q - Quit: To end without saving \nI - Insert/Create a transaction \nD - Delete a transaction \nC - Display contents of the list\
			\nU - Display contents of the upper 10 transactions \nS - Save to file \nL - Load from file \nN - Linear Search \nT - Sort \n" << endl;

		cin >> user_choice; //get user input to select transaction

		//Exit program without saving
		if (user_choice == 'Q' || user_choice == 'q') {
			cout << "You are about to quit the program without saving your transactions \nPress enter to confirm..." << endl;
			cin.ignore();
		}

		//insert new object to the top of the linked list
		else if (user_choice == 'I' || user_choice == 'i') {
			cout << "...You are about start a new transaction..." << endl;
			Transaction& mytransaction = transactionOwner.createObj();	//create object to be inserted using a reference to the abstract class
			transaction_list.add(mytransaction);	//add created object to the linked list
			cout << "object successfully created and added to transactions list" << endl; //check mechanism for object addition to list
		}

		//delete an object from the top of linked list
		else if (user_choice == 'D' || user_choice == 'd') {
			cout << "...Initiating delete option..." << endl;
			int check_remove = 1;
			check_remove = transaction_list.remove();
			if (check_remove) { cout << "Transaction at the top of the list deleted successfully" << endl; }
			else { cout << "Unable to delete transaction, try again" << endl; }
			
			cout << endl;
		}

		//display all contents of the transaction linked list
		else if (user_choice == 'C' || user_choice == 'c') {
			cout << "-------Displaying contents of the list------" << endl;
			transaction_list.display();	//display list contnts
			cout << endl;
		}

		//Display contents of first ten transactions in the list
		else if (user_choice == 'U' || user_choice == 'u') {
			cout << "-----Displaying contents of the first ten objects-----" << endl;
			transaction_list.displayTen();
			cout << endl;
		}

		//save contents of list to .txt file
		else if (user_choice == 'S' || user_choice == 's') {
			//ofstream myfile;	//file stream object to handle writing to file
			cout << "-----Saving transactions option initiated------" << endl;
			transaction_list.writetoFile();
			cout << endl;
		}

		//Load contents from a file into linked list 
		else if (user_choice == 'L' || user_choice == 'l') {
			cout << "--------Load from file option initiated----------" << endl;
			transactionOwner.load(transaction_list);
			cout << endl;
		}

		//Perform linear search on ltems in linked list
		else if (user_choice == 'N' || user_choice == 'n') {
			cout << "-----Search option initiated------" << endl;
			transactionOwner.search(transaction_list);
			cout << endl;
		}

		//Sort in decreasing order of time
		else if (user_choice == 'T' || user_choice == 't') {
			cout << "--------Sort contents of list initiated------" << endl;
			transactionOwner.sortlist(transaction_list);
			cout << endl;
		}

		//check if option entered is valid
		else {
			cout << "Incorrect option, please enter a valid choice" << endl;
		}
	} while ((user_choice != 'Q') && (user_choice != 'q'));

	return 0;
}