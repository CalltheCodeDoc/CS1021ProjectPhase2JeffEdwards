#include "BinarySearchTree.h"
#include <iostream>

using namespace std;
template <typename T>
BinarySearchTree<T>::BinarySearchTree(){
	root=nullptr;
	size = 0;
}
template <typename T>
BinarySearchTree<T>::~BinarySearchTree() { 

}
template <typename T>
void BinarySearchTree<T>::Insert(T* inval, Node<T>* parent) {
	//inserting options:
	//head->right->right
	//head->right->left
	//head->left->right
	//head->left->left

	//recursion

	//************************************************************
	//duplicate values are always put on leftside
	// what if that first node is  removed, will it still find the duplicate value?
	// //i think so if rebalancing is handled right
	// BUT THE STANDARD FOR THIS CODE IS ALL DUPLICATE VALUES GET PLACED ON THE LEFT
	//************************************************************
	if(root == nullptr) {
		root = new Node<T>(inval);
		return;
	}
	else if(*inval > *parent->key){
		if (parent->right == nullptr) {
			parent->right = new Node<T>(inval);
			return;
		}
		Insert(inval, parent->right);
	}
	else {
		if (parent->left == nullptr) {
			parent->left = new Node<T>(inval);
			return;
		}
		Insert(inval, parent->left);
	}

	Height(root, nullptr);
	//need to manage other parameters here like
	// 
	//height
	//balance
	//level
	//size or count
	//
	//NEED TO REBALANCE HERE TOOO
}
template <typename T>
void BinarySearchTree<T>::Remove(T* inval) {


	//*******************************************************************************************
	//REMOVE FUNCTION
	//DELETEING A NODE CAUSES A CHAIN REACTION of deleting all nodes below it,
	//Even if its temp
	//change left and right pointers to nullptrs  before manually deleting node in this function
	//******************************************************************************************


	//these functions Remove should rebalance if necessary
		//this is inefficient
	//Node<T>* tempgrandchild = FindTransverse(inval, root);
	//bool children = false;
	Node<T>* temp = FindTransverseFamily(inval, root, nullptr, nullptr);
	bool exception = false;
	if (temp == nullptr) {
		return; //nothing to remove   SHould PRINT OUT A THROW EXCEPTION BUT KEEP PROGRAM RUNNING
	}
	else if (temp->isTarget) {
		if (temp->left == nullptr && temp->right == nullptr) {
			//target is root and is the only node in tree
			temp->isTarget = false;
			temp->Target = nullptr;
			root = nullptr;
			delete temp;    //********************** remove if u dont want to delete but want to fetch it
			//no rebalancing necessary here
		}
		else {
			//TODO
			//what to do if root has children
			//rebalance? or just remove and let rebalancing handle it? or just remove and dont rebalance?

			if (temp->Target->left != nullptr&& temp->Target->right == nullptr) {
				root = temp->Target->left;
				//temp->Target->left = nullptr;
				//below line is unnecessary
				//temp->Target->left->right= temp->right //THIS ONLY WORKS IF target has no children
					//TO DO
					//could put conditionals where if temp->right and temp->Target->left->right are not null then do somethign differeent
					//conditoinal would have to be above the above line
					//but it conflicts with the above if condition
			}
			else if(temp->Target->right != nullptr && temp->Target->left == nullptr) {
				root = temp->Target->right;
				//temp->Target->right = nullptr;
				//below line is unnecessary but it does help in some corner cases
				//temp->Target->right->left = temp->left //THIS ONLY WORKS IF target has no children
					//TO DO
					//could put conditionals where if temp->left and temp->Target->right->left are not null then do somethign differeent
					//conditional would have to be above the above line
					//but it conflicts with the above else if condition
			}
			else if (temp->Target->right != nullptr && temp->Target->left != nullptr) {
				//TO DO
				//handle cases where there are collisions.
				//how to handle the branch that has no easy way to be reinserted into the tree
				//find minimum in right subtree
				//copy the value in targeted node
				//remove the minimum in right subtree
				//****************WHHHHHOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOPPPPPPPPPSS
				//I DID THIS AS IF IT WERENT ROOT, BUT IT IS ROOT
				//MAYBE IT WORKS ANY WAY BUT DOUBLE CHECK
				//seems to be valid so thumbs up
				if (temp->Target->right->left == nullptr) {
					temp->Target->key = temp->Target->right->key;
					Node<T>* temp2 = temp->Target->right;
					temp->Target->right = temp->Target->right->right;
					temp2->right = nullptr;
					temp2->left = nullptr;
					delete temp2;
					exception = true;
				}
				else {
					Node<T>* minimum = FindMinimum(temp->Target->right,temp->Target->right->left);
					if (minimum->left != nullptr && minimum->left->right != nullptr) {
						temp->Target->key = minimum->left->key;
						Node<T>* temp3 = minimum->left;
						minimum->left = minimum->left->right;
						temp3->left = nullptr;
						temp3->right = nullptr;
						delete temp3;

					}
					else {
						temp->Target->key = minimum->left->key;  
						minimum->left->left = nullptr;
						minimum->left->right = nullptr;
						delete minimum->left;
						minimum->left = nullptr;
						//delete minimum;
						exception = true;

						//TODO
						//I THINK THIS HANDLES ALL CASES EXCEPT WHEN the minimum has a right child

						//THIS TO DO SHOULD BE ABOVE INBETWEEN ELSE AND LINE BELOW MINIMUM

						//THIS IS WHERE YAH DO RECURSION

					}





				}





				}

			if (!exception) {
				temp->left = nullptr;
				temp->right = nullptr;
				delete temp;
			}
			temp->Target_Parent = nullptr;
			temp->isTarget = false;
			temp->Target = nullptr;
		}

	}
	else {
		//remove
		if (temp->Target!= nullptr && (temp->Target->left !=nullptr || temp->Target->right !=nullptr)) {//children
			//have to reinsert children in tree
			// //rebalance
			//TODO


			if (temp->Target->left != nullptr && temp->Target->right == nullptr) {
				
				//this should mirror the above
				//except instead of dealing with root
				//deal with temp->Target_Parent
				//so copy code and repla
				if (temp->Target_Parent->left == temp->Target) {
					temp->Target_Parent->left = temp->Target->left;
				}
				else if (temp->Target_Parent->right == temp->Target) {
					temp->Target_Parent->right = temp->Target->left;
				}
				else {
					//error
				}
				//Target_Parent = temp->Target->left;
				//temp->Target->left = nullptr;
				//below line is unnecessary
				//temp->Target->left->right = temp->right



			}
			else if(temp->Target->right != nullptr && temp->Target->left == nullptr){
				if (temp->Target_Parent->left == temp->Target) {
					temp->Target_Parent->left = temp->Target->right;
				}
				else if (temp->Target_Parent->right == temp->Target) {
					temp->Target_Parent->right = temp->Target->right; //Target parent points to a parent
					//but it doesnt point from left or right
					//never change target_parent
				}
				//temp->Target->right = nullptr;
				//below line is unnecessary but it does help in some corner cases
				//temp->Target->right->left = temp->left //THIS ONLY WORKS IF target has no children



			}
			else if (temp->Target->right != nullptr && temp->Target->left != nullptr) {

				//TODO



				//find minimum in right subtree
				//copy the value in targeted node
				//remove the minimum in right subtree
				//******************* THIS IS THE SAME CODE AS ABOVE but it was done as if it werent root
				//this should ***************** work , btu above code might not work
				if (temp->Target->right->left == nullptr) {
					//this checks to see if the conditions are right for the 
					//recursion to end in one loop
					//if it doesnt then the else catches everything else
					temp->Target->key = temp->Target->right->key;
					//temp->Target->value = minimum->value;
					Node<T>* temp2 = temp->Target->right;
					temp->Target->right = temp->Target->right->right;
					//do i need to set the pointers to null??
					temp2->left = nullptr;
					temp2->right = nullptr;
					delete temp2;
					exception = true;
				}
				else {
					Node<T>* minimum = FindMinimum(temp->Target->right, temp->Target->right->left);
					if (minimum->left != nullptr && minimum->left->right != nullptr) {
						temp->Target->key = minimum->left->key;
						Node<T>* temp3 = minimum->left;
						minimum->left = minimum->left->right;
						temp3->left = nullptr;
						temp3->right = nullptr;
						delete temp3;

					}
					else {
						temp->Target->key = minimum->left->key;  //should this dereference?
						//* in front to derefernce?????????  im not sure
						//temp->Target->value = minimum->value;
						// uncomment value if add value to node
						minimum->left->left = nullptr;
						minimum->left->right = nullptr;
						delete minimum->left;
						minimum->left = nullptr;
						//delete minimum;
						exception = true;

						//TODO
						//I THINK THIS HANDLES ALL CASES EXCEPT WHEN the minimum has a right child

						//THIS TO DO SHOULD BE ABOVE INBETWEEN ELSE AND LINE BELOW MINIMUM

						//THIS IS WHERE YAH DO RECURSION


					}


				}



			}
			/*
			else {
				//no children under target, so simply change parents pointer to it to null and delete
			if(temp->Target_Parent->left==temp->Target)
				temp->Target_Parent->left = nullptr;
			else if (temp->Target_Parent->right == temp->Target)
				temp->Target_Parent->right = nullptr;
			else {
				//error
			}
			}
			*/



			
			temp->Target_Parent = nullptr;
			temp->isTarget = false;
			temp->Target = nullptr;
			temp->left = nullptr;
			temp->right = nullptr;
			delete temp;

		}
		else {//nochildren
			//isleaf
			if (temp->Target_Parent != nullptr && temp->Target != nullptr) {


				if (temp->Target_Parent->left == temp->Target) {
					temp->Target_Parent->left = nullptr;
				}
				else {
					temp->Target_Parent->right = nullptr;
				}

				temp->isTarget = false;
				temp->Target_Parent == nullptr;
				temp->Target == nullptr;
				temp->left = nullptr;
				temp->right = nullptr;
				delete temp;


			}

		}
	}
}




