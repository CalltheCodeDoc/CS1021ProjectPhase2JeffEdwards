#include "Customer.h"
#include <string>
#include <vector>
#include <algorithm>
//#include <istream>
#include <iostream>
//#include <bits/stdc++.h>
#include <typeinfo>
#include <sstream>
#include <type_traits>
#include <fstream>


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
    current_balance = 0;
    Password = "";
    shift = 55;
    transaction(0);
}

//
Customer::Customer(long id, string user, string nam, string acc, string organ, string stat, string birth, string job, long social, string pass)
{
    shift = 55;
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

string Customer::Hash_Encoder(string input) {
    //caeser encoding
    string temp;
    for (auto x : input) {

        temp.push_back((x + shift) % 256);
    }
    return temp;
}

string Customer::Hash_Decoder(string input) {
    //ceaser decoding
    string temp;
    for (auto x : input) {

        temp.push_back((x + (256-shift)) % 256);
    }
    return temp;
}


//**************************************************************************************************************
//**************************************************************************************************************
//**************************************************************************************************************
//**************************************************************************************************************
//**************************************************************************************************************
//**************************************************************************************************************
//HUGE PROBLEM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! HUGE PROBLEM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//  HUGE PROBLEM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! HUGE PROBLEM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//  HUGE PROBLEM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! HUGE PROBLEM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                                  THIS CODE DOES NOT RECORD VECTOR DATA AND INBOX DATA AND TRANSACTION DATA
//                                  THIS CODE DOES NOT RECORD VECTOR DATA AND INBOX DATA AND TRANSACTION DATA
//************************************************************************************************************
//************************************************************************************************************
//************************************************************************************************************
//************************************************************************************************************
//************************************************************************************************************



//********************************************************************************
//Okay it half works!!!!!!
//it loads 3 of the customers
//but fails 2 of the customers


Customer* Customer::Load_Decode_File1(fstream& data) {

    if (!data) {
        cout << "Unable to open file" << endl;
    }
    else {

        Customer* person = new Customer();
        string temp;
        string temp2;
        string temp3;
        bool TERMINATION_CONDITION;
        int count=0;

        while (data) {
            getline(data, temp);
            //this if condition might be problematic and not work as intended
            /*if ((temp==" "|| temp =="/n")&&(count>15||count==0 )) {
                TERMINATION_CONDITION = true;
                return nullptr;
                break;
            }*/
            if(temp[0] == Hash_Encoder("CID: ")[0] && temp[1] == Hash_Encoder("CID: ")[1] && temp[2] == Hash_Encoder("CID: ")[2]) {
                getline(data, temp2);
                temp3 = Hash_Decoder(temp2);
                person->CID = (long)stoi(temp3);
                count++;
                if (count == 11) {
                    break;
                }
            }
            else if (temp == Hash_Encoder("Name: ")) {

                getline(data, temp2);
                temp3 = Hash_Decoder(temp2);
                person->Name = temp3;
                count++;
                if (count == 11) {
                    break;
                }
            }
            else if (temp == Hash_Encoder("UserName: ")) {
                getline(data, temp2);
                temp3 = Hash_Decoder(temp2);
                person->Username = temp3;
                count++;
                if (count == 11) {
                    break;
                }
            }
            else if (temp == Hash_Encoder("Account Type: ")) {
                getline(data, temp2);
                temp3 = Hash_Decoder(temp2);

                person->AccType = temp3;
                count++;
                if (count == 11) {
                    break;
                }
            }
            else if (temp == Hash_Encoder("Organization: ")) {
                getline(data, temp2);
                temp3 = Hash_Decoder(temp2);
                person->Org = temp3;
                count++;
                if (count == 11) {
                    break;
                }
            }
            else if (temp == Hash_Encoder("Status: ")) {
                getline(data, temp2);
                temp3 = Hash_Decoder(temp2);
                person->Status = temp3;
                count++;
                if (count == 11) {
                    break;
                }
            }
            else if (temp == Hash_Encoder("DOB: ")) {
                getline(data, temp2);
                temp3 = Hash_Decoder(temp2);
                person->DOB = temp3;
                count++;
                if (count == 11) {
                    break;
                }
            }
            else if (temp == Hash_Encoder("DOJ: ")) {
                getline(data, temp2);
                temp3 = Hash_Decoder(temp2);
                person->DOJ = temp3;
                count++;
                if (count == 11) {
                    break;
                }
            }
            else if (temp == Hash_Encoder("SSN: ")) {
                getline(data, temp2);
                temp3 = Hash_Decoder(temp2);
                person->SSN = (long)stoi(temp3);
                count++; 
                if (count == 11) {
                    break;
                }
            }
            else if (temp == Hash_Encoder("Current Balance: ")) {
                getline(data, temp2);
                temp3 = Hash_Decoder(temp2);
                person->current_balance = (long)stoi(temp3);
                count++; 
                if (count == 11) {
                    break;
                }
            }
            else if (temp == Hash_Encoder("Password: ")) {
                getline(data, temp2);
                temp3 = Hash_Decoder(temp2);
                person->Password = temp3;
                count++;
                if (count == 11) {
                    break;
                }
            }
            if (count==11) {
                break;
            }
            if ((temp[0] == ' ' || temp[0] == '/n')) {
                return nullptr;
            }
            


        }
        return person;
    }
}





void Customer::Save_Encode_File1(fstream& data) {
   
    if (!data) {
        cout << "Unable to open file" << endl;
    }
    else {
     
           
  
                //std::ostringstream oss;
                std::string stringify;
                //oss << temp->CID;
                stringify = to_string(CID);
                //stringify = oss.str();

                data << Hash_Encoder("CID: ") << endl << Hash_Encoder(stringify) << endl;
                stringify = Name;
                data << Hash_Encoder("Name: ") << endl << Hash_Encoder(stringify) << endl;
                stringify = Username;
                data << Hash_Encoder("UserName: ") << endl << Hash_Encoder(stringify) << endl;
                stringify = AccType;
                data << Hash_Encoder("Account Type: ") << endl << Hash_Encoder(stringify) << endl;
                stringify = Org;
                data << Hash_Encoder("Organization: ") << endl << Hash_Encoder(stringify) << endl;
                stringify = Status;
                data << Hash_Encoder("Status: ") << endl << Hash_Encoder(stringify) << endl;
                stringify = DOB;
                data << Hash_Encoder("DOB: ") << endl << Hash_Encoder(stringify) << endl;
                stringify = DOJ;
                data << Hash_Encoder("DOJ: ") << endl << Hash_Encoder(stringify) << endl;
                //oss << temp->SSN;
                stringify = to_string(SSN);
                //stringify = oss.str();
                data << Hash_Encoder("SSN: ") << endl << Hash_Encoder(stringify) << endl;
                //oss << temp->current_balance;
                stringify = to_string(current_balance);
                //stringify = oss.str();
                data << Hash_Encoder("Current Balance: ") << endl << Hash_Encoder(stringify) << endl;
                stringify = Password;
                data << Hash_Encoder("Password: ") << endl << Hash_Encoder(stringify) << endl;
                data << endl;
            }

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

      
void Customer::TransfertootherCID() {
    //not yet implemented
    cout << "This feature is not yet implemented" << endl;
}

void Customer::StatementsummarylastNtransactions() {
    //just display up to last 5 transactions
    DisplayTransactionsTable();
    //Old code below
    /*if (account_status.size() == 0) {
        cout << " You have made no transactions as of yet" << endl;
    }
    else {
        for (int k = 0; k < account_status.size(); k++) {
            cout << "Transaction _______ PLACE HOLDER SHOULD PUT DATE: $" << account_status[k] << endl;
        }
    }*/
    
}

void Customer::CurrentBalance() {

    cout << "Your Current balance is: " << balance() << endl;
    
}
void Customer::Withdraw() {
    //decrease balance
    //lower balance sheet
    //message the ammount
    //perhaps dont allow to go negative
    long amount;
    cout << "How much would you like to withdraw from the bank?" << endl;
    //do {
    cin >> amount;
    cin.ignore();
    //} while (!isdigit(amount));
    transaction(-1 * amount);

    //**********************************************************************************
    //TO DO, add a 2-d transaction that includes description of type of transaction
    //**********************************************************************************
    
}
void Customer::Deposit() {
    //increase balance
        //also add to balance sheet
        //message the ammount
    long amount;
    cout << "How much would you like to deposit into the bank?" << endl;
    //do {
    cin >> amount;
    cin.ignore();
    //} while (!isdigit(amount));
    transaction(amount);
    //**********************************************************************************
    //TO DO, add a 2-d transaction that includes description of type of transaction
    //**********************************************************************************
    
}

void Customer::CheckInbox() {
    //warning for negative balance can be read here 
    cout << endl;
    cout << "Opening Inbox" << endl;
    cout << "Messages: " << endl;
    if (Inbox.size() != 0) {
        for (int i = 0; i < Inbox.size(); i++) {
            cout << Inbox[i] << endl;  //size of should be vector dimensions
            //make sure there is a value and makesure use right size of function for vectors
        }
    }
    else {
        cout << "There are no Messages" << endl;
        
    }
}


//******************************            
//Customer page functions
//******************************


//void TransfertootherCID(Customer& persons) {}//**************************************
//
//
//
//void StatementsummarylastNtransactions(Customer& persons) {
//    //just display up to last 5 transactions
//    if (persons.account_status.size() == 0) {
//        cout << " You have made no transactions as of yet" << endl;
//    }
//    else {
//        for (int k = 0; k < persons.account_status.size(); k++) {
//            cout << "Transaction _______ PLACE HOLDER SHOULD PUT DATE: $" << persons.account_status[k] << endl;
//        }
//    }
//    //************************** NEED A PAUSE FUNCTION OR STUFF WONT SHOW
//}
//void CurrentBalance(Customer& persons) {
//
//    cout << "Your Current balance is: " << persons.balance() << endl;
//    pausebefore();
//}
//void Withdraw(Customer& persons) {
//    //decrease balance
//    //lower balance sheet
//    //message the ammount
//    //perhaps dont allow to go negative
//    long amount;
//    cout << "How much would you like to withdraw from the bank?" << endl;
//    //do {
//    cin >> amount;
//    cin.ignore();
//    //} while (!isdigit(amount));
//    persons.transaction(-1 * amount);
//    pausebefore();
//}
//void Deposit(Customer& persons) {
//    //increase balance
//        //also add to balance sheet
//        //message the ammount
//    long amount;
//    cout << "How much would you like to deposit into the bank?" << endl;
//    //do {
//    cin >> amount;
//    cin.ignore();
//    //} while (!isdigit(amount));
//    persons.transaction(amount);
//    pausebefore();
//}
//
//void CheckInbox(Customer& persons) {
//    //warning for negative balance can be read here 
//    cout << endl;
//    cout << "Opening Inbox" << endl;
//    cout << "Messages: " << endl;
//    if (sizeof(persons.Inbox) != 0) {
//        for (int i = 0; i < sizeof(persons.Inbox); i++) {
//            cout << persons.Inbox[i] << endl;  //size of should be vector dimensions
//            //make sure there is a value and makesure use right size of function for vectors
//        }
//    }
//    else {
//        cout << "There are no Messages" << endl;
//        pausebefore();
//    }
//}

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



        ////std::ostringstream oss;
        //std::string stringify;
        ////oss << temp->CID;
        //stringify = to_string(CID);
        ////stringify = oss.str();

        //data << Hash_Decoder("CID: ") << Hash_Decoder(stringify) << endl;
        //stringify = Name;
        //data << Hash_Decoder("Name: ") << Hash_Decoder(stringify) << endl;
        //stringify = Username;
        //data << Hash_Decoder("UserName: ") << Hash_Encoder(stringify) << endl;
        //stringify = AccType;
        //data << Hash_Decoder("Account Type: ") << Hash_Decoder(stringify) << endl;
        //stringify = Org;
        //data << Hash_Decoder("Organization: ") << Hash_Decoder(stringify) << endl;
        //stringify = Status;
        //data << Hash_Decoder("Status: ") << Hash_Decoder(stringify) << endl;
        //stringify = DOB;
        //data << Hash_Decoder("DOB: ") << Hash_Decoder(stringify) << endl;
        //stringify = DOJ;
        //data << Hash_Decoder("DOJ: ") << Hash_Decoder(stringify) << endl;
        ////oss << temp->SSN;
        //stringify = to_string(SSN);
        ////stringify = oss.str();
        //data << Hash_Decoder("SSN: ") << Hash_Decoder(stringify) << endl;
        ////oss << temp->current_balance;
        //stringify = to_string(current_balance);
        ////stringify = oss.str();
        //data << Hash_Decoder("Current Balance: ") << Hash_Decoder(stringify) << endl;
        //data << endl;

    //}

//}






    //data.close();


    //UMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM THIS SHOULDN'T APPEND IT SHOULD OVERWRITE
    //OTHERWISE it'll keep old accounts and make duplicates even after changes
    //but do keep a backupfile