#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Customer.h"
//#include "Shelf.h"
//#include "EntertainmentCollection.h"
//#include <fstream>
#include <chrono>
//#include <windows.h>
#include <fstream>
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include "NodeBST.h"
#include "NodeBST.cpp"
#include "Admin.h"
//#include <istream>



using namespace std;


//TODO:
//1)UPDATE INFORMATION STORAGE to be more in line with requirements
//
// 2) start receding a lot of code into background classes
//          that includes:
//                          cin overload, replace that call in this source file
//                                  it should transform like 15 lines of code into 2
//                          make default kwargs that take roots,  so user never has to input root, unless they wanna change it
//                              i think as long as root is a tree member and the method that calls it is also, jsut use this->root
// 
// 
//3)add encryption to file reading and writing
//4)   Make displays update informatoin,  HINT have to create dataobjects that reference the information not copy it
//
//5) make customers informatoin saved and updated and loaded from separate fileio object
// 
// 
// 
//6) MEMORY MANAGEMENT,  HAVE TO DELETE STUFF LOLLLL  YOU JUST CREATE AND LEAVE IT IGNORE
//
//7)  Need to fix all this unnecessary spiderweb of search code.  fold in a lot of this overhead code back into
//      the tree class,  and make it so that the tree class can be used to search for any data type
//      AND ALSO customer admin classes.    theres less need for this danglign variables and helped functions

//**************************************************************************
//must do flow chart
//**************************************************************************

//can I use function templates????

struct ADate {
    int  month;
    int  day;
    int  year;
};

//functions that display pages
char initial_welcome();
bool admin_sign();
bool cust_sign();
bool customer_signup();
char admin_route();
char customer_route();

//critical auxillary functions 
bool admmatch(string usar, string passs);
Customer* searchcollection(string namen);
void pausebefore();
void search_collect(bool negpos);

//admin page functions
void TotalCustomers();
void Totalactivecustomers();
void TotalInactivecustomers();
void Total_pos_vebalances();
void Total_neg_vebalances();
void Admin_Logout();

//customer page functions
void StatementsummarylastNtransactions(Customer& persons);
void CurrentBalance(Customer& persons);
void Withdraw(Customer& persons);
void Deposit(Customer& persons);
void TransfertootherCID(Customer& persons);
void CheckInbox(Customer& persons);
void Customer_Logout(Customer& persons);

vector<vector<string>> user_pass;   // each column represents a user, row 1 is username row2 is their password
int usersnum = 0;

Admin* admin = new Admin();
string admin_user = "admin";
string admin_pass = "password";

BinarySearchTree<Customer>* collection = new BinarySearchTree<Customer>();

vector<Customer*> nega;
vector<Customer*> posi;

Customer* aptr;   //pointer to customers information

bool cuyes;
bool adyes;