template <typename T>
bool BinarySearchTree<T>::Find(T* inval, Node<T>* parent) {
	//recurssion
	if (parent == nullptr) {
		return false;
	}
	else if (*parent->key == *inval) {
		return true;
	}
	else if (*inval > *parent->key) {
		return Find(inval, parent->right);
	}
	else {
		return Find(inval, parent->left);
	}

}

template <typename T>
Node<T>* BinarySearchTree<T>::FindMinimum(Node<T>* start, Node<T>* target) {
	//recurssion
	if (start->left==nullptr) {
		return start;  //only problem is you wont know if it stops at if it stops at the start
		//have to check that when ever u call this function
		//THIS IS BAD IF THIS HAPPENS FIRSTIME
	}
	else if (start->left->left == nullptr) {
		return start;
	}
	else {
		return FindMinimum(start->left, start->left->left);
	}

}

template <typename T>
Node<T>* BinarySearchTree<T>::FindTransverse(T* inval, Node<T>* parent) {
	//recurssion
	if (parent == nullptr) {
		return nullptr;
	}
	else if (*parent->key == *inval) {
		return parent;
			}
	else if (*inval > *parent->key) {
		return FindTransverse(*inval, parent->right);
	}
	else {
		return FindTransverse(*inval, parent->left);
	}

}
template <typename T>
Node<T>* BinarySearchTree<T>::FindTransverseFamily(T* inval, Node<T>* grandparent, Node<T>* parent, Node<T>* child) {
	//recurssion
	//initiate with grandparent as root, and parent and child as nullptrs
	//slowly fill in parent and child as you go down the tree

	//************************************************************
	//THIS DOESN't RETURN THE NODE ITSELF WHERE THE VALUE IS AT
	//IT RETURNS THE GRANDPARENT OF THE NODE WHERE THE VALUE IS AT
	//************************************************************
	//GOTTA FIGURE OUT HOW TO DEAL WITH THIS WITH FUNCTIONS THAT CALL THIS
	//************************************************************

	if (parent == nullptr && child == nullptr) {
		//this basically says we are at the root, parent and child of the current search position don't necessarily
		//equal null, 
		//but once we check if the parent and or child of the value supplied by grandparent is nullptr
		//then there are no more children to check
		if (grandparent == nullptr) {
			return nullptr; //not found
		}
		else if (*grandparent->key == *inval) {
			grandparent->isTarget = true;
			grandparent->Target_Parent = nullptr;  //***************************************** even if u put root it wont work, will have to deal with the root issue iftarget is true, then change what root points too manually ********************
			grandparent->Target = grandparent; 
			return grandparent;
		}
		else if (*inval > *grandparent->key) {
			return FindTransverseFamily(inval, grandparent, grandparent->right, nullptr);
			//return FindTransverse(inval, grandparent->right);
		}
		else {
			return FindTransverseFamily(inval, grandparent, grandparent->left, nullptr);
			//return FindTransverse(inval, parent->left);
		}
	}
	else if (child == nullptr) {
		if (parent == nullptr) {
			return nullptr; //not found
		}
		else if (*parent->key == *inval) {
			grandparent->isTarget = false;
			grandparent->Target_Parent = grandparent;  //***************************************** even if u put root it wont work, will have to deal with the root issue iftarget is true, then change what root points too manually ********************
			grandparent->Target = parent;
			return grandparent;
		}
		else if (*inval > *parent->key) {
			return FindTransverseFamily(inval, grandparent, parent, parent->right);
			//return FindTransverse(inval, grandparent->right);
		}
		else {
			return FindTransverseFamily(inval, grandparent, parent, parent->left);
			//return FindTransverse(inval, parent->left);
		}
	}
	else {
		if (child == nullptr) {
			return nullptr; //not found
		}
		else if (*child->key == *inval) {
			grandparent->isTarget = false;  //***************************************** even if u put root it wont work, will have to deal with the root issue iftarget is true, then change what root points too manually ********************
			grandparent->Target_Parent = parent; 
			grandparent->Target = child;
			return grandparent;
		}
		else if (*inval > *child->key) {
			return FindTransverseFamily(inval, parent, child, child->right);
			//return FindTransverse(inval, grandparent->right);
		}
		else {
			return FindTransverseFamily(inval, parent, child, child->left);
			//return FindTransverse(inval, parent->left);

		}


	}
}
/*
template <typename T>
Node<T>* BinarySearchTree<T>::FindTransverseGrandParent(T* inval, Node<T>* parent) {
	//recurssion
	if (parent == nullptr) {
		return nullptr;
	}
	else if (*parent->key == inval) {
		return parent;
	}
	else if (inval > *parent->key) {
		return FindTransverse(inval, parent->right);
	}
	else {
		return FindTransverse(inval, parent->left);
	}

}
*/
template <typename T>
Node<T>** BinarySearchTree<T>::GetAllAscending() {
	int const numnodes = this->Size(0, this->root);
	Node<T>** arr = new Node<T>*[numnodes];
	Collect(arr, 0, root);
	return arr;
}
template <typename T>
Node<T>** BinarySearchTree<T>::GetAllDescending() { 
	int const numnodes = this->Size(0, this->root);
	Node<T>** arr = new Node<T>*[numnodes];
	collect(arr, 0, root);
	return arr;
}
template <typename T>
void BinarySearchTree<T>::EmptyTree() // theoretically works by relying on a cascading destructor call caused by Node's destructor
{
	delete root;
}

