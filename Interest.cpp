/* PLAGIARISM DECLARATION
“I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct
and dealt with accordingly.  I understand that if I lend this piece of work to another
student and they copy all or part of it, either with or without my knowledge or
permission, I shall be guilty of collusion.  In submitting this work I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.”
“Name:  Ugbede Daniel Momoh     ID No:  N0953313” */
#include "Interest.h"
// Definition of set and get methods to access the variable of the class
Interest::Interest()	//constructor definition
{
	set_datetime();
}

Interest::~Interest()	//destructor definition
{
	cout << "destroying interest object" << endl;
}

void Interest::set_int_details(double r, string s)
{
	amount = r; interest_type = s;
}

void Interest::printout()
{
	cout << "INT" << " " << day << " " << month << " " << year << " " << mytime << " " << amount << " " << interest_type << endl;
}

void Interest::savetofile(ofstream& outfile)
{
	outfile << "INT" << " " << day << " " << month << " " << year << " " << mytime << " " << amount << " " << interest_type << endl;
}

void Interest::loadfromfile(istringstream& iss)
{
	iss >> day >> month >> year >> mytime >> amount >> interest_type;
}