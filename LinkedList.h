#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>
#include <iostream>
#include <exception>

using namespace std;

//or 
//NODES
//double linked lists
//this is ordered
template <typename T>
class LinkedList/*Node*/ {
	//linked list makes nodes, nodes controlled and mapped by linked list class

public:
	LinkedList();
	~LinkedList();
	void AddItem(T* item);
	Node<T>* GetItem(T* item, Node<T>* ptr);
	bool IsInList(T* item);
	bool IsEmpty();
	int Size();
	T* SeeNext();
	T* SeePrev();
	Node<T>* SeeAt(T*, Node<T>* ptr);
	void Reset();
	Node<T>* PointerSwap(Node<T>* ptr1, Node<T>* ptr2);
	Node<T>* PointerSwap2(Node<T>* ptr1, Node<T>* ptr2, int removeindex);
	Node<T>* PointerSwap3(Node<T>* ptr1);
	void Swap(Node<T>* ptr1, Node<T>* ptr2);
	//add function printlist()
	void BubbleSort();
	void NotYetMergeSort();
	void Display();
	bool Transverse(T* item, Node<T>* ptr);


	Node<T>* tail;
	Node<T>* head;// = null;
	int length;// = 0;
	Node<T>* iterator;


	class ListNotFlow : public exception {
	public:
		ListNotFlow(const char* message) : msg_(message) {}
		const char* what() const noexcept { return msg_.c_str(); }
	private:
			string msg_;
	};
	//***************************************************
	//**********  MERGE SORT CAUSE ITS ORDEREd ***********
	//***************************************************

	//	OPERATORS OVERLOADED
		//for comparison of nodes
	//overloaded < > ==

private:
protected:
};
#endif