template <typename T>
int BinarySearchTree<T>::Collect(Node<T>** arr, int index, Node<T>* node) {
	//int newindex = index;
	if (node == nullptr) {
		//return newindex;
		return index;
	}

	index = Collect(arr, index, node->left);
	//arr[newindex] = node;
	//newindex+=1;
	//debugging code
	//std::cout << "count: "<<newindex << endl;

	arr[index] = node;
	index += 1;
	index = Collect(arr, index, node->right);
	
	//if (node->left != nullptr) {
	//	newindex = Collect(arr, newindex, node->left);
	//}
	//if (node->right != nullptr) {
	//	newindex = Collect(arr, newindex, node->right);
	//}
	//return newindex;
	return index;



}
template <typename T>
int BinarySearchTree<T>::collect(Node<T>** arr, int index, Node<T>* node) {
	
	if (node == nullptr) {
		
		return index;
	}

	index = collect(arr, index, node->right);
	
	arr[index] = node;
	index += 1;
	index = collect(arr, index, node->left);

	return index;



}
template <typename T>
int BinarySearchTree<T>::Size(int count, Node<T>* node) { 
	
	if (node == nullptr) {
		return count;
	}
	count += 1;
	//if (node->left != nullptr) {
		count = Size(count, node->left);
	//}
	//if (node->right != nullptr) {
		count = Size(count, node->right);
	//}
	return count;


	
}
template <typename T>
void BinarySearchTree<T>::Print(Node<T>* toprint) {
	if (toprint == NULL) return;
	cout << *toprint->key << " ( ";
	if (toprint->left != nullptr) {
		cout << *toprint->left->key;
	}
	cout << " ,";
	if(toprint->right!=nullptr)
		cout << *toprint->right->key;
	cout << " ) " << endl;
	Print(toprint->left);
	Print(toprint->right);

}