int main()
{
    system("color 0A");
    /*
    fstream data;
    data.open("BankCustomers.txt", ios::in);
    if (data.is_open()) {

            //MAKE FUNCTION HERE THAT READS AND DECODES HERE

        while (!data.eof()) {
            long CID;
            string Username;
            string Name;
            string AccType;
            string Org;
            string Status;
            string DOB;
            string DOJ;
            long SSN;
            string Password;
            data >> CID >> Username >> Name >> AccType >> Org >> Status >> DOB >> DOJ >> SSN >> Password;
            Customer* person = new Customer(CID, Username, Name, AccType, Org, Status, DOB, DOJ, SSN, Password);
            collection.addItem(person);
        }
    }
    data.close();
    fstream data;
    data.open("BankCustomers.txt", ios::out|ios::app);
    */

    Customer* person1 = new Customer((long)4737, "jeff", "JeffEdwards", "B", "UniCinci", "pos", "12251997", "01012020", 3543543, "jeff");
    Customer* person2 = new Customer((long)3646, "Ramona", "RamonaHucken", "B", "OSU", "neg", "7201999", "01012020", 757435, "ramona");
    Customer* person3 = new Customer((long)4564, "Sam", "SamAltman", "P", "OpenAi", "pos", "5202000", "01012020", 456456, "sam");
    Customer* person4 = new Customer((long)4564, "Obama", "BarackObama", "B", "Whitehouse", "neg", "1201960", "01012020", 4533463, "obama");
    Customer* person5 = new Customer((long)4547, "Abbian", "AbbianLaw", "P", "DeutscheBank", "pos", "8032002", "01012020", 3536363, "abbian");
    person1->transaction(55);
    person1->transaction(100);
    person1->transaction(10000);
    person2->transaction(8008);
    person3->transaction(1337);
    person4->transaction(-5);
    person4->transaction(-500);
    person4->transaction(454);
    person5->transaction(-10);
    person4->transaction(999);
    person5->transaction(-100);
    person2->transaction(5000);
    person1->balance();
    person2->balance();
    person3->balance();
    person4->balance();
    person5->balance();
    //Insert(T * inval, Node<T>*parent);
    collection->Insert(person1, collection->root);
    collection->Insert(person2, collection->root);
    collection->Insert(person3, collection->root);
    collection->Insert(person4, collection->root);
    collection->Insert(person5, collection->root);
    
    //if (data.is_open()) {
    // 
    //          //  MAKE FUNCTION THAT ENCRYPTS HERE AND ALSO WRITES TO FILE
    // 
    //    for (int i = 0; i < collection.size(); i++) {
    //		data << collection[i]->getCID() << " " << collection[i]->getUsername() << " " << collection[i]->getName() << " " << collection[i]->getAccType() << " " << collection[i]->getOrg() << " " << collection[i]->getStatus() << " " << collection[i]->getDOB() << " " << collection[i]->getDOJ() << " " << collection[i]->getSSN() << " " << collection[i]->getPassword() << endl;
    //	}
    //}
    //spoof fake customers for bank database


    //********************************************************************************************************
    search_collect(true);
    search_collect(false);
    /*int CID[];string Username[];string Name[]; string AccType[];string Org[];string Status[]; string DOB[];string DOJ[];long SSN[];string Password[];
    */

    //display WORKS!!!!  YAYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
    //posi[0]->DisplayCustomerInformation();
    //posi[0]->DisplayTransactionsTable();
    //posi[0]->DisplayMessagesTable();

    //variables to handle cycling of menus
    char first_page_option;
    char customer_or_admin;
    bool admin_success = false;
    bool customer_success = false;
    bool signup_success = false;
    char admin_choice;
    char customer_choice;
    bool logout = true;

    while (logout) {
        do {

            //welcome menu,   choose 1 2 3 or 4       
            first_page_option = initial_welcome();

        } while (first_page_option != '1' && first_page_option != '2' && first_page_option != '3' && first_page_option != '4');

        switch (first_page_option)
        {
        case '1':
            do {
                //ADMIN SIGN IN FUNCTION
                //uses recurssion
                // if username and password match then returns true and allows next step
                // if no match then loops to this step
                //ADMIN PASSWORD SIGN IN
                admin_success = admin_sign();
                //while loop is unnecessary with recursion
            } while (!admin_success);
            customer_or_admin = 'a';
            break;
        case '2':
            do {
                //CUSTOMER SIGN IN FUNCTION
                //returns true if success, store in a variable to give access to any customer sign in options
                //returns false which leads to recursion
                //perhaps leave an option to exit

                customer_success = cust_sign();

                //while loop is unnecessary with recursion
            } while (!customer_success);
            customer_or_admin = 'c';
            break;
        case '3':
            do {

                signup_success = customer_signup();
            } while (!signup_success);
            customer_or_admin = 'c';
            break;
        case '4':
            logout = false;
            break;
        }
        if (!logout) {
            break;
        }

        switch (customer_or_admin)
        {
        case 'a':
            adyes = true;
            do {
                do {
                    admin_choice = admin_route();
                } while (admin_choice != '1' && admin_choice != '2' && admin_choice != '3' && admin_choice != '4' && admin_choice != '5' && admin_choice != '6' && admin_choice != '7');


                switch (admin_choice) {
                case '1':
                    admin->payInterest(posi, 0.07);
                    break;
                case '2':
                    admin->checkNegativeBalance(nega, 909);
                    break;
                case '3':
                    admin->checkPositiveBalance(posi, 909);
                    break;
                case '4':
                    admin->Warningmessagesto_neg_vebalanceaccounts(nega);
                    break;
                case '5':
                    admin->blockNegativeAccount(nega, 909);
                    break;
                case '6':
                    admin->generateSummaryReport(posi, nega, collection);
                    break;
                    //TotalCustomers();
                    //Totalactivecustomers();
                    //TotalInactivecustomers();
                    //Total_pos_vebalances();
                    //Total_neg_vebalances();
                case '7':
                    Admin_Logout();
                    adyes = false;
                    //logout = false;
                }
                //below should be put within a switch case within the above switch case
            } while (adyes);
        case 'c':
      

            do {
                do {
                    customer_choice = customer_route();
                } while (customer_choice != '1' && customer_choice != '2' && customer_choice != '3' && customer_choice != '4' && customer_choice != '5' && customer_choice != '6' && customer_choice != '7');

                switch (customer_choice) {
                case '1':
                    StatementsummarylastNtransactions(*aptr);
                    break;
                case '2':
                    CurrentBalance(*aptr);
                    break;
                case '3':
                    Withdraw(*aptr);
                    break;
                case '4':
                    Deposit(*aptr);
                    break;
                case '5':
                    TransfertootherCID(*aptr);
                    break;
                case '6':
                    CheckInbox(*aptr);
                    break;
                case '7':
                    Customer_Logout(*aptr);
                    break;
                }
            } while (customer_choice != '7');
        default:
            cout << "uhoh" << endl;
        }




    }

    return 0;
}












