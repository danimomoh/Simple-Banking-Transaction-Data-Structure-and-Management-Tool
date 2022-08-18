/* PLAGIARISM DECLARATION
“I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct
and dealt with accordingly.  I understand that if I lend this piece of work to another
student and they copy all or part of it, either with or without my knowledge or
permission, I shall be guilty of collusion.  In submitting this work I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.”
“Name:  Ugbede Daniel Momoh     ID No:  N0953313” */
#include "TransactionOwner.h"


//definition of function to create and insert object from user input
Transaction& TransactionOwner::createObj() {
	string x;
	//Transaction* mytrans = NULL;
	//Do-while to control the transaction selected
	do {
		cout << "Select the type of transaction you wish to perform from the list below" << endl;
		cout << "DB - Debit \nCP - Cash Point \nDD - Direct Debit \nTF - Transfer \nCR - Credit Point \nIN - Interest \nQ - return to main menu" << endl;
		cin >> x;
		if (x == "DB")	//Debit transaction initiated
		{
			Debit* mytrans = new Debit();
			cout << "Debit transaction initiated" << endl;
			int p; string q; string r; string s; double t;
			cout << "Enter the card number used: ";
			cin >> p;
			cout << endl;
			cout << "Enter the retailer name: ";
			cin >> q;
			cout << endl;
			cout << "Enter the retailer location: ";
			cin >> r;
			cout << endl;
			cout << "Enter the authorisation method (online, phone or mail order): ";
			cin >> s;
			cout << endl;
			cout << "Enter the amount debited: ";
			cin >> t;
			cout << endl;

			mytrans->set_debitDetails(p, q, r, s, t);

			return *mytrans;
		}
		else if (x == "CP")	//Cash point transaction initiated
		{
			CashPoint* mytrans = new CashPoint();
			cout << "Cash Point transaction initiated" << endl;
			int r; int s; double t;
			cout << "Enter the location ID of the store location of the cash point used: ";
			cin >> r;
			cout << endl;
			cout << "Enter the card number used: ";
			cin >> s;
			cout << endl;
			cout << "Enter the amount: ";
			cin >> t;
			cout << endl;

			mytrans->setcpDetails(r, s, t);

			return *mytrans;
		}
		else if (x == "DD")	//Direct debit transaction initiated
		{
			DirectDebit* mytrans = new DirectDebit();
			cout << "Direct debit transaction initiated" << endl;
			double r; string s;
			cout << "Enter the direct debit reference: ";
			cin >> s;
			cout << "Enter the direct debit amount: ";
			cin >> r;

			mytrans->set_dd_details(r, s);

			return *mytrans;
		}
		else if (x == "TF")	//Transfer transaction initiated
		{
			Transfer* mytrans = new Transfer();
			cout << "A transfer transaction is initiated" << endl;
			double r; int p; string s;

			cout << "Enter your account number: ";
			cin >> p;
			cout << "Enter your sort code in the format XX-YY-ZZ: ";
			cin >> s;
			cout << "Enter the amount you will like to transfer: ";
			cin >> r;

			mytrans->set_tr_details(r, p, s);

			return *mytrans;
		}
		else if (x == "CR")	//Credit point transaction initiated
		{
			CreditPoint* mytrans = new CreditPoint();
			cout << "Credit point transaction initiated" << endl;
			double r; string s;

			cout << "Enter the type of payment used (cheque or cash): ";
			cin >> s;
			cout << "Enter the credit point amount: ";
			cin >> r;

			mytrans->set_cdp_details(r, s);
			return *mytrans;
		}
		else if (x == "IN")	//Interest transaction initiated
		{
			Interest* mytrans = new Interest();
			cout << "Interest transaction initiated" << endl;
			double r; string s;

			cout << "Enter the type of interest (daily, monthly or annual): ";
			cin >> s;
			cout << "Enter the interest amount: ";
			cin >> r;

			mytrans->set_int_details(r, s);
			return *mytrans;
		}
		else if (x == "Q")
		{
			break;
		}
		else {
			cout << "Incorrect transaction type selected. Kindly try gain" << endl;
		}
	} while (x != "DB" || "CP" || "DD" || "TF" || "CR" || "IN");
	
}

