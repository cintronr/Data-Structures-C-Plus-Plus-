#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;


template <class T>

class LinkedList {
public:
	//head = NULL;
	struct Node {//struct node for linked list

		T data;//integer to hold numbers
		struct Node* next;// for next portion
		struct Node* prev;//for previous portion
	};

	struct Node* head;// Pointer to head node  
	struct Node* tail;//Pointer to tail node
	struct Node* mark;//Pointer for search funtion, as well as pointer for minimum and maximum.
	struct Node* DeleteN;//Pointer for node deletion


	struct Node* GetNewNode(T x) {

		//local variable, cleared from memory when function is finished
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //reserving heap of memory, object stored for retention 
		newNode->data = x;//pass int x into data position
		newNode->prev = NULL;//set previous to null
		newNode->next = NULL;//set next to null
		return newNode;//return new node

	}

	void InsertAtHead(T x) {//function to insert at head

		struct Node* newNode = GetNewNode(x);//obtains new node info
		if (head == NULL) {//if statement which determines if head is empty, if so, set head and tail address to NewNode.
			head = newNode;
			tail = newNode;
			return;
		}

		head->prev = newNode;//Sets previous of established node as address of new node
		newNode->next = head;//sets next of created node as address of established head
		head = newNode; //sets head as address of new node
	}

	void InsertAtTail(T x)//function to insert at tail
	{
		struct Node* newNode = GetNewNode(x);//obtains new node info
		if (tail == NULL)//if tail is empty, set address to newNode
		{
			tail = newNode;
			return;
		}
		tail->next = newNode;//sets next of established node to address of created node
		newNode->prev = tail;//sets previous of created node to address of established node
		tail = newNode;//set tail as address of new node
	}


	void PrintReverse() {
		struct Node* temp = head;//Set struct Node temp to head address
		while (temp != NULL)//While temp is not equal to Null
		{

			std::cout << "<" << temp->data << ">";//set temp to next
			temp = temp->next;//move to next position
		}
		std::cout << endl;//print new line
	}

	void Print() {//Print Function

		struct Node* temp = head;
		if (temp == NULL) return;//if list is empty, exit					 
		while (temp->next != NULL)//while next pos is not equal to null
		{
			temp = temp->next;//temp is temp(next)
		}
		//Traverse backward using previous pointer
		while (temp != NULL)//while temp is not equal to null
		{
			std::cout << "<" << temp->data << ">";//print data from temp(data)
			temp = temp->prev;//(temp is temp(prev)
		}
		std::cout << endl;//print new line
	}

	void find(T number) {//Function for finding a number based on user input

		if (head == NULL) {//if head is empty, state such condition
			std::cout << "Your list is empty!";
		}
		mark = head;//mark is head
		int place = 0;//Integer for place where number was found
		while (mark != NULL) {//while mark is not null
			place++;//increment place
			if (mark->data == number) {//if mark(data) is equal to number
				std::cout << "Found " << number << " at position: " << place << endl;//display number and position found
				return;
			}
			if (mark->next != NULL)//if mark(next) is not equal to null
				mark = mark->next;// mark is mark(next)
			else
				break;
		}
		std::cout << number << " is not in list, sorry." << endl;
	}


	void DeleteEnd() {//Function to delete from end of list
		if (head == NULL) {//if list is empty, state such condition
			std::cout << "List is empty";//std cout stating list is empty
		}
		else//otherwise
		{
			struct Node* DeleteN = head;//move head into temp  DeleteN
			head = head->next;//reposition head
			head->prev = NULL;//
			delete DeleteN;//clear data from memory.
		}
	}



	void DeleteBegining() {//change to delete begining


		if (tail == NULL) {//if list is empty, state such condition
			std::cout << "List is empty";//std cout stating list is empty
		}
		else//otherwise
		{
			struct Node* DeleteN = tail;//move head into temp  DeleteN
			tail = tail->prev;//reposition head
			tail->next = NULL;//
			delete DeleteN;//clear data from memory.
		}
	}

	void findMax() {

		if (head == NULL) {//if head is empty, state such condition
			std::cout << "Your list is empty!";
		}//end if
		mark = head;//mark is head
		int max = 0;//Integer for maximum number
		while (mark != NULL) {//while mark is not null
			if (mark->data > max) { // is data in mark is greater than maximum 
				max = mark->data;//set int max equal to mark(data)
			}
			if (mark->next != NULL) {//if mark(next) is not equal to null
				mark = mark->next;// mark is mark(next)
			}
			else
				break;
		}//end while loop
		std::cout << "Maximum value is: " << max << endl;



	}//end findMax function



	void findMin() {//Find minimum function

		if (head == NULL) {//if head is empty,state this condition
			std::cout << "List is empty." << endl;
		}
		mark = head;//set mark as head
		int min = 1000000;//int to store minimum value, initialized to 100K for issue of 0/null retention when 0 value was removed from list
		while (mark != NULL) {//while mark is not empty
			if (mark->data < min) {//if mark(data) is less then minimum value
				min = mark->data;//minimum int become value in data
			}
			if (mark->data != NULL) {//if mark(data) is not empty
				mark = mark->next;//move to next position

			}
			else
				break;
		}//end while loop


		std::cout << "The lowest value in the list is:" << min << endl;//output lowest value found

	}//end of findMin function
public:

	void InsertAtHeadM(T x) {//function to insert at head

		InsertAtHead(x);
	}

	void PrintM() {

		Print();
	}
	void InsertAtTailM(T x) {

		InsertAtTail(x);

	}
	void PrintReverseM() {

		PrintReverse();
	}
	void DeleteBeginingM()
	{
		DeleteBegining();
	}
	void DeleteEndM()
	{
		DeleteEnd();
	}
	void findM(T x) {

		find(x);

	}
	void findMinM() {


		findMin();
	}
	void findMaxM() {
		findMax();
	}
};



