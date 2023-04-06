#include "LinkedList.h"
#include "Node.h"
#include <iostream>

using namespace std;

//constructor
template <typename T>
LinkedList<T>::LinkedList(){
	head = nullptr;
	tail = nullptr;
	length = 0;
	iterator = nullptr;
}
//destructor
template <typename T>
LinkedList<T>::~LinkedList(){

	Node<T>* temp = head;
	Node<T>* temp2 = head;
	for (int l = 0; l < length; l++) {
		if (temp != nullptr) {
			delete temp->data;
			temp->data = nullptr;
			temp = temp->next;
			delete temp2;
			temp2 = temp;
		}
	}
//Destructor – make sure you remove all items to avoid memory leaks
}
/*
The destructor destroys the list by deleting all its nodes. These functions are defined in
NumberList.cpp
*/
/*
// Constructor
19 NumberList()
20 { head = nullptr; }
*/



template <typename T>
void LinkedList<T>::AddItem(T* inval){
	//so far this is unordered
	//activates iterator
	if (length > 0&& iterator ==nullptr)
		iterator = head;
	if (length == 0) {
		//Node<T>* temp = tail;
		tail = new Node<T>(inval, tail);
		head = tail;
		length++;
		//activates iterator
		if (length > 0 && iterator == nullptr)
			iterator = head;
	}
	else {
		Node<T>* temp = tail;
		tail = new Node<T>(inval, tail);
		temp->next = tail;
		//okay this works so long as stuff is always added to tail
		length++;
		BubbleSort();
	}
	//then do some ordering operation like merge sort
}


