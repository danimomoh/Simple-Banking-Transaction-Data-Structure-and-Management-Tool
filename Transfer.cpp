/* PLAGIARISM DECLARATION
“I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct
and dealt with accordingly.  I understand that if I lend this piece of work to another
student and they copy all or part of it, either with or without my knowledge or
permission, I shall be guilty of collusion.  In submitting this work I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.”
“Name:  Ugbede Daniel Momoh     ID No:  N0953313” */
#include "Transfer.h"
//Definition of set and get methods to access the variable of the class
Transfer::Transfer()	//constructor definition
{
	set_datetime();
}

Transfer::~Transfer()	//destructor definition
{
	cout << "Destroying transfer object" << endl;
}

void Transfer::set_tr_details(double r, int p, string s)
{
	amount = r; account_num = p; sort_code = s;
}

void Transfer::printout()
{
	cout << "TR" << " " << day << " " << month << " " << year << " " << mytime << " " << amount << " " << account_num << " " << sort_code << endl;
}

void Transfer::savetofile(ofstream& outfile)
{
	outfile << "TR" << " " << day << " " << month << " " << year << " " << mytime << " " << amount << " " << account_num << " " << sort_code << endl;
}

void Transfer::loadfromfile(istringstream& iss)
{
	iss >> day >> month >> year >> mytime >> amount >> account_num >> sort_code;
}