template <typename T>
int BinarySearchTree<T>::GetHeight(Node<T>* current) { 
	if(current==nullptr)
		return 0;
	int L = GetHeight(current->left);
	int R = GetHeight(current->right);
	if (L == 0 && R == 0)//(L==nullptr && R==nullptr)
		return 1;
	if (L > R) {
		return 2 + 1;  
	}
	else
	{
		return R + 1; 
	}
	//inserting options:
	//head->right->right
	//head->right->left
	//head->left->right
	//head->left->left
}   //This does the rebalancing
template <typename T>
void BinarySearchTree<T>::RotateLeft(Node<T>* parent, Node<T>* pivot) { }
template <typename T>
void BinarySearchTree<T>::RotateRight(Node<T>* parent, Node<T>* pivot) { 
	//children
	bool children = false;
	if (children) {

		parent->left = parent->left->left;
		parent->left->right = pivot->left->right;
		pivot->left->right = pivot;
	
	}


	if(!children){ 
	
		parent->left = parent->left->left;
		parent->left->right = pivot;
		pivot->left = nullptr;
	
	}	
	
}
template <typename T>
void BinarySearchTree<T>::RotateLeftRight(Node<T>* parent, Node<T>* pivot) { }
template <typename T>
void BinarySearchTree<T>::RotateRightLeft(Node<T>* parent, Node<T>* pivot) { 
//this is one type, for all children
	//need to make a type for no children
	//need to make a type for one child
	parent->right->left;
	pivot->right->left = parent->left->right;
	parent->left->right = pivot->right;
	//pivot->right->left = nullptr;
	pivot->right = parent->left->left;
	parent->left->left = pivot;

}















