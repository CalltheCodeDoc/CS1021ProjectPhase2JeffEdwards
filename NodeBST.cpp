#include "NodeBST.h"

template <typename T>
Node<T>::Node(T* inval) {
	key = inval; //i think
	//or is data the count????
	left = nullptr;
	right = nullptr;
	isTarget = false;
	Target_Parent = nullptr;
	Target = nullptr;
	//DO we let Node handle connections to other nodes or BinarySearchTree?
}

template <typename T>
Node<T>::~Node() {
	Target_Parent = nullptr;
	Target = nullptr;
	//delete key;
	delete left;
	delete right;
	//maybe delete value
}