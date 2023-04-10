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
// 2) DECODE still truncates 2 customers oddly..
// 
// 
//4)   Make displays update informatoin,  HINT have to create dataobjects that reference the information not copy it
//
//
//8)  Transaction history on initial balance creation doesnt work and update
// 
// 
// 10)   implement transferCID    && active customers
// 
// 
// 11)  make transaction table a 2 vectors and actually store the type of transaction
// 
// 
// 12) double check project requirements to make sure all requirements are met
// 


//**************************************************************************
//must do flow chart
//**************************************************************************


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
void Admin_Logout();

//customer page functions
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


bool preload = true;



int main()
{
    system("color 0A");
    
    if (preload) {
        collection->Load_Decode_File("Customers.txt");
    }
    else {
        //INITIALIZER


        //this is just to load dummie variables into the program
        //once there is a file this isn't needed
        //though it might be smart to figure out how to load transactions separately
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
    }
    



    //functions that load up two admin functions (positive and negative accounts)
    search_collect(true);
    search_collect(false);
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
                } while (admin_choice != '1' && admin_choice != '2' && admin_choice != '3' && admin_choice != '4' && admin_choice != '5' && admin_choice != '6' && admin_choice != '7' && admin_choice != '8' && admin_choice != '9' && admin_choice != '10'&& admin_choice != '11');


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
                case '7':
                    Admin_Logout();
                    collection->Save_Encode_File("Customers.txt");
                    adyes = false;
                    //logout = false;
                    break;
                case '8':
                    admin->TotalCustomers(collection);
                    break;
                case '9':
                    admin->TotalActiveCustomers(collection);
                    break;
                case '10':
                    admin->Total_pos_vebalances(posi);
                    break;
                case '11':
                    admin->Total_neg_vebalances(nega);
                    break;
                }
                
            } while (adyes);
        case 'c':
      

            do {
                do {
                    customer_choice = customer_route();
                } while (customer_choice != '1' && customer_choice != '2' && customer_choice != '3' && customer_choice != '4' && customer_choice != '5' && customer_choice != '6' && customer_choice != '7');

                switch (customer_choice) {
                case '1':
                    aptr->StatementsummarylastNtransactions();
                    break;
                case '2':
                    aptr->CurrentBalance();
                    break;
                case '3':
                    aptr->Withdraw();
                    break;
                case '4':
                    aptr->Deposit();
                    break;
                case '5':
                    aptr->TransfertootherCID();
                    break;
                case '6':
                    aptr->CheckInbox();
                    break;
                case '7':
                    Customer_Logout(*aptr);
                    collection->Save_Encode_File("Customers.txt");
                    break;
                }
            } while (customer_choice != '7');
        default:
            cout << "uhoh" << endl;
        }




    }

    //Memory management isn't quite taken care of here, But i dont want to break anything by prematurely deleting a node
    // during a rebalancing act.
    //stray arrays aren't handled here
    //althought that doesn't matter too terribly much if the contents of the array are pointers to the collection items
    // and collection items's contents are deleted here under the for loops
    //just means theres some stray pointers that point to the abyss of nothingness or point in misleading directions
    // I believe most if not all those stray pointers are also lost in limbo  of closed escaped functions
    //but that's not a big deal
    //maybe they automatically get closed???
    delete collection->root;
    delete collection;
    for(auto x: nega)
        delete x;
    for(auto x: posi) 
        delete x;

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
    cout << "4. ExitApplication:        Enter   4    " << endl << endl;
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
    //**********************************************************************************************
    // THIS IS NOT YET FULLY IMPLEMENTED
    //**********************************************************************************************
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

    while (true) {
        system("cls");
        cout << "Customer Sign in Page:" << endl << endl;
        cout << "Enter Customer Username: " << endl;
        cin >> user;
        cin.ignore();
        cout << "Enter Password: " << endl << endl;
        cin >> pas;
        cin.ignore();

        Customer* temp;

        if (searchcollection(user) == nullptr) {
            cout << "******Username not found: LoopBack*********" << endl << endl;
            //pausebefore();
            string dump;
            cin >> dump;
            cin.clear();
            continue; // Continue with the next iteration of the loop
        }

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
            continue; // Continue with the next iteration of the loop
        }
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
    cout << "3 : Checkaccountwith + vebalances." << endl;
    cout << "4 : Warningmessagesto - vebalanceaccounts." << endl;
    cout << "5 : Repeated - vebalance; Blockaccount." << endl;
    cout << "6: GeneratesummaryReport:" << endl;
    cout << setw(30) << "8: TotalCustomers" << endl;
    cout << setw(30) << "9: Totalactivecustomers" << endl;
    cout << setw(30) << "10: Total + vebalances" << endl;
    cout << setw(30) << "11: Total - vebalances" << endl;
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
    Node<Customer>** temp = collection->GetAllDescending();
    bool incol = false;
    //collection
    if (collection->size == 0) {
        return nullptr;
    }
    else {
        for (int i = 0; i < collection->Size(collection->root); i++) {
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



void Admin_Logout() {
    cout << "Logging out" << endl;
    pausebefore();
}





//no functionality as of now
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