template <class T>
T* BinarySearchTree<T>::remove(T* inval)
{
	if (root==nullptr) // empty tree case
	{
		//throw EmptyTreeException();
		return nullptr;
	}
	if (!Find(inval, root)) // not found case
	{
		//throw ItemNotFoundException();
		return nullptr;
	}

	Node<T>* temp = root;
	Node<T>* to_delete = nullptr;
	T* retval;

	if (*root->key == *inval) // root case
	{
		retval = root->key;
		if (root->right != nullptr) // right child exists
		{
			T* replaceval = FindSmallestLarger(root->right);
			T* removeval = remove(replaceval);
			size++;
			root->key = removeval;
		}
		else if (root->left != nullptr) // left child exists
		{
			T* replaceval = FindLargestSmaller(root->left);
			T* removeval = remove(replaceval);
			size++;
			root->key = removeval;
		}
		else // no children
		{
			EmptyTree();
		}

		// call balancing methods

		size--;
		return (retval);
	}

	// Other cases

	// While loop to find the parent of the Node<T> we wish to remove
	while ((temp->left != nullptr && *temp->left->key != *inval) || (temp->right != nullptr && *temp->right->key != *inval))
	{
		if (*temp->key < *inval && *temp->right->key != *inval)
		{
			temp = temp->right;
		}
		else if (*temp->key > *inval && *temp->left->key != *inval)
		{
			temp = temp->left;
		}
		else
		{
			break;
		}
	}

	// Figure out how many children our target Node<T> has and run appropriate remove procedure

	if (temp->left != nullptr && *temp->left->key == *inval) // Left child is the target
	{
		if (temp->left->left == nullptr && temp->left->right == nullptr) // leaf case
		{
			retval = temp->left->key;
			delete temp->left;
			temp->left = nullptr;
		}
		else if (temp->left->left != nullptr && temp->left->right != nullptr) // two children case
		{
			to_delete = temp->left;
			//**************************************************
			T* replaceval = FindSmallestLarger(to_delete->right);
			T* removeval = remove(replaceval); // will always be a leaf, so recursive remove call should return pretty quickly
			size++;
			retval = to_delete->key;
			to_delete->key = removeval;
		}
		else // one child case
		{
			to_delete = temp->left;
			if ((to_delete)->left != nullptr) // to_delete has left child
			{
				temp->left = to_delete->left;
				retval = to_delete->key;
				to_delete->left = nullptr;
				to_delete->right = nullptr;
				delete to_delete;
			}
			else // to_delete has right child
			{
				temp->left = to_delete->right;
				retval = to_delete->key;
				to_delete->left = nullptr;
				to_delete->right = nullptr;
				delete to_delete;
			}
		}
	}
	else // Right child is the target
	{
		if (temp->right->left == nullptr && temp->right->right == nullptr) // leaf case
		{
			retval = temp->right->key;
			delete temp->right;
			temp->right = nullptr;
		}
		else if (temp->right->left != nullptr && temp->right->right != nullptr) // two children case
		{
			//****************************************************************
			to_delete = temp->right;
			T* replaceval = FindSmallestLarger(to_delete->right);
			T* removeval = remove(replaceval); // will always be a leaf, so recursive remove call should return pretty quickly
			size++;
			retval = to_delete->key;
			to_delete->key = removeval;
		}
		else // one child case
		{
			to_delete = temp->right;
			if ((to_delete)->left != nullptr)
			{ // to_delete has left child
				temp->left = to_delete->left;
				retval = to_delete->key;
				to_delete->left = nullptr;
				to_delete->right = nullptr;
				delete to_delete;
			}
			else
			{ // to_delete has right child
				temp->right = to_delete->right;
				retval = to_delete->key;
				to_delete->left = nullptr;
				to_delete->right = nullptr;
				delete to_delete;
			}
		}
	}

	size--;

	// call balancing methods
	Height(root, nullptr);

	return retval;
}
template <class T>
T* BinarySearchTree<T>::FindSmallestLarger(Node<T>* temp)
{
	while (temp->left != nullptr)
	{
		temp = temp->left;
	}
	return temp->key;
}
template <class T>
T* BinarySearchTree<T>::FindLargestSmaller(Node<T>* temp)
{
	while (temp->right != nullptr)
	{
		temp = temp->right;
	}
	return temp->key;
}
// Methods for Rotation

