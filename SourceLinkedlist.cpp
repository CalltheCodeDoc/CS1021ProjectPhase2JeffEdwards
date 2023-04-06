#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Node.h"
#include "Node.cpp"
#include "InventoryItem.h"
#include <ctime>
#include <chrono>
//#include "InventoryItem.cpp"
#include <string>


//ohhhhhh only include the .cpp when its a templated class



using namespace std;



//prototypes
InventoryItem* searchsku2(int SKU, LinkedList<InventoryItem>* lis);
InventoryItem* searchsku(int SKU, InventoryItem* arr[], int numItems);
int indexsku(int SKU, InventoryItem* arr[], int numitems);
void arraysquish(InventoryItem* arr[], int index, int numitems);
void displayskus(LinkedList<InventoryItem>* lis);

int main() {
	//commented code tests parts of the code as I go
	/**/
	/**/
	/*    */
	/**/
	//
	//TODO:
	//	1.  To DO: make datetime stuff work in available function,  
	// 
	//
	// 
	//  
	//
	//5. 
	// 6. merge sort for fun, implement it
	//IT WORKS FINALLLLYYYY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	

	
	
	//TASK 3 BELOW
	system("Color 0A");
	int userresponse;
	char userresponse1;
	//int numberitems = 4;
	
	
	InventoryItem* temp2;
	LinkedList<InventoryItem>* list = new LinkedList<InventoryItem>();
	Node<InventoryItem>* temp = new Node<InventoryItem>(new InventoryItem(576879, "PS5 gaming console", 600, "UOM whatever that is", 5, 20), list->head);
	//^^^^ Don't do node<inventoryItem


	list->AddItem(new InventoryItem(3879, "PS5 gaming console", 600, "UOM whatever that is", 5, 20));
	list->AddItem(new InventoryItem(2589, "PS5 gaming console", 600, "UOM whatever that is", 5, 20));
	list->AddItem(new InventoryItem(1687, "PS5 gaming console", 600, "UOM whatever that is", 5, 20));
	list->AddItem(new InventoryItem(9579, "PS5 gaming console", 600, "UOM whatever that is", 5, 20));
	list->AddItem(new InventoryItem(5879, "PS5 gaming console", 600, "UOM whatever that is", 5, 20));
	list->AddItem(new InventoryItem(589, "PS5 gaming console", 600, "UOM whatever that is", 5, 20));
	list->AddItem(new InventoryItem(5687, "PS5 gaming console", 600, "UOM whatever that is", 5, 20));
	list->AddItem(new InventoryItem(4579, "PS5 gaming console", 600, "UOM whatever that is", 5, 20));
		
		
	list->NotYetMergeSort();
	list->Display();

	Node<InventoryItem>* temp3;
	

	int SKU;
	//int arrgindex;
	int quantity;
	double price;
	string uom;
	double lead;
	string desc;


	bool Isin;
	
	do{
	do {

		cout << "This is a test of the LinkedList class." << endl;
		//cout << "Type 1 for: LinkedList();" << endl;
			cout << "Type 2 activate destructor for the list" << endl;
			cout << "Type 3 to use AddItem(T * item) method to add an item into the list" << endl;
			cout << "Type 4 to use GetItem(T * item, Node<T>*ptr) method to retrieve and remove and item from the list" << endl;
			cout << "Type 5 to see if item is in the list using the method: IsInList(T * item)" << endl;
			cout << "Type 6 to see if the list is empty using the method: IsEmpty()" << endl;
			cout << "Type 7 to see how many nodes are in the list using the method: Size()" << endl;
			cout << "Type 8 to iterate forwards through the list using T* SeeNext() method" << endl;
			cout << "Type 9 to iterate backwards through the list using  T* SeePrev() method" << endl;
			cout << "Type 10 to use SeeAt(T*, Node<T>*ptr) method" << endl;
			cout << "Type 11 to Reset iterator back to head pointer used for SEENEXT, SEEPREV methods" << endl;
			cout << "Type 12 to manually sort inventory by SKU number" << endl;
			cout << "Type 13 to Display all inventory" << endl;
			//cout << "Type 14 for: void displayskus(LinkedList<InventoryItem>* lis)" << endl;
			cout << "Type 15 to terminate program" << endl;
			cin >> userresponse;
			cin.ignore();
			//getline(cin, userresponse);

	} while (userresponse>15||userresponse <1);
	cin.clear();
	switch (userresponse) {
	case 1:
		//cout << "Creating empty list..." << endl;
		//LinkedList<InventoryItem>* list = new LinkedList<InventoryItem>();
		break;
		//****************************************
		//use try catches in all of these to make sure list exists first and is not empty
		//so that the program doesnt crash when it tries to access a nullptr by user being dumbdumb
	case 2:
		cout << "Deleting list..." << endl;
		//Gotta delete all ints* in the list too
		//nodes too???
		delete list;
		break;
	case 3:
		cout << "To add an item please enter the values of the inventory item:" << endl;
		cout << "integer SKU: " << endl;

		cin >> SKU;
		cin.ignore();
		//getline(cin, SKU);
		cout << "Quantity: " << endl;
		cin >> quantity;
		cin.ignore();
		cout << "Price: " << endl;
		cin >> price;
		cin.ignore();
		cout << "Unit of Measure: " << endl;
		getline(cin, uom);
		cout << "Lead Time: " << endl;
		cin >> lead;
		cin.ignore();
		cout << "Description: " << endl;
		getline(cin, desc);
		cout << "Adding item to list..." << endl;
		list->AddItem(new InventoryItem(SKU, desc, price, uom, lead, quantity));
		list->NotYetMergeSort();
		break;
		
	case 4:
		cout << "Type in the SKU of the item you want to get: " << endl;
		cin >> SKU;
		cin.ignore();
		//if not available, message this to customer,
		//or just use available() method
		//Node<InventoryItem>* searchsku(int SKU, LinkedList<InventoryItem>*lis)

		try {
			InventoryItem* temp4 = searchsku2(SKU, list);
			if (temp4 == nullptr)
			{
				throw LinkedList<InventoryItem>::ListNotFlow("Item not found in list");
			}
			else {


				temp3 = list->GetItem(temp4, list->head);
				if (temp3 == nullptr)
				{
					throw LinkedList<InventoryItem>::ListNotFlow("Item not found in list");
				}
				else {

					cout << temp3->data->GetPartInfo() << " Is the item retrieved " << endl;
					delete temp3->data;
					temp3->data = nullptr;
					//probably should make destructor handle this stuff automatically
					delete temp3;
					temp3 = nullptr;

				}
			}
		}
		catch(const LinkedList<InventoryItem>::ListNotFlow& e) {
			std::cerr << "Caught MyClass::MyException: " << e.what() << std::endl;
		}
		break;
		//add additional code to display the item to the user indicating its in stock
	case 5:
		cout << "Check to see if an item is in the list." << endl;
		cout << "Type in the SKU of the item you want to check: " << endl;
		cin >> SKU;
		cin.ignore();
		Isin = list->IsInList(searchsku2(SKU, list)); //replace T * item with proper coding
		if (Isin) {
			cout << "Item is in the list." << endl;
		}
		else {
		cout << "Item is not in the list." << endl;
	}
		break;
	case 6:
		cout << "Check to see if the list is empty." <<endl;
		cout << "It is: " << list->IsEmpty() << " that the list is empty." <<endl;
		break;
	case 7:
		cout << "The size of the list is: " <<endl;
		cout<<  list->Size()<<endl;
		break;
	case 8:
		cout << "See the next item in the list." <<endl;
		try {
		temp2 = list->SeeNext();
		if(temp2==nullptr)
		{
			throw LinkedList<InventoryItem>::ListNotFlow("Item not found in list");
		}
		else {
			cout << temp2->GetPartInfo() << endl; //this sees a pointer, probably wanna see SKU or description
		}
		}
		catch (const LinkedList<InventoryItem>::ListNotFlow& e) {
			std::cerr << "Caught MyClass::MyException: " << e.what() << std::endl;
		}
		break;
	case 9:
		cout << "See the previous item in the list." <<endl;
		try {
		temp2 = list->SeePrev();
		if(temp2==nullptr)
		{
			throw LinkedList<InventoryItem>::ListNotFlow("Item not found in list");
		}
		else {
			cout << temp2->GetPartInfo() << endl; //this sees a pointers; probably wanna see SKU or description
		}
		}
		catch (const LinkedList<InventoryItem>::ListNotFlow& e) {
			std::cerr << "Caught MyClass::MyException: " << e.what() << std::endl;
		}
		break;
	case 10:
		cout << "See the item at a specific location in the list." <<endl;
		cout << "Type in the SKU of the item you want to see: "<<endl;
		cin >> SKU;
		try{
		//might have to change function to pay attention to SKU, not pointer
				InventoryItem* temp5 = searchsku2(SKU, list);
				if (temp5 == nullptr)
				{
					throw LinkedList<InventoryItem>::ListNotFlow("Item not found in list");
				}
				else {
					temp = list->SeeAt(temp5, list->head);
					if (temp == nullptr)
					{
						throw LinkedList<InventoryItem>::ListNotFlow("Item not found in list");
					}
					else {
						//temp = list->SeeAt(searchsku2(SKU, list), list->head);
						cout << temp->data << endl; //this sees a pointer, probably wanna see SKU or description
						//also replace T* with some mangled mess of data->getSKU(SKU)
						//*************************************************************
						//DUNNO WHAT YAH WANT TO SEE , the DATA, pointer, SKU?
					}
				}
		}
		catch (const LinkedList<InventoryItem>::ListNotFlow& e) {
			std::cerr << "Caught MyClass::MyException: " << e.what() << std::endl;
		}
		break;
	case 11:
		cout << "Reset the iterator view of the list to 0" <<endl;
		list->Reset();
		break;
	case 12:
		cout<< "Sort the list by SKU" <<endl;
		cout<< "This should be done whenever u wanna access items after adding items."<<endl;
		//***********************  
		//  OR THIS FUNCTION SHOULD BE CALLED AUTOMATICALLY everytime additems is called
		list->NotYetMergeSort();
		list->Display();
		break;
	case 13:
		cout << "Display the list." <<endl;
		list->Display();
		break;
	//case 14:
	//	cout << "Display all the SKUS in the list." << endl;
	//	displayskus(list);
	//	break;
	case 15:
		cout << "Terminating program." <<endl;
	}
	cout<< "Clear text? (y/n)" <<endl;
	cin>>userresponse1;
	if(userresponse1=='y')
	system("CLS");
		}while (userresponse!=99);

	
	

	return 0;
}






