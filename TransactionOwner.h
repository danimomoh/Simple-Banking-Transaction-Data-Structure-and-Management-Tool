/* PLAGIARISM DECLARATION
“I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct
and dealt with accordingly.  I understand that if I lend this piece of work to another
student and they copy all or part of it, either with or without my knowledge or
permission, I shall be guilty of collusion.  In submitting this work I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.”
“Name:  Ugbede Daniel Momoh     ID No:  N0953313” */
#pragma once
#include<iostream>
#include<string>
#include "Transaction.h"
#include "CashPoint.h"
#include "CreditPoint.h"
#include "Debit.h"
#include "DirectDebit.h"
#include "Interest.h"
#include "Transfer.h"
#include "List.h"

//Transaction owner class is created to implement an abstract factory design pattern
class TransactionOwner
{
public:
	Transaction& createObj();	//function to create and return a new object of any derived type of abstract Transaction class
	void load(List&);	//load option to load data from file
	void search(List&);	//function to perform linear search on transaction list
	void sortlist(List&);	//function to perform sort on transaction list
	int converMnthtoNum(string);	//converting the month string to number
	int dateCompare(Transaction*, Transaction*);	//function to compare two dates
};

