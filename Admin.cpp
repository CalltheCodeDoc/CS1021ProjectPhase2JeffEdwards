#include "Admin.h"


Admin::Admin(){
    //default admin
    Username="admin";
    Password="password";

}
Admin::Admin(long CIDarg, long SSNarg, string Usernamearg, string Namearg, string Rankarg, string Organizationarg, string Statusarg, string DOBarg, string DOJarg, string Passwordarg){
    CID=CIDarg;
    SSN=SSNarg;

    //string 
    Username=Usernamearg;
    Name=Namearg;
    Rank=Rankarg;
    Organization=Organizationarg;
    Status=Statusarg;
    DOB=DOBarg;
    DOJ=DOJarg;
    Password=Passwordarg;

}
float Admin::payInterest(vector<Customer*> posi, float interestrate) { 
    
    float tem_bal;
    cout << "Crediting accounts with interest accumulate for the month:\n";
    for (int k = 0; k < posi.size(); k++) {
        tem_bal = posi[k]->current_balance * interestrate;
        cout << "Username: " << posi[k]->Username << " " << "Name: " << posi[k]->Name << " Balance: " << posi[k]->current_balance << " Interest is : " << tem_bal;
        posi[k]->current_balance += tem_bal;
        cout << " New balance is: " << posi[k]->current_balance << endl;
        posi[k]->DisplayTransactionsTable();
    }
    return 0;
}

float Admin::checkNegativeBalance(vector<Customer*> nega, int CID) { 
    cout << "checking accounts with negative balances: \n";
    for (int k = 0; k < nega.size(); k++) {

        nega[k]->DisplayCustomerInformation();
        nega[k]->DisplayTransactionsTable();
        //cout << "Username: " << nega[k]->Username << " " << "Name: " << nega[k]->Name << " Balance: " << nega[k]->current_balance << endl;
    }
    return 0;
}

float Admin::checkPositiveBalance(vector<Customer*> posi, int CID) { 
    
    cout << "checking accounts with positve balances: \n";
    for (int k = 0; k < posi.size(); k++) {
       
        posi[k]->DisplayCustomerInformation();
        posi[k]->DisplayTransactionsTable();
        //cout << "Username: " << posi[k]->Username << " " << "Name: " << posi[k]->Name << " Balance: " << posi[k]->current_balance << endl;
    }
    return 0;
}

float Admin::blockNegativeAccount(vector<Customer*> nega, int CID) { 
    
    //delete account maybe
    // 
        //Customer* searchcollection(bool negpos)
    cout << "Do you want to block accounts that have multiple warning messages?" << endl;
    cout << "Type Y for yes" << endl;
    string block;
    cin >> block;
    cin.ignore();
    if (block == "Y") {
        for (int k = 0; k < nega.size(); k++) {
            if (nega[k]->Inbox.size() >= 1) {
                nega[k]->Inbox.push_back("Your account has been blocked");
                nega[k]->current_balance = 0;
                nega[k]->Password = "CANT NOT LOG IN NOW";
                cout << nega[k]->Username << " has been blocked" << endl;
            }
        }
    }
    //function to disable pass or something;

    return 0;
}
float Admin::generateSummaryReport(vector<Customer*> posi, vector<Customer*> nega, BinarySearchTree<Customer>* collection) {
    
    //
    cout << endl << "******Summary Report******: " << endl << collection->size << endl;
    cout << endl << "Total Customers are: " << endl << collection->size << endl;
    cout << "Accounts with positve balances: \n";
    for (int k = 0; k < posi.size(); k++) {
        //cout << "Username: " << posi[k]->Username << " " << "Name: " << posi[k]->Name << " Balance: " << posi[k]->current_balance << endl;
        posi[k]->DisplayCustomerInformation();
        posi[k]->DisplayTransactionsTable();
    
    }
    cout << "Accounts with negative balances: \n";
    for (int k = 0; k < nega.size(); k++) {
        //cout << "Username: " << nega[k]->Username << " " << "Name: " << nega[k]->Name << " Balance: " << nega[k]->current_balance << endl;
        nega[k]->DisplayCustomerInformation();
        nega[k]->DisplayTransactionsTable();
    
    }

    //CALLLLLLLLLLLLL
    //DISPLAY FUNCTIONS HERE
    //REPEATEDLY
    
    return 0; 
}





