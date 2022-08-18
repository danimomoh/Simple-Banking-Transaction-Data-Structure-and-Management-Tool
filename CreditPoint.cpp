/* PLAGIARISM DECLARATION
“I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct
and dealt with accordingly.  I understand that if I lend this piece of work to another
student and they copy all or part of it, either with or without my knowledge or
permission, I shall be guilty of collusion.  In submitting this work I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.”
“Name:  Ugbede Daniel Momoh     ID No:  N0953313” */
#include "CreditPoint.h"
//definition of set and get methods to access the variable of the class
CreditPoint::CreditPoint()	//constructor
{
	set_datetime();
}

CreditPoint::~CreditPoint()
{
	cout << "Destroying credit point object" << endl;
}

void CreditPoint::set_cdp_details(double p, string s)
{
	amount = p; payment_type = s;
}

void CreditPoint::printout()
{
	cout << "CDP" << " " << day << " " << month << " " << year << " " << mytime << " " << amount << " " << payment_type << endl;
}

void CreditPoint::savetofile(ofstream& outfile)
{
	outfile << "CDP" << " " << day << " " << month << " " << year << " " << mytime << " " << amount << " " << payment_type << endl;
}

void CreditPoint::loadfromfile(istringstream& iss)
{
	iss >> day >> month >> year >> mytime >> amount >> payment_type;
}