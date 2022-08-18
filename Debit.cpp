/* PLAGIARISM DECLARATION
“I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct
and dealt with accordingly.  I understand that if I lend this piece of work to another
student and they copy all or part of it, either with or without my knowledge or
permission, I shall be guilty of collusion.  In submitting this work I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.”
“Name:  Ugbede Daniel Momoh     ID No:  N0953313” */
#include "Debit.h"
//constructor
Debit::Debit() {
	card_Num = 0;
	set_datetime();
}

//destructor
Debit::~Debit() { cout << "Destroying debit  object" << endl; }

// Definition of set and get methods to access the variable of the Class
void Debit::set_debitDetails(int p, string q, string r, string s, double t) {
	card_Num = p; retailer_name = q; retailer_loc = r; auth_method = s; amount = t;
}

//console output
void Debit::printout()
{
	cout << "DB" << " " << day << " " << month << " " << year << " " << mytime  << " " << amount << " " << card_Num << " " << retailer_name << " " << retailer_loc << " " << auth_method << endl;
}

//save to file
void Debit::savetofile(ofstream& outfile)
{
	outfile << "DB" << " " << day << " " << month << " " << year << " " << mytime << " " << amount << " " << card_Num << " " << retailer_name << " " << retailer_loc << " " << auth_method << endl;
}

//load data from file
void Debit::loadfromfile(istringstream& iss)
{
	iss >> day >> month >> year >> mytime >> amount >> card_Num >> retailer_name >> retailer_loc >> auth_method;
}