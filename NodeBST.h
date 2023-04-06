#pragma once
#ifndef NODEBST_H
#define NODEBST_H

template <typename T>
class Node {

public:
	Node(T* inval);
	~Node();
	T* key; //data
	//T value;
	Node* left;
	Node* right;
	//below is activated and deactivated for finding the target node to be used in remove functionn
	//findtransversefamily function activates these
	//removefunction should deactivate these
	bool isTarget;
	Node<T>* Target_Parent;
	Node<T>* Target;
};
#endif