#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include <iostream>
//#include <istream>
#include "TablePrinter.h"

using namespace std;

class Customer {

private:
    


    

	public:
        //TODO convert to int CID MAYBE, add to private
        long CID;

        void Save_Encode_File1(fstream& data);
        string Hash_Encoder(string input);
        string Hash_Decoder(string input);
        Customer* Load_Decode_File1(fstream& data);
        int shift;
        //TODO convert to private
        string AccType;

        //TODO convert to private
        string Org;

        //TODO convert to private
        string Status;

        //TODO convert to private
        string DOB;

        //TODO convert to private
        string DOJ;
        //TODO convert to int SSN MAYBE, add to private
        long SSN;
        //TODO convert to private
        string Username; // so this is accessible

        //TODO convert to private
        string Name;
        //TODO convert to private
        string Password;  // so this is easilly accessible,  but probably should be private
		//constructors
        // uh oh these tables can't just be
        //TO DO CONVERT ACCOUNT_STATUS TO PRIVATe, make it a vector of floats, and rename to transactions
        vector<long> account_status;     // a table of transactions
        //TO DO CONVERT TO PRIVATE and INT
        long current_balance;     //sum of all transactions


        //TO DO IMPLEMENT:
        string showInboxMessages(int n);


        //TO DOCONVERT to private, rename to messages
        vector<string> Inbox;
		Customer();
        //TO DO MAKE SURE CONSTRUCTOR FORMAT INCLUDES ALL THESE ARGS:
        //    customer(CID, SSN, Username, Name, Account Type, Organization, Status, DOB, DOJ, Password);
        Customer(long id, string user, string nam, string acc, string organ, string stat, string birth, string job, long social, string pass);
		~Customer();

        //mutators
        //TO DO OPTIONAL:  SPLIT TRANSACTION INTO WITHDRAWAL, DEPOSIT, TRANSFER, change to floats as well with outputs of floats
        //    float withdrawal(float);
        //float depositfloat;
        //float transfer(float, int CID);
        void transaction(long credit_debit);    //addjusts account_status by adding a new negative
        void summate(long ite);

        //TO DO implement this function below or change other function to more closely match this function:
        string lastNTransactions(int N);

        // or positive entry
        //accessors
        long balance();  // returns current balance or a transaction from account_status vector

        void DisplayCustomerInformation() const;
        void DisplayTransactionsTable() const;
        void DisplayMessagesTable() const;


        bool operator <(Customer& const other);
        bool operator >(Customer& const other);
        bool operator ==(Customer& const other);
        friend ostream& operator<<(ostream& out, const Customer& other);
        friend istream& operator>>(istream& in, Customer& other);



        void TransfertootherCID();
        void StatementsummarylastNtransactions();
        void CurrentBalance();
        void Withdraw();
        void Deposit();
        void CheckInbox();

};

#endif