template <class T>
int BinarySearchTree<T>::Height(Node<T>* current, Node<T>* parent)
{
	// base case
	if (current == nullptr)
	{
		return 0;
	}

	int L = Height(current->left, current);
	int R = Height(current->right, current);

	// logic to know when to rotate
	if (L - R >= 2)
	{
		if (current->left->left != nullptr)
		{
			rotateRight(parent, current);
			L--;
			R++;
		}
		else
		{
			rotateLeftRight(parent, current);
			L--;
			R++;
		}
	}
	else if (L - R <= -2)
	{
		if (current->right->right != nullptr)
		{
			rotateLeft(parent, current);
			L++;
			R--;
		}
		else
		{
			rotateRightLeft(parent, current);
			L++;
			R--;
		}
	}

	// more base cases
	if (L > R)
	{
		return L + 1;
	}
	return R + 1;
}

template <class T>
void BinarySearchTree<T>::rotateLeft(Node<T>* parent, Node<T>* pivot) // written in class, should work
{
	if (pivot == root)
	{
		root = pivot->right;
		pivot->right = root->left;
		root->left = pivot;
	}
	else if (parent->left == pivot)
	{ // if pivot is the left child of the parent
		parent->left = pivot->right;
		pivot->right = pivot->right->left;
		parent->left->left = pivot;
	}
	else
	{ // if pivot is the right child of the parent
		parent->right = pivot->right;
		pivot->right = pivot->right->left;
		parent->right->left = pivot;
	}
}

