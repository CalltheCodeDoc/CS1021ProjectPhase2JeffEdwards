#include "Customer.h"
#include <string>
#include <vector>
#include <algorithm>
#include <istream>
#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
//default constructor
Customer::Customer() {
    CID = 0;
    Username = "";
    Name = "";
    AccType = "";
    Org = "";
    Status = "";
    DOB = "";
    DOJ = "";
    SSN = 000000000;
    Password = "";
}

//
Customer::Customer(long id, string user, string nam, string acc, string organ, string stat, string birth, string job, long social, string pass)
{
    CID = id;
    Username = user;
    Name =nam;
    AccType = acc;
    Org = organ;
    Status = stat;
    DOB = birth;
    DOJ = job;
    SSN = social;
    Password = pass;
    current_balance = 0;
    transaction(0);
}


Customer::~Customer() {
    //delete* this;
}



void Customer::DisplayCustomerInformation() const{
    std::vector<std::string> headers = { "CID", "Username", "Name", "Acc. Type", "Org.","Status", "DOB", "DOJ", "SSN", "Password"};
   
    std::vector<std::vector<std::string>> data = {
        {to_string(CID), Username, Name, AccType, Org, Status, DOB, DOJ, to_string(SSN), Password}
        //{"Longer Value 1", "Longer Value 2", "Longer Value 3"},
        //{"Short 1", "Short 2", "Short 3"},
    };

    TablePrinter table(headers, data);
    table.displayTable();
}
void Customer::DisplayTransactionsTable()const{

    std::vector<std::string> headers = { };
    //does empty vector work as such here?
    std::vector<std::vector<std::string>> data = {
        {}
        //{"Longer Value 1", "Longer Value 2", "Longer Value 3"},
        //{"Short 1", "Short 2", "Short 3"},
    };
    if (account_status.size() > 0) {
        for (int i = 0; i < account_status.size(); i++) {
            headers.push_back("Transaction ");
            data[0].push_back(to_string(account_status[i]));
        }
    }
    else {
        headers.push_back("No Transactions");
        data.push_back({ "0" });
    }

    TablePrinter table(headers, data);
    table.displayTable();
}
void Customer::DisplayMessagesTable()const{
    std::vector<std::string> headers = { };
    //does empty vector work as such here?
    std::vector<std::vector<std::string>> data = {
        {}
        //{"Longer Value 1", "Longer Value 2", "Longer Value 3"},
        //{"Short 1", "Short 2", "Short 3"},
    };
    if (Inbox.size() > 0) {
        for (int i = 0; i < Inbox.size(); i++) {
            headers.push_back("Transaction ");
            data[0].push_back(Inbox[i]);
        }
    }
    else {
        headers.push_back("No Messages");
        data[0].push_back({"Check again another time"});
    }
    TablePrinter table(headers, data);
    table.displayTable();
}

void Customer::transaction(long credit_debit) {
    account_status.push_back(credit_debit);
}

void Customer::summate(long ite) {
    current_balance += ite;

}

long Customer::balance() {
    //return accumulate(account_status.begin(), account_status.end(), 0);
    current_balance = 0;
    if (account_status.size() == 0) {
        return current_balance;
    }
    else {
        for (int k = 0; k < account_status.size(); k++) {
            //current_balance += account_status[k];
            summate(account_status[k]);
        }
    }
        
    return current_balance;
}

bool Customer::operator <(Customer& const other) {
    if (CID < other.CID) {
        return true;
    }
    else
    {
        return false;
    }
}

bool Customer::operator >(Customer& const other) {
    if (CID > other.CID) {
        return true;
    }
    else {
        return false;
    }
}


bool Customer::operator ==(Customer& const other) {
    if (CID == other.CID)
        return true;
    else
        return false;
}
ostream& operator <<(ostream& out, const Customer& other) {
    out << "CID: " << other.CID << "\nUserName: " << other.Username << "\nAccount Type: " << other.AccType << "\nOrganization: " << other.Org << "\nStatus: " << other.Status << "\nDOB: " << other.DOB << "\nDOJ: " << other.DOJ << "\nSSN: " << other.SSN << "\nCurrent Balance: " << other.current_balance << endl;
    return out;
}
/*
istream& operator >>(istream& in, const Customer& other) {
    cout << "CID: ";
    in >> other.CID;
    >> "\nUserName: " >> other.Username >> "\nAccount Type: " >> other.AccType >> "\nOrganization: " >> other.Org >> "\nStatus: " >> other.Status >> "\nDOB: " >> other.DOB >> "\nDOJ: " >> other.DOJ >> "\nSSN: " >> other.SSN >> "\nCurrent Balance: " >> other.current_balance >> endl;
    return in;
}
*/
std::istream& operator>>(std::istream& in, Customer& other) {
    std::cout << "CID: ";
    in >> other.CID;

    std::cout << "UserName: ";
    in >> other.Username;

    std::cout << "Account Type: ";
    in >> other.AccType;

    std::cout << "Organization: ";
    in >> other.Org;

    std::cout << "Status: ";
    in >> other.Status;

    std::cout << "DOB: ";
    in >> other.DOB;

    std::cout << "DOJ: ";
    in >> other.DOJ;

    std::cout << "SSN: ";
    in >> other.SSN;

    std::cout << "Current Balance: ";
    in >> other.current_balance;

    return in;
}

      