//Implementation of load from file function
void TransactionOwner::load(List& list)
{
	auto mystr = string{};
	string file_name;	//hold name of file
	string file_input;	//hold input from the file
	Transaction* myObj = NULL;
	cout << "Enter the file name containing transactions list to read transactions from (in the format name.txt): ";
	cin >> file_name;
	ifstream infile(file_name.c_str());	//file stream object to hold input file object
	if (infile.is_open())	//check if file is open
	{
		cout << "Reading transactions from file..." << endl;
		while (!infile.eof())	//check if end of file reached
		{
			getline(infile, file_input);	//read input from file
			auto iss = istringstream(file_input.c_str());	//string stream object to hold file input
			iss >> mystr;
			//check if end of file reached
			if (infile.eof()) { break; }
			
			//Conditional statements to create transaction object based on transaction type identified from file input
			if (mystr == "DB")
			{
				myObj = new Debit();
				myObj->loadfromfile(iss);
				list.add(*myObj);	//add created object to transaction list
			}
			else if (mystr == "CSP")
			{
				myObj = new CashPoint();
				myObj->loadfromfile(iss);
				list.add(*myObj);	//add created object to transaction list
			}
			else if (mystr == "CDP")
			{
				myObj = new CreditPoint();
				myObj->loadfromfile(iss);
				list.add(*myObj);	//add created object to transaction list
			}
			else if (mystr == "DD")
			{
				myObj = new DirectDebit();
				myObj->loadfromfile(iss);
				list.add(*myObj);	//add created object to transaction list
			}
			else if (mystr == "INT")
			{
				myObj = new Interest();
				myObj->loadfromfile(iss);
				list.add(*myObj);	//add created object to transaction list
			}
			else if (mystr == "TR")
			{
				myObj = new Transfer();
				myObj->loadfromfile(iss);
				list.add(*myObj);	//add created object to transaction list
			}
			else { cout << "Error reading details from file" << endl; }//output message if error encountered in reading objects
		}
		infile.close();	//close file after reading

		cout << "Done reading from file" << endl;
	}
	else { cout << "Unable to open file" << endl; }	//check if file not opened
}

//implementation of linear search function
void TransactionOwner::search(List& list)
{
	int low = 0, high = list.size() - 1;
	int position = low;
	int location = -1;
	
	int dd; string mnth; int yy;
	//collect date input from user
	cout << "Enter date for which you want to search for transactions" << endl;
	cout << "Enter day (dd) >> ";
	cin >> dd;
	cout << "Enter month (in the format - Jan, Feb, Mar, etc) >> ";
	cin >> mnth;
	cout << "Year (in the format 1990, 2020, etc) >> ";
	cin >> yy;

	//record start time
	clock_t begin_time = clock();

	//start searchinh
	do
	{
		//DateTime nextDateTime = transactions.get(position)->getDate();
		Transaction* objfrmList = list.getObj(position);
		if (objfrmList == 0) { return; }
		if (objfrmList->day == dd && objfrmList->month == mnth && objfrmList->year == yy) 
		{ 
			location = position; 
			cout << "Transaction found below.." << endl; 
		}
		else { position = position + 1; }
	} while ((position <= high) && (location == -1));

	clock_t end_time = clock();	//record end time

	
	//check if transaction is present in list
	if (location == -1)
	{
		cout << "Transaction does not exist in list" << endl;
		return;
	}

	list.getObj(location)->printout();	//display result found if transaction is contained in list

	//print out total time to search
	cout << "Time taken to search transaction list = " << float(end_time - begin_time) / CLOCKS_PER_SEC << " seconds" << endl;
	cout << "Searching complete!" << endl;
}

//Implementation of sort list function
void TransactionOwner::sortlist(List& list)
{
	//record start time
	clock_t begin_time = clock();

	for (int spa = list.size() / 2; 0 < spa; spa /= 2)
	{
		for (int a = spa; a < list.size(); a++)
		{
			for (int b = a - spa; 0 <= b; b -= spa)
			{
				Transaction* firstObj = list.getObj(b+spa);	//get object after current in transaction list to compare
				Transaction* secondObj = list.getObj(b);	//get current object in transaction list to compare
				
				

				if ( this->dateCompare(firstObj, secondObj) > 0)
				{
					Transaction* temp = list.getObj(b + spa);
					list.setObjLoc(b + spa, list.getObj(b));
					list.setObjLoc(b, temp);
				}
			}
		}
	}
	clock_t end_time = clock();	//record end time
	cout << "Sorting complete!" << endl;
	//print out total time to search
	cout << "Time taken to sort transaction list = " << float(end_time - begin_time) / CLOCKS_PER_SEC << " seconds" << endl;
	cout << "You can select the display option to see the contents of the sorted list" << endl;
}

//definition of function to convert month string to num
int TransactionOwner::converMnthtoNum(string str)
{
	string month[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	for (int i = 0; i < 12; i++)
	{
		if (month[i] == str)
		{
			return i + 1;
		}
	}
	return -1;
}

//definition of function to compare two dates
int TransactionOwner::dateCompare(Transaction* firstObj, Transaction* secondObj)
{
	int dd; string mnth; int yy; int month_num;	//declare variables to hold date info from one object
	int dd_1; string mnth_1; int yy_1; int month_num_1;	//declare variables to hold date from second object

	dd = firstObj->day; mnth = firstObj->month; month_num = this->converMnthtoNum(mnth); yy = firstObj->year;
	dd_1 = secondObj->day; mnth_1 = secondObj->month; month_num_1 = this->converMnthtoNum(mnth); yy_1 = secondObj->year;

	if (yy > yy_1) { return 1; }
	else if (yy < yy_1) { return -1; }

	if (month_num > month_num_1) { return 1; }
	else if (month_num < month_num_1) { return -1; }

	if (dd > dd_1) { return 1; }
	else if (dd < dd_1) { return -1; }
	
	return 0;
}