template <class T>
void BinarySearchTree<T>::rotateRight(Node<T>* parent, Node<T>* pivot) // inverse of what was written in class
{
	if (pivot == root)
	{
		root = pivot->left;
		pivot->left = root->right;
		root->right = pivot;
	}
	else if (parent->left == pivot)
	{ // if pivot is the left child of the parent
		parent->left = pivot->left;
		pivot->left = pivot->left->right;
		parent->left->right = pivot;
	}
	else
	{ // if pivot is the right child of the parent
		parent->right = pivot->left;
		pivot->left = pivot->left->right;
		parent->right->right = pivot;
	}
}

template <class T>
void BinarySearchTree<T>::rotateRightLeft(Node<T>* parent, Node<T>* pivot)
{
	if (pivot == root) // NOT DONE IN CLASS
	{
		root = pivot->right->left;
		pivot->right->left = root->right; // root->right to root->left
		root->right = pivot->right;
		pivot->right = root->left;
		root->left = pivot;
	}
	else if (pivot == parent->left) // pivot is left child of parent (in class)
	{
		parent->left = pivot->right->left; // start of case where pivot is the left of parent
		pivot->right->left = parent->left->right;

		parent->left->right = pivot->right;
		pivot->right = parent->left->left;

		parent->left->left = pivot;
	}
	else // pivot is right child of parent
	{
		parent->right = pivot->right->left; // start of case where pivot is the right of parent
		pivot->right->left = parent->right->right;

		parent->right->right = pivot->right;
		pivot->right = parent->right->left;

		parent->right->left = pivot;
	}
}


template <class T>
void BinarySearchTree<T>::rotateLeftRight(Node<T>* parent, Node<T>* pivot)
{
	if (pivot == root) // pivot is root (in class)
	{
		root = pivot->left->right;
		pivot->left->right = root->left;
		root->left = pivot->left;
		pivot->left = root->right;
		root->right = pivot;
	}
	else if (pivot == parent->left) // pivot is left child of parent
	{
		parent->left = pivot->left->right; // start of case where pivot is the left of parent
		pivot->left->right = parent->left->right;

		parent->left->left = pivot->left;
		pivot->left = parent->left->right;

		parent->left->right = pivot;
	}
	else // pivot is right child of parent
	{
		parent->right = pivot->left->right; // start of case where pivot is the right of parent
		pivot->left->right = parent->right->left;

		parent->right->left = pivot->left;
		pivot->left = parent->right->right;

		parent->right->right = pivot;
	}
}


template <class T>
T* BinarySearchTree<T>::Find(T* inval) // returns pointer to data of the node (could be edited to return entire node if needed
{
	if (Size(0, root) == 0)
	{
		throw EmptyTreeException();
	}
	Node<T>* temp = root;
	T* retval;
	while (true)
	{
		if (temp == nullptr)
		{ // not found case
			return nullptr;
		}
		if (*temp->key == *inval)
		{ // found case
			retval = temp->key; //////////////////////
			return retval;
		}
		if (*temp->key > *inval)
		{ // move right case
			temp = temp->left;
		}
		else
		{ // move left case
			temp = temp->right;
		}
	}
}

template <class T>
void BinarySearchTree<T>::PrintVect(Node<T>** vects)
{
	for (int i = 0; i < Size(0, root); i++)
	{
		//std::cout << *vects[i] << endl;
		cout << *vects[i]->key << endl;
	}
}