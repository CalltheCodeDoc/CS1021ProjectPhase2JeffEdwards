#pragma once
#ifndef NODE_H
#define NODE_H

using namespace std;

template <typename T>
class Node {
public:
	Node(T* inval, Node* hinter);
	~Node();
	Node* prev;
	Node* next;
	//Node* root;
	//Node * tail;
	T* data;
private:
protected:
};
#endif