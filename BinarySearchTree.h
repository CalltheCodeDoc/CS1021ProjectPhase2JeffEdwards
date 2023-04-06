#pragma once
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "NodeBST.h"
#include <exception>
#include "TreeExceptions.h"

template <typename T>
class BinarySearchTree
{
public:

	//https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

	BinarySearchTree();
	~BinarySearchTree();
	void Insert(T* inval, Node<T>* parent);
	T* remove(T* key);
	void Remove(T* inval);
	//these functions Remove should rebalance if necessary
	bool Find(T* inval, Node<T>* parent);
	T* Find(T* inval);
	Node<T>* FindTransverse(T* inval, Node<T>* parent);
	Node<T>** GetAllAscending();   //key is string,  count is data//  sort by string
	Node<T>** GetAllDescending();
	void EmptyTree();
	int Size(int count, Node<T>* node);
	void Print(Node<T>* toprint);
	void PrintVect(Node<T>** vects);



	string Hash_Encoder(string input);
	string Hash_Decoder(string input);

	
	void BinarySearchTree<T>::Save_Encode_File(string file);
	void BinarySearchTree<T>::Load_Decode_File(string file);
	
	Node<T>* FindTransverseFamily(T* inval, Node<T>* grandparent, Node<T>* parent, Node<T>* child);
	Node<T>* FindMinimum(Node<T>* start, Node<T>* target);
	int Collect(Node<T>** arr, int index, Node<T>* node);
	int collect(Node<T>** arr, int index, Node<T>* node);
	//these are used in recurssion where yah ahve to keep track of the parent and grandparent
	//Node<T>* BinarySearchTree<T>::FindTransverseParent(T* inval, Node<T>* parent);
	

	int GetHeight(Node<T>* current);   //This does the rebalancing
	void RotateLeft(Node<T>* parent, Node<T>* pivot);  // change arguments to be more appropriate
	void RotateRight(Node<T>* parent, Node<T>* pivot);
	void RotateLeftRight(Node<T>* parent, Node<T>* pivot);
	void RotateRightLeft(Node<T>* parent, Node<T>* pivot);

	T* FindSmallestLarger(Node<T>* temp);
	T* FindLargestSmaller(Node<T>* temp);
	int Height(Node<T>* current, Node<T>* parent);
	void rotateLeft(Node<T>* parent, Node<T>* pivot);
	void rotateRight(Node<T>* parent, Node<T>* pivot);
	void rotateRightLeft(Node<T>* parent, Node<T>* pivot);
		void rotateLeftRight(Node<T>* parent, Node<T>* pivot);

		Node<T>* root;
		int size;


	/*
	class TreeException : public exception {
	public:
		TreeException(const char* message) : msg_(message) {}
		const char* what() const noexcept { return msg_.c_str(); }
	private:
		string msg_;
	};
	*/

	private:
	
};

#endif 