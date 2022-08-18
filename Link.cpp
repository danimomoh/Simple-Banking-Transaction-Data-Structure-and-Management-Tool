/* PLAGIARISM DECLARATION
“I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct
and dealt with accordingly.  I understand that if I lend this piece of work to another
student and they copy all or part of it, either with or without my knowledge or
permission, I shall be guilty of collusion.  In submitting this work I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.”
“Name:  Ugbede Daniel Momoh     ID No:  N0953313” */
#include "Link.h"

//definition of constructor for link class
Link::Link(Transaction& px)
{
	//cout << "beginning link constructor" << endl;
	X = &px;
	//cout << "entered link constructor" << endl;
	Next = 0;
	//cout << "exiting link constructor" << endl;
}

Transaction* Link::get()
{
	return X;
}