InventoryItem* searchsku2(int SKU, LinkedList<InventoryItem>* lis) {
	Node<InventoryItem>* tempo = lis->head;
	int suk;
	while (tempo!=nullptr) {
		suk = tempo->data->GetSKU();
		if (suk == SKU) {
			return tempo->data;
		}
		tempo=tempo->next;
	}
	return nullptr;

}

InventoryItem* searchsku(int SKU, InventoryItem* arr[], int numitems) {
	for (int i = 0; i < numitems; i++) {
		if (arr[i] != nullptr) {
			if (arr[i]->GetSKU() == SKU)
				return arr[i];
		}
	}
	throw "Item not found";
	
}
int indexsku(int SKU, InventoryItem* arr[], int numitems) {
	for (int i = 0; i < numitems; i++) {
		if (arr[i] != nullptr) {
			if (arr[i]->GetSKU() == SKU) {
				return i;
			}
		}
	}
	throw "Item not found";
}
void arraysquish(InventoryItem* arr[], int index, int numitems) {

	for (int k = 0; k < numitems; k++) {
		if (k >= index) {
			arr[k] = arr[k + 1];
		}
	}
}

void displayskus(LinkedList<InventoryItem>* lis) {
	int sku;
	for (int i = 0; i < lis->Size(); i++) {
		sku = lis->SeeNext()->GetSKU();
		cout<< sku <<endl;
		

	}
	lis->Reset();
}