//********************************************************************
//****                          END OF MAIN FUNCTION                **
//********************************************************************
//****                         code for functions below             **
//********************************************************************












bool admmatch(string usar, string passs) {
    if (usar == admin->GetUsername() && passs == admin->GetPassword()) {
        cout << endl << "Sign in Successful" << endl;
        return true;
    }
    else {
        return false;
    }
}


bool admin_sign() {

    string user;
    string pas;
    system("cls");
    cout << "AdminSignInPage:" << endl << endl;
    cout << "Enter Admin Username: " << endl;

    cin >> user;
    cin.ignore();
    cout << "Enter Password: " << endl << endl;
    cin >> pas;
    cin.ignore();
    //admmatch is a function to plug in creditentials and do a search and match
    if (admmatch(user, pas)) {
        cout << "******PasswordMatch: Proceed**********" << endl << endl;
        return true;  //**************************************************tentative
    }
    else {
        cout << "******Passwordmismatch: LoopBack*********" << endl << endl;
        return admin_sign();
    }
}








char initial_welcome() {
    char first;
    system("cls");
    cout << "************WelcometoC++ProgrammersBank*********************" << endl;
    cout << "1. AdminSignIn:            Enter   1     " << endl;
    cout << "2. CustomerSignInpage:     Enter   2    " << endl;
    cout << "3. CustomerSignUppage:     Enter   3    " << endl;
    cout << "4. ExitApplication:”       Enter   4    " << endl << endl;
    cout << "Enter your option: " << endl;
    cin >> first;
    cin.ignore();
    //pausebefore();

    return first;
}





bool customer_signup() {


    Customer* person = new Customer();
    std::cin>>*person;
    collection->Insert(person, collection->root);
    user_pass.push_back({ person->Username,person->Password });
    usersnum++;
    aptr = person;
    
    if (true) {
        return true;
    }
    else {
        return false;
    }
}



bool cust_sign() {

    string user;
    string pas;
    system("cls");
    cout << "Customer Sign in Page:" << endl << endl;
    cout << "Enter Customer Username: " << endl;
    cin >> user;
    cin.ignore();
    cout << "Enter Password: " << endl << endl;
    cin >> pas;
    cin.ignore();
    Customer* temp;
    //cusmatch is a function to plug in creditentials and do a search and match
    if (searchcollection(user)->Username == user && searchcollection(user)->Password == pas) {
        cout << "******PasswordMatch: Proceed**********" << endl << endl;
        aptr = searchcollection(user);
        pausebefore();
        //******************************************************************************************
        return true;
    }
    else {
        cout << "******Passwordmismatch: LoopBack*********" << endl << endl;
        string dump;
        cin >> dump;
        pausebefore();
        return cust_sign();
    }
}

bool cusmatch(string usernam, string passwrd) {
    //function to search classes and see if username and password both exist and match
    //return true if both, return false if at least one is invalid

    if (usersnum == 0) {//sizeof(user_pass) == 0

        return false;
    }
    else {
        //for(int i = 0; i < collection.numitems(); i++)
        //collection.getusername()[i]
        //collection.getpassword()[i]
        for (int i = 0; i < usersnum; i++) {
            if (true/*user_pass[i][0] == usernam && user_pass == */) {
                return true;
            }
        }
        return false;

    }
}


char customer_route() {
    char choice;
    //system("cls");
    cout << "CustomerFunctionality:" << endl;
    cout << "1: StatementsummarylastNtransactions:" << endl;
    cout << "2: CurrentBalance" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4: Deposit" << endl;
    cout << "5: TransfertootherCID" << endl;
    cout << "6: CheckInbox" << endl;
    cout << "7: Logout" << endl;
    cin >> choice;
    cin.ignore();
    pausebefore();
    return choice;
}

char admin_route() {
    //system("cls");
    char choice;
    cout << "Adminfunctionality : " << endl;
    cout << "1 : PayMonthlyInterest." << endl;
    cout << "2 : Checkaccountwith - vebalance." << endl;
    cout << "3. Checkaccountwith + vebalances." << endl;
    cout << "4 : Warningmessagesto - vebalanceaccounts." << endl;
    cout << "5 : Repeated - vebalance; Blockaccount." << endl;
    cout << "6: GeneratesummaryReport:" << endl;
    cout << setw(30) << "TotalCustomers" << endl;
    cout << setw(30) << "Totalactivecustomers" << endl;
    cout << setw(30) << "TotalInactivecustomers" << endl;
    cout << setw(30) << "Total + vebalances" << endl;
    cout << setw(30) << "Total - vebalances" << endl;
    cout << "7: Logout" << endl;
    cin >> choice;
    cin.ignore();
    pausebefore();
    return choice;

}

