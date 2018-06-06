#pragma once
//Hash.h
#include <iostream>
#include <cstdlib>
#include <string>



using namespace std;


class Hash {// hash class
private://private portion
	static const int tableSize = 10; //static const int with a size of 10

	struct node{//struct node
		string name;// portion to store name
		int phoneNumber; // stores integer
		node* next; //node pointer for next item in list

	};

	node* HTable[tableSize]; // Node pointer for Hash table with a size of static const int above

public://public portion

	// function declarations 
	Hash();
	int hash(string key);
	void AddItem(string name, int phoneNumber);
	int countIndex(int index);
	//void displayItemsIndex(int index);
	void keySearch(string name);
	void displayTable();



};