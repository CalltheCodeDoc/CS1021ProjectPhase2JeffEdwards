#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Node.h"
#include "Node.cpp"
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include "Words.h"
#include <iomanip>
#include <cstring>
#include <random>


using namespace std;









/*

BinarySearchTree<Word>* WordTree;


template <class T>
void printBT(const std::string& prefix, const Node<T>* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "|--" : "'--");

		// print the value of the node
		std::cout << *node->key << std::endl;

		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
		printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
	}
}

template <class T>
void printBT(const Node<T>* node)
{
	printBT("", node, false);
}

bool exists(const string& fileName) // Returns true if the filename passed in exists (function checks if a string of any kind is present in the file)
{
	ifstream infile(fileName.c_str());
	return infile.good();
}

void BodyFunction() // created to make main() more efficient and readable
{
	string fileName;
	ifstream targetFile;
	cout << "Please Enter the File Name (with extension): ";
	cin >> fileName;

	targetFile.open(fileName);

	while (!targetFile)
	{
		cout << "Error: The file with the name provided could not be opened." << endl;
		cout << "Please try again: ";
		cin >> fileName;
		targetFile.open(fileName);
	}

	string contentsWatch = ""; // string used to search for "Contents:" so the beginning of the actual text can be found

	while (contentsWatch != "Contents:" && contentsWatch != "Contents: " && contentsWatch != "Contents:\r" && contentsWatch != "Contents: \r")
	{
		getline(targetFile, contentsWatch);
	}

	int flag = 0;
	string w;
	string w1;

	while (!targetFile.eof())
	{
		targetFile >> w;
		w1 = "";
		for (int i = 0; i < w.length(); i++)
		{
			if (!isalpha(w.at(i))) {
				continue;
			}
			w.at(i) = tolower(w.at(i));
			w1 += w.at(i);
		}
		Word *tempWord = new Word(w1, 1);
		try {
			WordTree->Find(tempWord);
		}
		catch (EmptyTreeException ex) {
			WordTree->Insert(tempWord, WordTree->root);
			continue;
		}

		Word* WordLocation = WordTree->Find(tempWord);
		if (WordLocation == nullptr)
		{
			WordTree->Insert(tempWord, WordTree->root);
		}
		else
		{
			if (tempWord->getWords() == "me")
			{
				int x = 1;
			}
			WordLocation->setFrequency(WordLocation->getFrequency() + 1);
		}
	}

	printBT(WordTree->root); //////////////////////////////////////////////does it print address or value?
	//WordTree->PrintVect(WordTree->GetAllAscending());

	targetFile.close(); // close file

}

void OptionMenu() {

	int menuans = 0;
	string search = "";
	Word* searchword;
	Word* searchloc;
	while (menuans == 0)
	{
		cout << endl;
		cout << "What would you like to do next?" << endl;
		cout << "(0) Search for a word (outputs frequency)" << endl;
		cout << "(1) GetAllAscending (list of elements in alphabetical order)" << endl;
		cout << "(2) GetAllDescending (list of elements in reverse alphabetical order)" << endl;

		cin >> menuans;

		switch (menuans) {
		case 0: // search
			cout << endl;
			cout << "What word would you like to search for?" << endl;
			cout << "> ";
			cin >> search;
			cout << endl;
			searchword = new Word(search, 0);
			searchloc = WordTree->Find(searchword);
			if (searchloc == nullptr)
			{
				cout << "The word you searched for was not in the tree." << endl;
			}
			else
			{
				cout << "The given word appeared " << searchloc->getFrequency() << " times." << endl;
			}
			break;
		case 1: // ascending
			cout << endl;
			WordTree->PrintVect(WordTree->GetAllAscending());
			break;
		case 2: // descending
			cout << endl;
			WordTree->PrintVect(WordTree->GetAllDescending());
			break;
		}

		cout << endl;
		cout << "Would you like to select another option?" << endl;
		cout << "(0) Yes" << endl;
		cout << "(1) No" << endl;

		cin >> menuans;
	}
}

int main()
{
	WordTree = new BinarySearchTree<Word>();
	char anotherBook = 'Y';

	BodyFunction();
	OptionMenu();

	cout << endl;
	cout << "Would you like to process another book?(Y/N): ";
	cin >> anotherBook;
	while (anotherBook == 'Y')
	{
		WordTree->EmptyTree();
		BodyFunction();
		OptionMenu();

		cout << endl;
		cout << "Would you like to process another book?(Y/N): ";
		cin >> anotherBook;
		while (anotherBook != 'Y' && anotherBook != 'N')
		{
			cout << "Please enter Y or N: ";
			cin >> anotherBook;
		}
	}

	return 0;
}






*/






