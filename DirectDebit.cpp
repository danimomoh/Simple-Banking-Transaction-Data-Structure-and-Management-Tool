/* PLAGIARISM DECLARATION
“I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct
and dealt with accordingly.  I understand that if I lend this piece of work to another
student and they copy all or part of it, either with or without my knowledge or
permission, I shall be guilty of collusion.  In submitting this work I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.”
“Name:  Ugbede Daniel Momoh     ID No:  N0953313” */
#include "DirectDebit.h"
// Definition of set and get methods to access the variable of the class
DirectDebit::DirectDebit()	//constructor definition
{
	set_datetime();
}

DirectDebit::~DirectDebit()	//destructor definition
{
	cout << "Destroying direct debit object" << endl;
}

void DirectDebit::set_dd_details(double r, string s)
{
	amount = r; ref = s;
}

void DirectDebit::printout()
{
	cout << "DD" << " " << day << " " << month << " " << year << " " << mytime << " " << amount << " " << ref << endl;
}

void DirectDebit::savetofile(ofstream& outfile)
{
	outfile << "DD" << " " << day << " " << month << " " << year << " " << mytime << " " << amount << " " << ref << endl;
}

void DirectDebit::loadfromfile(istringstream& iss)
{
	iss >> day >> month >> year >> mytime >> amount >> ref;
}