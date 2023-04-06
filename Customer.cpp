#include "Customer.h"
#include <string>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>

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

/*
Customer::~Customer() {
    delete* this;
}*/

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
