#include "Customer.h"
#include <string>
#include <vector>
#include <algorithm>
//#include <istream>
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
std::istream& operator>>(std::istream& is, Customer& other) {

    std::cout << "CID: ";
    is >> other.CID;

    std::cout << "UserName: ";
    is >> other.Username;

    std::cout<< "Name: ";
    is >> other.Name;

    std::cout<< "Password: ";
    is >> other.Password;


    std::cout << "Account Type: ";
    is >> other.AccType;

    std::cout << "Organization: ";
    is >> other.Org;

    std::cout << "Status: ";
    is >> other.Status;

    std::cout << "DOB: ";
    is >> other.DOB;

    std::cout << "DOJ: ";
    is >> other.DOJ;

    std::cout << "SSN: ";
    is >> other.SSN;

    std::cout << "Current Balance: ";
    is >> other.current_balance;

    return is;
}

      


//**************************************************
//**************************************************
//**************************************************
//**************************************************
//**************************************************
//DEFUNCT CODE BELOW TO BE DELETED ONCE PROOVEN EVERYTHING WOKRS SUFFICIENTLY AFTER FULL REPLACEMENT

//bool customer_signup() {
//
//    long CID;
//    string Username, Name, AccType, Org, Status, DOB, DOJ, Password;
//    long SSN;
//    do {
//        system("cls");
//        cout << "Enter Customer Username: " << endl;
//        cin >> Username;
//        cin.ignore();
//        cout << "Enter Name: " << endl;
//        cin >> Name;
//        cin.ignore();
//        cout << "Enter Account Type(B/P): " << endl;
//        cin >> AccType;
//        cin.ignore();
//        cout << "Enter Organization: " << endl;
//        cin >> Org;
//        cin.ignore();
//        //cout << "Enter DOB: " << endl;
//        //cin >> string Status;                //<<set by bank
//        //cin.ignore();
//        cout << "Enter Date of Birth: " << endl;
//        cin >> DOB;
//        cin.ignore();
//        //cout << "Enter Date of Join: " << endl;
//        //cin >> string DOJ;                  //set to current date
//        //cin.ignore();
//        cout << "Enter Social Security Number: " << endl;
//        cin >> SSN;
//        cin.ignore();
//        cout << "Enter Password: " << endl;
//        cin >> Password;
//        cin.ignore();
//        //should be searchable somehow
//    } while (Username.size() <= 3 && Name.size() <= 3 && DOB.size() <= 3);
//    user_pass.push_back({ Username,Password });
//    usersnum++;
//
//    long ID = 2345234;
//    string status_temp = "temporary status";
//    string JOB = "temporary date of start";
//    pausebefore();
//   
//    Customer* person = new Customer(ID, Username, Name, AccType, Org, status_temp, DOB, JOB, SSN, Password);
//    collection->Insert(person, collection->root);
//   
//
//    //**************************************************************************************************
//    //**************************************************************************************************
//    //whats this,  this is incomplete code?!?!?!?!??!?!
//    //fix it
//    if (true) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}