//**********************************************************************************************************
//SUPER IMPORTANT FUNCTION
//*********************************************************************************************************
Customer* searchcollection(string namen) {

    Customer* aptr2;
    Node<Customer>** temp = collection->GetAllAscending();
    bool incol = false;
    //collection
    if (collection->size == 0) {
        return nullptr;
    }
    else {
        for (int i = 0; i < collection->size; i++) {
            aptr2 = temp[i]->key;

            if (aptr2->Username == namen) {

                return aptr2;
            }
        }
        return nullptr;  //name not in collection
    }
}

//****************************************************************************************
//overloaded for admin functionality,  return a list of negative or positive balances
//*********************************************************************************
void search_collect(bool negpos) {
 
    Node<Customer>* aptr2;
    bool incol = false;
    Node<Customer>** temp = collection->GetAllAscending();
  
    if (collection->size == 0) {
        return;
    }
    else {
        for (int i = 0; i < collection->size; i++) {
            aptr2 = temp[i];  
            if (negpos) {
                if (aptr2->key->current_balance >= 0) {
                    //puts customer into positive vector
                    posi.push_back(aptr2->key);
                }
            }
            else {
                if (aptr2->key->current_balance <= 0) {
                    //puts customer into negtive vector
                    nega.push_back(aptr2->key);
                }
            }
        }
        return;  //name not in collection
    }
}



void TotalCustomers() {
    cout << endl << "Total Customers are: " << endl << collection->size << endl;
    //string a;
    //cin >> a;
    //cin.ignore();
}
void Totalactivecustomers() {
    cout << endl << "Total Active Customers are: " << endl << collection->size << endl;
}
void TotalInactivecustomers() {
    cout << endl << "Total Inactive Customers are: " << endl << "0" << endl;
}
void Total_pos_vebalances() {
    //create a list of all accounts with positive balances
    //include name, and balance in table
    // 
    cout << endl << "Total Postive Balances are: " << endl << posi.size() << endl;
    //Customer* searchcollection(bool pos);
}
void Total_neg_vebalances() {
    //create a list of all accounts with negative balances
        //include name, and balance in table
        // 
    cout << endl << "Total Negative Balances are: " << endl << nega.size() << endl;
    //Customer* searchcollection(bool neg);
}
void Admin_Logout() {
    cout << "Logging out" << endl;
    pausebefore();
}

//******************************            
//Customer page functions
//******************************
void StatementsummarylastNtransactions(Customer& persons) {
    //just display up to last 5 transactions
    if (persons.account_status.size() == 0) {
        cout << " You have made no transactions as of yet" << endl;
    }
    else {
        for (int k = 0; k < persons.account_status.size(); k++) {
            cout << "Transaction _______ PLACE HOLDER SHOULD PUT DATE: $" << persons.account_status[k] << endl;
        }
    }
    //************************** NEED A PAUSE FUNCTION OR STUFF WONT SHOW
}
void CurrentBalance(Customer& persons) {

    cout << "Your Current balance is: " << persons.balance() << endl;
    pausebefore();
}
void Withdraw(Customer& persons) {
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
    persons.transaction(-1 * amount);
    pausebefore();
}
void Deposit(Customer& persons) {
    //increase balance
        //also add to balance sheet
        //message the ammount
    long amount;
    cout << "How much would you like to deposit into the bank?" << endl;
    //do {
    cin >> amount;
    cin.ignore();
    //} while (!isdigit(amount));
    persons.transaction(amount);
    pausebefore();
}
void TransfertootherCID(Customer& persons) {}//**************************************
void CheckInbox(Customer& persons) {
    //warning for negative balance can be read here 
    cout << endl;
    cout << "Opening Inbox" << endl;
    cout << "Messages: " << endl;
    if (sizeof(persons.Inbox) != 0) {
        for (int i = 0; i < sizeof(persons.Inbox); i++) {
            cout << persons.Inbox[i] << endl;  //size of should be vector dimensions
            //make sure there is a value and makesure use right size of function for vectors
        }
    }
    else {
        cout << "There are no Messages" << endl;
        pausebefore();
    }
}


void pausebefore() {
    //string adump;
    //cin >> adump;     //done to get user a chance to read message before screen clears
    //cin.ignore();
    //chrono::seconds dura( 5);
    //this_thread::sleep_forsleep_for(dura);
    //sleep(5);

}


void Customer_Logout(Customer& persons) {
    cout << "Logging OUT" << endl;
    pausebefore();
    //aptr = nullptr;
}