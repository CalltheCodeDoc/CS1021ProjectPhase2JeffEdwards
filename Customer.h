#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>

using namespace std;

class Customer {

private:
    long CID;
    string AccType;
    string Org;
    string Status;
    string DOB;
    string DOJ;
    long SSN;


    

	public:
        string Username; // so this is accessible
     string Name;
        string Password;  // so this is easilly accessible,  but probably should be private
		//constructors
        // uh oh these tables can't just be
        vector<long> account_status;     // a table of transactions
        long current_balance;     //sum of all transactions
        vector<string> Inbox;
		Customer();
        Customer(long id, string user, string nam, string acc, string organ, string stat, string birth, string job, long social, string pass);
		~Customer();

        //mutators
        void transaction(long credit_debit);    //addjusts account_status by adding a new negative
        void summate(long ite);
        // or positive entry
        //accessors
        long balance();  // returns current balance or a transaction from account_status vector
};

#endif