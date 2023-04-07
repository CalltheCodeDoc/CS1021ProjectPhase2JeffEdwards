#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <vector>
#include <iostream>
#include "Customer.h"
#include "BinarySearchTree.h"

using namespace std;

class Admin {

private:
	int CID, SSN;
	string Username, Name, Rank, Organization;
	string Status, DOB, DOJ, Password;
public:

	Admin();
	Admin(long CID,long SSN,string Username,string Name,string Rank,string Organization,string Status,string DOB,string DOJ,string Password);
	float payInterest(vector<Customer*> posi, float interestrate);
	float checkNegativeBalance(vector<Customer*> nega, int CID);
	float checkPositiveBalance(vector<Customer*> posi, int CID);
	float blockNegativeAccount(vector<Customer*> nega, int CID);
	float generateSummaryReport(vector<Customer*> posi, vector<Customer*> nega, BinarySearchTree<Customer>* collection);
	void Warningmessagesto_neg_vebalanceaccounts(vector<Customer*> nega);
	string GetUsername();
	string GetPassword();


};
#endif