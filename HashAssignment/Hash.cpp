//Hash.cpp

#include <iostream>
#include <cstdlib>
#include <string>
#include "Hash.h"



using namespace std;
//Function definitions

Hash::Hash()
{

	for (int i = 0; i < tableSize; i++) {//for loop that ends when tablesize is reached

		HTable[i] = new node;//point to a new item
		HTable[i]->name = "empty"; //make portion empty
		HTable[i]->phoneNumber = 0;// set phone number to zero
		HTable[i]->next = NULL; //following pointer to null


	}//end for loop


}//end constructor

void Hash::keySearch(string name) {
	int index = hash(name);//calls hash function to calculate value for storage, sets int index equal to that
	bool foundKey = false;// boolean foundKey set to false
	int phoneNumber; //int for phone number

	node* Ptr = HTable[index]; //point to first item in bucket
	while (Ptr != NULL) {//while pointer is not null
	if (Ptr->name == name) {//if pointer name is equal to value name passed in
		foundKey = true;//set foundKey to true
		phoneNumber = Ptr->phoneNumber;// andvance to next item


		}

	Ptr = Ptr->next;//advance to next item


	}
	if (foundKey == true) {// if the key was found, display the name and phone number
		cout << "We have found " << name << ". Their phone number is: " << phoneNumber << endl;
	}
	else {// if key isnt found

		cout << "Key not found!" << endl;// state such condition

	}
}





//function for displaying items in an index, takes index number as an argument
/*
void Hash::displayItemsIndex(int index) {
	node* Ptr = HTable[index];
	if (Ptr->name == "empty") {//if index is empty, state such condition 

		cout << "Bucket = " << index << " is empty" << endl;
	}
	else {//otherwise

		cout << "Index = " << index << "Has these items\n";//provide index number
		while (Ptr != NULL) {// while loop, while Pointer is not null
			cout << "****************************\n";
			cout << Ptr->name << endl;//display name 
			cout << Ptr->phoneNumber << endl;// display phone number
			cout << "****************************\n";
			Ptr = Ptr->next;//advance to following pointer
		}


	}






}
*/
//function to add item to our table, takes a name and phone number as arguments

void Hash::AddItem(string name,int phoneNumber)
{
	int index = hash(name);//calls hash function to calculate value for storage, sets int index equal to that


	if (HTable[index]->name == "empty") {// if table (index location) is equal to empty

		HTable[index]->name = name; //set name as name passed in
		HTable[index]->phoneNumber = phoneNumber;// set phoneNumber as phoneNumber passed in
	}
	else {//add item, if list is not empty
	
		node* Ptr = HTable[index];//Node Ptr, looking at start of index
		node* n = new node;//new pointer is pointing to a new node
		n->name = name;// sets name as value passed in 
		n->phoneNumber = phoneNumber;//sets P# as value passed in
		n->next = NULL; // sets next as null
		while (Ptr->next != NULL)//while next is not null
		{
			Ptr = Ptr->next;//advance forward to end of list
		}
		Ptr->next = n; //connects last item in list to created item
	}

	
}

int Hash::countIndex(int index) {// function to count items in index
	int count = 0;
	if (HTable[index]->name == "empty") {//if portion selected in index equals empty,
	

		return count;//return count value

	}
	else {//if portion is not empty...

		count++;//increment count
		node* Ptr = HTable[index];//node pointer pointing to item in index
		while (Ptr->next != NULL) {//while next item is not empty
			count++;//increment count
			Ptr = Ptr->next;//andvance to next position
		}
		
	}
	return count;//return count variable
}
// function for displaying table

void Hash::displayTable(){
	int number;//integer for quantity of items in list
	for (int i = 0; i < tableSize; i++)// for loop which cycles until table reaches its end
	{
		number = countIndex(i);
		cout << endl;
		cout << "***********"<<endl;
		cout << "Index: " << i << endl;//display index number
		cout << HTable[i]->name << endl; // display name
		cout << HTable[i]->phoneNumber << endl; // display phone number
		cout << "Number of items: " << number << endl; // display numbers of items in list
		cout << "***********";
		cout << endl;
	}



}
//hash function
int Hash::hash(string key) {

	int hash = 0; //integer variable for hash
	int index;//integer variable for index

	


	for (int i = 0; i < key.length(); i++)// for loop which lasts until key length is reached
	{

		hash += (int)key[i];//hash equals hash plus
		//cout << "Hash = " << hash << endl;
	}

	index = hash % tableSize;// index equals hash modulo tableSize
	
	return index;//  return index value

}