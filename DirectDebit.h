/* PLAGIARISM DECLARATION
?I am aware of the University?s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct
and dealt with accordingly.  I understand that if I lend this piece of work to another
student and they copy all or part of it, either with or without my knowledge or
permission, I shall be guilty of collusion.  In submitting this work I confirm that
I am aware of, and am abiding by, the University?s expectations for proof-reading.?
?Name:  Ugbede Daniel Momoh     ID No:  N0953313? */
#pragma once
#include "Transaction.h"
class DirectDebit :
    public Transaction
{
    // Direct debit class attribute
private:
    string ref;
    //Declaration of public method for Direct debit
public:
    DirectDebit();
    ~DirectDebit();
    void set_dd_details(double, string);
    void printout();
    void savetofile(ofstream&);
    void loadfromfile(istringstream&);
};

