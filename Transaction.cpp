/* PLAGIARISM DECLARATION
“I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct
and dealt with accordingly.  I understand that if I lend this piece of work to another
student and they copy all or part of it, either with or without my knowledge or
permission, I shall be guilty of collusion.  In submitting this work I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.”
“Name:  Ugbede Daniel Momoh     ID No:  N0953313” */
#include "Transaction.h"

void Transaction::set_datetime()
{
	time_t now = time(0);	//current system date time
	char* dt = ctime(&now);
	string trans_datetime = dt;
	trans_datetime = trans_datetime.substr(0, trans_datetime.length() - 1);
	auto iss = istringstream(trans_datetime.c_str());
	iss >> sday >> month >> day >> mytime >> year;
}