//operator overload to compare items in tree, dunno if have to make yeah another separate class for this
//bool operator >(InventoryItem& const other);
//bool operator <(InventoryItem& const other);
//bool operator ==(InventoryItem& const other);
//friend ostream& operator<<(ostream& out, const InventoryItem& other);
bool retesting = false;
bool to_test = true;

int main()
{


	//debug code block

	BinarySearchTree<int>* Tree=new BinarySearchTree<int>();
	Tree->Insert(new int(25), Tree->root);
	Tree->Insert(new int(20), Tree->root);
	Tree->Insert(new int(45), Tree->root);
	Tree->Insert(new int(13), Tree->root);
	Tree->Insert(new int(100), Tree->root);
	Tree->Insert(new int(6), Tree->root);
	Tree->Insert(new int(17), Tree->root);
	Tree->Insert(new int(30), Tree->root);
	Tree->Insert(new int(31), Tree->root);
	Tree->Insert(new int(5), Tree->root);
	Tree->Insert(new int(8), Tree->root);
	Tree->Insert(new int(7), Tree->root);
	Tree->Insert(new int(3), Tree->root);
	Tree->Insert(new int(4), Tree->root);
	Tree->Insert(new int(2), Tree->root);
	Tree->Insert(new int(1), Tree->root);
	Tree->Print(Tree->root);

	//cout << endl << endl << endl;
	//cout << "Number of nodes in tree are: " << Tree->Size(0, Tree->root) << endl;

	//Node<int>** arg = Tree->GetAllAscending();
	Node<int>** arg = Tree->GetAllDescending();
	//cout << "Size of: array: "<<sizeof(arg) << endl;
	for (int i = 0; i < Tree->Size(0, Tree->root); i++) {
		cout << *arg[i]->key << endl;
	}

	if (false) {
		//seems to work, it has a fail case, but the fail case catch happens outside of the function
		//not good to test the fail case without duplicating the external catching mechanism
		cout << endl << endl << endl;
		Node<int>* temp = Tree->FindMinimum(Tree->root, Tree->root->left);
		Tree->Print(temp);

		cout << endl << endl << endl;
		temp = Tree->FindMinimum(Tree->root->right, Tree->root->right->left);
		Tree->Print(temp);

		cout << endl << endl << endl;
		temp = Tree->FindMinimum(Tree->root->left, Tree->root->left);
		Tree->Print(temp);

		cout << endl << endl << endl;
		temp = Tree->FindMinimum(Tree->root, Tree->root->left);
		Tree->Print(temp);
	}


	if (retesting) {
		cout << endl << endl << endl;
		Node<int>* temp = Tree->FindTransverseFamily(new int(1), Tree->root, nullptr, nullptr);
		Tree->Print(temp);
		cout << endl << endl << endl;
		temp = Tree->FindTransverseFamily(new int(100), Tree->root, nullptr, nullptr);
		Tree->Print(temp);
		cout << endl << endl << endl;
		temp = Tree->FindTransverseFamily(new int(45), Tree->root, nullptr, nullptr);
		Tree->Print(temp);
		cout << endl << endl << endl;
		temp = Tree->FindTransverseFamily(new int(8), Tree->root, nullptr, nullptr);
		Tree->Print(temp);
		cout << endl << endl << endl;
		temp = Tree->FindTransverseFamily(new int(25), Tree->root, nullptr, nullptr);
		Tree->Print(temp);
	}

	if (to_test) {
	
		Tree->remove(new int(25));

		Tree->Print(Tree->root);
		


	}


	return 0;
}
/*/
//**********************************************************************************************************
//CODE BELOW IS HW1 CODE NOT YET ADJUSTED FOR LAB 9
/*
const int LETTER_NUM = 26;
int main()
{
	string answer;
	do {
		// Ask the user for the name of the file to be processed. 
		cout << "Enter the name of the file to be processed: ";
		string filename;
		getline(cin, filename);
		//Attempt to open the file of the given name.If unsuccessful, it should output an error message
		//and prompt the user to enter another file name.
		ifstream inFile;
		inFile.open(filename, ios::in);
		while (!inFile)
		{
			cout << "Error: unable to open the file. Enter another file name: ";
			getline(cin, filename);
			inFile.open(filename, ios::in);
		}
		
		struct Book
		{
			string title;
			string fullName;
			int wordCount;
			double letterFreqs[LETTER_NUM];
			int lineCount;
		};
		Book book;
		book.wordCount = 0;
		book.lineCount = 0;
		getline(inFile, book.title);
		getline(inFile, book.fullName);
		inFile.ignore(9, '\n');
		while (inFile)
		{
			string word;
			inFile >> word;
			if (word != "")
			{
				book.wordCount++;
			}
		}
		inFile.clear();
		inFile.seekg(0L, ios::beg);
		int letterCounts[LETTER_NUM] = { 0 };
		inFile.ignore(100, ':');
		inFile.ignore(1, '\n');
		while (inFile)
		{
			char letter;
			inFile.get(letter);
			if (isupper(letter))
			{
				letterCounts[static_cast<int>(letter) - static_cast<int>('A')]++;
			}
			else if (islower(letter))
			{
				letterCounts[static_cast<int>(letter) - static_cast<int>('a')]++;
			}
			else
			{
			}
		}
		int total = 0;
		for (int i = 0; i < LETTER_NUM; i++)
		{
			total += letterCounts[i];
		}
		for (int i = 0; i < LETTER_NUM; i++)
		{
			book.letterFreqs[i] = letterCounts[i] / static_cast<double>(total);
		}
		inFile.clear();
		inFile.seekg(0L, ios::beg);
		inFile.ignore(100, ':');
		inFile.ignore(1, '\n');
		while (inFile)
		{
			string line;
			getline(inFile, line);
			if (line != "")
			{
				book.lineCount++;
			}
		}
		inFile.close();
		
		ofstream outFile;
		outFile.open("CardCatalog.txt", ios::app);
		outFile << "Title : " << book.title << endl;
		outFile << "Full Author : " << book.fullName << endl;
		int index = book.fullName.find(' ');
		string firstName = book.fullName.substr(0, index);
		string lastName = book.fullName.substr(index + 1);
		outFile << "Author First Name : " << firstName << endl;
		outFile << "Author Last Name : " << lastName << endl;
		outFile << "Word count : " << book.wordCount << endl;
		outFile << "Line count : " << book.lineCount << endl << endl;
		outFile.close();
		
		cout << "Do you want to see the letter frequency? Enter \"yes\" or \"no\": ";
		//string answer;
		cin >> answer;
		while (answer != "yes" && answer != "no")
		{
			cout << "Error: please enter \"yes\" or \"no\": " << endl;
			cin >> answer;
		}
		if (answer == "yes")
		{
			for (int i = 0; i < LETTER_NUM; i++)
			{
				cout << char(static_cast<int>('a') + i) << ": " << book.letterFreqs[i] << endl;
			}
		}

		

		cout << "Do you want to process another book? (Enter 'yes' or 'no'): ";
		cin >> answer;


		while (answer != "yes" && answer != "no")
		{
			cout << "Error: please enter \"yes\" or \"no\": " << endl;
			cin >> answer;
		}
		cin.ignore(1, '\n');
	} while (answer == "yes");
	
	return 0;
}
*/