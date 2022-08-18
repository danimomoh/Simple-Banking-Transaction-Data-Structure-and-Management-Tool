/* PLAGIARISM DECLARATION
“I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct
and dealt with accordingly.  I understand that if I lend this piece of work to another
student and they copy all or part of it, either with or without my knowledge or
permission, I shall be guilty of collusion.  In submitting this work I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.”
“Name:  Ugbede Daniel Momoh     ID No:  N0953313” */
#include "CashPoint.h"

//construtctor
CashPoint::CashPoint()
{
	set_datetime();
}

//destructor
CashPoint::~CashPoint()
{
	cout << "Destroying cashpoint object" << endl;
}

//methods definitions
void CashPoint::setcpDetails(int r, int s, double t) {
	cashpoint_loc = r; card_type = s; amount = t;
}

void CashPoint::printout()
{
	cout << "CSP" << " " << day << " " << month << " " << year << " " << mytime << " " << amount << " " << card_type << " " << cashpoint_loc << endl;
}

void CashPoint::savetofile(ofstream& outfile)
{
	outfile << "CSP" << " " << day << " " << month << " " << year << " " << mytime << " " << amount << " " << card_type << " " << cashpoint_loc << endl;

}

void CashPoint::loadfromfile(istringstream& iss)
{
	iss >> day >> month >> year >> mytime >> amount >> card_type >> cashpoint_loc;
}