template <typename T>
void LinkedList<T>::Display() {
	Node<T>* temp = head;
	while (temp != nullptr) {
		cout << *temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


template <typename T>
Node<T>* LinkedList<T>::GetItem(T* item, Node<T>* ptr) {
		//recursion
	//not done according to function
	//GetItem – searches the list for the given item.If found, it removes it from
	///	the listand returns it.If not found, it returns a null pointer.

		if (ptr != nullptr && *ptr->data < *item) {
			if (ptr->next != nullptr) {
				return GetItem(item, ptr->next);
			}
			else {
				
				return nullptr;
			}
		}
		else if (ptr != nullptr && *ptr->data == *item) {
			//****************************************
			//RIGHT HERE ADD THE REMOVE FUNCTION
			// It swaps pointers to cut out the item
			//*****************************************
			//PROBLEM
			//WHAT IF ITEM THATS GOTTEN IS HEAD PTR OR TAIL and theres 1 or 2
			//THIS NEXT FUNCTION ONLY WORKS ON SANDWICHED PTRS

			//ok
			//make a umbrella function that swaps
			//have umbrella function contains conditions
			// that call specific case functions
			//that swap
			//do for all types of these functions
			Node<T>* temp;
			if (ptr == head && ptr == tail) {
				iterator == nullptr;
				temp = PointerSwap3(ptr);
			}
			else if (ptr == head) { //using tenary operator, but standard bool type castedworks too
				temp = PointerSwap2(ptr, ptr->next, 0);
			}
			else if (ptr == tail) {
				temp = PointerSwap2(ptr->prev, ptr, 1);
			}
			//if this is sandwiched pointer
			else {
			temp = PointerSwap(ptr->prev, ptr->next);
		}
			return temp;
		}
		else {
			
			return nullptr;
		}
}


template <typename T>
bool LinkedList<T>::IsInList(T* item){
	//returns a bool indicating if the given item is in the list.
	return Transverse(item, head);
}
template <typename T>
bool LinkedList<T>::IsEmpty(){
	if (length == 0)
		return true;
	else
		return false;
}
template <typename T>
int LinkedList<T>::Size() {
	// returns an int indicating the number of items in the list.
	return length;
}


template <typename T>
T* LinkedList<T>::SeeNext() {
/*
SeeNext – returns the item without removing it from the list at a given
location in the list. The class will maintain the next location and will start
at the first item in the list. When it gets to the last item in the list, it will
return a null pointer after it gets past the last item. If the list is empty, this
will throw an error. 2 calls to SeeNext will return the 2 items next to each
other in the list unless SeeAt or Reset is called in between the 2 calls (or
the first call returns the last item in the list).
*/
	if (iterator != nullptr) {
		if (iterator->next != nullptr) {
			iterator = iterator->next;
			return iterator->data;
		}
		else {
			throw "ListNotFlow";
			return nullptr;
		}
	}
	//else if (ptr != nullptr) {
	//	return ptr;
	//}
	else {
		throw "ListNotFlow";
		return nullptr;
	}

}

template <typename T>
T* LinkedList<T>::SeePrev(){
//SeePrev – Same as SeeNext except in the other direction.
	if (iterator != nullptr) {
		if (iterator->prev != nullptr) {
			iterator = iterator->prev;
			return iterator->data;
		}
		else {
			return nullptr;
		}
	}
	//else if (ptr != nullptr) {
	//	return ptr;
	//}
	else {
	
		return nullptr;
	}
}


template <typename T>
Node<T>* LinkedList<T>::SeeAt(T* item, Node<T>* ptr){
/*
SeeAt – Finds an item at a location in the list (int passed in from user), and
returns the item without removing it. If the location passed by the user is
past the end of the list, this will throw an error. This will set the location
used by SeeNext to point at the item after the item returned.
*/
	
	//if(item>length) //what do they mean my location???
		//throw "ListNotFlow"
	
		if (ptr != nullptr && *ptr->data < *item) {
			if (ptr->next != nullptr) {
				return SeeAt(item, ptr->next);
			}
			else {
				
				return nullptr;
			}
		}
		else if (ptr != nullptr && *ptr->data == *item) {
			return ptr;
		}
		else {
			
			return nullptr;
		}
	
}
template <typename T>
void LinkedList<T>::Reset(){
//Reset – resets the location that the SeeNext function uses to point at the
//	first item in the list.
	iterator = head;
}

template <typename T>
void LinkedList<T>::Swap(Node<T>* ptr1, Node<T>* ptr2){
	//sequential swap only
	//does not swap for nonsequential nodes
	//should put if statement to make sure this only happens with
	//sequential nodes
	//also doesnt work when prev pointer points to head pointer
	//gotta fix all instances of that
	// *************************************************
	// //prev point that leads to head should never point to head. thats dumb
	//********************************************************
	//
	//Node<T>* Temp = ptr1;
	//Node<T>* Temp4 = ptr2;

	//Node<T>* Temp3 = ptr2->next;
	//ptr2->next = ptr1;
	//ptr1->next = Temp3;
	//ptr1 = ptr2;

	//Node<T>* Temp2 = ptr1->prev;
	//ptr1->prev = ptr2;
	//ptr2->prev = Temp2;
	//ptr1->next->prev = ptr1;
	T* temp = ptr1->data;
	ptr1->data = ptr2->data;
	ptr2->data = temp;

}
template <typename T>
Node<T>* LinkedList<T>::PointerSwap(Node<T>* ptr1, Node<T>* ptr2) {
	//sequential swap only
	//does not swap for nonsequential nodes
	//should put if statement to make sure this only happens with
	//sequential nodes
	//also doesnt work when prev pointer points to head pointer
	//gotta fix all instances of that
	// *************************************************
	// //prev point that leads to head should never point to head. thats dumb
	//********************************************************
	//
	if (ptr1 == head && length == 0) {//or if 1st pointer or 2nd pointer null pointers
		return nullptr;
	}
	else if (ptr1 == head && length == 1) {
		return nullptr;
	}
	else if (ptr1->next == tail && tail != nullptr) {
		//***************************************************
	}
	else
	{
		//cuts out the NODE in between ptr1 and ptr2
		//should it delete hmmmmmmmmmmm??????
		//Node<T>* Temp = ptr1;
		//Node<T>* Temp4 = ptr2;

		Node<T>* Temp2 = ptr1->next;
		ptr1->next = ptr2;
		ptr2->prev = ptr1;

		Temp2->prev = nullptr;
		Temp2->next = nullptr;

		//Node<T>* Temp3 = ptr2->next;
		//ptr2->next = ptr1;
		//ptr1->next = Temp3;
		//ptr1 = ptr2;
		length--;
		return Temp2;

	}
	//this should remove the pointers to a middle item between and from
	//and the two sandwiching items should point to each other
	//basically if the two sandwiching items don't exist
	//there should be conditionals to handle these cases
	//they would be end or start of list


}

template <typename T>
Node<T>* LinkedList<T>::PointerSwap2(Node<T>* ptr1, Node<T>* ptr2, int removeindex) {
	//changes pointers of first two or last two items
	//returns the item removed
	if (ptr1 == head && length==0) {//or if 1st pointer or 2nd pointer null pointers
		return nullptr;
	}
	else if (ptr1 == head && length==1) {
		return nullptr;
	}
	else {
		
			if (removeindex == 0&&head ==ptr1) {
				//might need to insure head is explicitly changed
				//Node<T>* Temp2 = ptr1->next;
				//ptr1->next = ptr2;
				//ptr2->prev = ptr1;

				Node<T>* Temp = head;
				head = ptr2;
				ptr2->prev = nullptr;
				ptr1 -> next = nullptr;
				ptr1->prev = nullptr;

				length--;
				return Temp;
			}
			else
			{
				//remove index is 1
				//also implies ptr2 is tail
				//************************************
				//what to do when treating head-> prev improperly

				Node<T>* Temp = tail;
				tail = ptr1;
				ptr1->next = nullptr;
				//THIS IS WHERE IT BREAKS WHEN YAH REMOVE 
				ptr2->next = nullptr;
				ptr2->prev = nullptr;

				length--;
				return Temp;

			}
	

		}
	}
	


template <typename T>
Node<T>* LinkedList<T>::PointerSwap3(Node<T>* ptr1) {
	//for length ==1;
	//either removes tail or where head leads to

	if (head == tail)
	{
		Node<T>* temp = head;
		head = nullptr;
		tail = nullptr;
		temp->next = nullptr;
		temp->prev = nullptr;
		length--;
		return temp;

	}

}
template <typename T>
void LinkedList<T>::NotYetMergeSort(){
	//bubble for now

	for (int k = 0; k < length - 1; k++) {
		Node<T>* temp = head;
		for (int j = 0; j < length-1-k; j++) {
			if (*temp->data > *temp->next->data) {
				Swap(temp, temp->next);
		}
			temp = temp->next;
		}
	}
}

template <typename T>
void LinkedList<T>::BubbleSort() {
	//bubble for now
	//if this worked from tail u'd only need to do this once and do it efficiently
	//there are issues with the swap function with the tail
	//maybe->prev isnt implemented how it should be
	//doesn't matter now it automatically sorts but at an expensive cost
	// OHHHHHHH THE ISSUE IS THAT IT ASSUMES WHEN IT GETS TO THE END OF THE LIST ITS DEALING WITH THE TAIL
	// //but since its working backwards forwards
	//WHEN IN ACTUALITY ITS DEALING WITH HEAD POINTERS
	//THATS THE PROBLEM
	/*
	for (int k = 0; k < length - 1; k++) {
		Node<T>* temp = head;
		for (int j = 0; j < length - 1; j++) {
			if (*temp->data > *temp->next->data) {
				Swap(temp, temp->next);
			}
			temp = temp->next;
		}
	}
	*/
	//for (int k = 0; k < length - 1; k++) {
		Node<T>* temp = tail;
		for (int j = 0; j < length - 1; j++) {
			if (*temp->data < *temp->prev->data) {
				Swap(temp->prev, temp);
			}
			temp = temp->prev;
		}
	//}
}
/*
individual backwards tail bubble sort

*/



/*

split(&head,&length/2,&length/2+1,&tail)
if(there is more than 2 items betqeen a and b)
split
exist merge conditions
order
merge

*/



template <typename T>
bool LinkedList<T>::Transverse(T* item, Node<T>* ptr) {
	//recursion
	
	if (ptr != nullptr && ptr->data < item) {
		if (ptr->next != nullptr) {
			return Transverse(item , ptr->next);
		}
		else {
			return false;
		}
	}
	else if (ptr != nullptr && ptr->data == item) {
		return true;
	}
	else {
		return false;
	}
}