void Admin::Warningmessagesto_neg_vebalanceaccounts(vector<Customer*> nega) {
    //leaves a message that customer can read in check inbox function
        //Customer* searchcollection(bool neg)
    cout << "Do you want to leave a warning message for negative balance accounts?" << endl;
    cout << "Type Y for yes" << endl;
    string warning;
    cin >> warning;
    cin.ignore();
    if (warning == "Y") {
        for (int k = 0; k < nega.size(); k++) {
            nega[k]->Inbox.push_back("This is a warning, you have a negative balance");
        }
    }
    //then function to add inbox;
}


string Admin::GetUsername(){

       return Username;

}
string Admin::GetPassword(){

       return Password;

}






//************************************
//below is junk code that will be deleted granted everything works well
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
//bool admmatch(string usar, string passs) {
//    if (usar == admin_user && passs == admin_pass) {
//        cout << endl << "Sign in Successful" << endl;
//        return true;
//    }
//    else {
//        return false;
//    }
//}

//**************************************************************
//functions:
//***************************************************************
// 
// ********************
//admin page functions
//*********************
/*
void PayMonthlyInterest() {
    long tem_bal;
    cout << "Crediting accounts with interest accumulate for the month:\n";
    for (int k = 0; k < posi.size(); k++) {
        tem_bal = posi[k]->current_balance * .07;
        cout << "Username: " << posi[k]->Username << " " << "Name: " << posi[k]->Name << " Balance: " << posi[k]->current_balance << " Interest is : " << tem_bal;
        posi[k]->current_balance += tem_bal;
        cout << " New balance is: " << posi[k]->current_balance << endl;
    }

}
void Checkaccountwith_neg_vebalance() {
    //create a list of all accounts with negative balances
        //include name, and balance in table
       // Customer* searchcollection(bool neg)

    cout << "checking accounts with negative balances: \n";
    for (int k = 0; k < nega.size(); k++) {
        cout << "Username: " << nega[k]->Username << " " << "Name: " << nega[k]->Name << " Balance: " << nega[k]->current_balance << endl;
    }

}
void Checkaccountwith_pos_vebalances() {
    //create a list of all accounts with positive balances
    //include name, and balance in table
    //should be able to look at their information
    //Customer* searchcollection(bool pos)
    cout << "checking accounts with positve balances: \n";
    for (int k = 0; k < posi.size(); k++) {
        cout << "Username: " << posi[k]->Username << " " << "Name: " << posi[k]->Name << " Balance: " << posi[k]->current_balance << endl;
    }
}
void Warningmessagesto_neg_vebalanceaccounts() {
    //leaves a message that customer can read in check inbox function
        //Customer* searchcollection(bool neg)
    cout << "Do you want to leave a warning message for negative balance accounts?" << endl;
    cout << "Type Y for yes" << endl;
    string warning;
    cin >> warning;
    cin.ignore();
    if (warning == "Y") {
        for (int k = 0; k < nega.size(); k++) {
            nega[k]->Inbox.push_back("This is a warning, you have a negative balance");
        }
    }
    //then function to add inbox;
}
void Repeated_neg_vebalance_Blockaccount() {
    //delete account maybe
    //
        //Customer* searchcollection(bool negpos)
    cout << "Do you want to block accounts that have multiple warning messages?" << endl;
    cout << "Type Y for yes" << endl;
    string block;
    cin >> block;
    cin.ignore();
    if (block == "Y") {
        for (int k = 0; k < nega.size(); k++) {
            if (nega[k]->Inbox.size() >= 1) {
                nega[k]->Inbox.push_back("Your account has been blocked");
                nega[k]->current_balance = 0;
                nega[k]->Password = "CANT NOT LOG IN NOW";
                cout << nega[k]->Username << " has been blocked" << endl;
            }
        }
    }
    //function to disable pass or something;
}
*/
//******************************************************************************************************************
//*****************************************************************************************************************
//most above admins functions can be deleted when they have been replaced by their class implementation
//*******************************************************************************************************************
//********************************************************************************************************************


/*
void GeneratesummaryReport() {
    //
    cout << endl << "******Summary Report******: " << endl << collection->size << endl;
    cout << endl << "Total Customers are: " << endl << collection->size << endl;
    cout << "Accounts with positve balances: \n";
    for (int k = 0; k < posi.size(); k++) {
        cout << "Username: " << posi[k]->Username << " " << "Name: " << posi[k]->Name << " Balance: " << posi[k]->current_balance << endl;
    }
    cout << "Accounts with negative balances: \n";
    for (int k = 0; k < nega.size(); k++) {
        cout << "Username: " << nega[k]->Username << " " << "Name: " << nega[k]->Name << " Balance: " << nega[k]->current_balance << endl;
    }
}
*/