/*
Rico Cintron
Sorting Assignment
7/14/2017
University of Advancing Technology
*/


//needed libraries
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<stdio.h>
#include<stdlib.h>
#include"Header.h"
#include <chrono>
#include <thread>


using namespace std;
using namespace std::this_thread;// allows sleep_for or sleep_until
using namespace std::chrono_literals;//enables use of nano seconds, ms, s, h, etc.
using std::chrono::system_clock;

LinkedList<int> InsertionSorttt;// Linked list creation for insertion sort
LinkedList<int> BubbleSorttt; // linked list creation for bubble sort
bool LLFilled = false; //boolean for linked list filled status
bool passed = false; // boolean for place marker
LinkedList<int> test;//LL for test
//sorting algorithm one (insertion sort)
void printANDtransfer(int numberArray[], int size) {
	for (int i = 0; i < size; i++) {
		if (size <= 10) {
			cout << numberArray[i] << " ";
		}
		else {
			if (LLFilled == true && size >=999 && passed == true) {
				InsertionSorttt.InsertAtHead(numberArray[i]);
			}
		}
	}
}

//sorting algorithm one (insertion sort)
void InsertionSort(int numberArray[], int size) {//function start
	
	if (size >= 999) {
		LLFilled = true;
	}
	clock_t begin = clock();//start clock
	int position; //integer for position
	int temp; //integer to hold temp value
	for (int i = 1; i < size; i++) {//for loop, functions with size of array
		position = i;//sets position integer value equal to i
		while (position > 0 && numberArray[position - 1] > numberArray[position]) { //while position value is greater than 0 and while value at position 0 of array is greater than value at position 1 of the array.
			temp = numberArray[position];//set temp equal value of array position with greater value
			numberArray[position] = numberArray[position - 1];//set array postition value to greater value
			numberArray[position - 1] = temp;// set first position equal to lesser value or temp value
			position--;//decrement position value for proper cylcing
		}
	}
	clock_t end = clock(); //stop clock
	double elapsedTime = double(end - begin) / CLOCKS_PER_SEC;//elapsed time equals double end minus begin
	
	cout << "Insertion sort algorithm with " << size << " objects took " << elapsedTime << " seconds to sort." << endl; //display size and elapsed time

}//function end

 //sorting algorithm two
void bubblesort(int numberArray[], int size) {//function start enabling array and size to be passed in
	
	clock_t begin = clock();//start clock
	for (int i = 0; i < size; i++) {//for loop starting at 0 and ending when size of array is reached.
		for (int a = 0; a < size - i - 1; a++) {//nested for loop starting at 0 and stoping at array size minus value of i and minus 1
			if (numberArray[a] > numberArray[a + 1]) {//if array position a is greater than position a plus one
				int temp = numberArray[a];//temp is set to value in array position a
				numberArray[a] = numberArray[a + 1];//position a is set with value in position a+1
				numberArray[a + 1] = temp; //position a+1 is set to value held by temp
			}
		}

	}
	clock_t end = clock();//stop clock
	double elapsedTime = double(end - begin) / CLOCKS_PER_SEC;//double esapsed time is double end minus begin times
	cout << "Bubble sort algorithm with " << size << " objects took " << elapsedTime << " seconds to sort." << endl;// display size and elapsed time
	
}//function end

int main() {
	///////////////////////////////////Program testing phase////////////////////

	cout << "System test commencing now!"<<endl;
	cout << endl;
	LinkedList<int> test;//LL for test
	cout << "Create test Linked List...Passed" << endl;
	cout << endl;
	const int sizeTest = 10;// constant integer with a value of 10
	int numbersInsertionTest[sizeTest];//array with a size of 10
								  //random number generation

	srand(unsigned(time(0)));
	cout << "First ten random numbers pushed to array: ";
	for (int i = 0; i < sizeTest; i++) {
		numbersInsertionTest[i] = (rand() % 80) + 1;
		cout << numbersInsertionTest[i] << " ";
	}
	cout << endl;
	cout << "If ten random integers are displayed, test passed." << endl;
	cout << endl;
	InsertionSort(numbersInsertionTest, sizeTest);//function call
	cout << "If ten integers are displayed in order, test passed." << endl;
	printANDtransfer(numbersInsertionTest, sizeTest);
	sleep_for(8s);
	cout << endl;
	cout << "Testing finished. Please wait";
	for (int i = 0; i < 20; i++)
	{
		cout << ".";
		sleep_for(300ms);

	}
	cout << endl;
	sleep_for(7s);
	system("cls");
	/////////////////////////////////////////////Finish testing, begin main program//////////

	int selection;//integer for menu selection
	char looper = 'y';// char for while loop 
	cout << "Sorting Algorithm Assignment!" << endl;
	cout << "In this program, we are implementing the Insertion Sort and Bubble Sort algorithms." << endl;
	cout << "We will pass ten, one hundred, and one thousand random numbers into each algorithm and determine which is faster at sorting." << endl;
	cout << "We will also allow you to transfer these sorted values into a linked list from a previous assignment." << endl;
	cout << endl;
	InsertionSorttt.head = NULL;//head set to NULL
	BubbleSorttt.head = NULL;//head set to NULL
	////////////////////////////////////////////////////////////Insertion Sort 10///////////////////////////////////
	const int size1 = 10;// constant integer with a value of 10
	int numbersInsertion10[size1];//array with a size of 10
					  //random number generation

	srand(unsigned(time(0)));
	cout << "First ten random numbers pushed to array: " << endl;
	for (int i = 0; i < size1; i++) {
		numbersInsertion10[i] = (rand() % 80) + 1;
		cout << numbersInsertion10[i] << " ";
	}
	cout << endl;
	InsertionSort(numbersInsertion10, size1);//function call
	
	///////////////////////////////////////////////////////////Insertion sort 100/////////////////////////////////////
	const int size2 = 100;// constant integer with a value of 10
	int numbersInsertion100[size2];//array with a size of 10
								 //random number generation
	srand(unsigned(time(0)));
	for (int i = 0; i < size2; i++) {
		numbersInsertion100[i] = (rand() % 80) + 1;
		//cout << numbersInsertion100[i] << " ";
	}
	InsertionSort(numbersInsertion100, size2);//function call

	//////////////////////////////////////////////////////////////////Bubble Sort 10
	const int size4 = 10;// constant integer with a value of 10
	int numbersBubble10[size4];//array with a size of 10
					  //random number generation
					  //generate random integers and push into arrays?
	srand(unsigned(time(0)));
	for (int i = 0; i < size4; i++) {
		numbersBubble10[i] = (rand() % 80) + 1;
		//cout << numbersBubble10[i] << " ";
	}
	bubblesort(numbersBubble10, size4);
	
	//////////////////////////////////////////////////////////////////Bubble Sort 100
	const int size5 = 100;// constant integer with a value of 10
	int numbersBubble100[size5];//array with a size of 10
							   //random number generation
							   //generate random integers and push into arrays?
	srand(unsigned(time(0)));
	for (int i = 0; i < size5; i++) {
		numbersBubble100[i] = (rand() % 80) + 1;
		//cout << numbersBubble100[i] << " ";
	}
	bubblesort(numbersBubble100, size5);
	
	//////////////////////////////////////////////////////////////////Bubble Sort 1000
	const int size6 = 1000;// constant integer with a value of 10
	int numbersBubble1000[size6];//array with a size of 10
								//random number generation
								//generate random integers and push into arrays?
	srand(unsigned(time(0)));
	for (int i = 0; i < size6; i++) {
		numbersBubble1000[i] = (rand() % 80) + 1;
		//cout << numbersBubble1000[i] << " ";
	}
	bubblesort(numbersBubble1000, size6);
	
	//////////////////////////////////////////////////////////////////////Insertion Sort 1000////////////////////////////////
	const int size3 = 1000;// constant integer with a value of 10
	int numbersInsertion1000[size3];//array with a size of 10
									//random number generation

	srand(unsigned(time(0)));
	for (int i = 0; i < size3; i++) {
		numbersInsertion1000[i] = (rand() % 80) + 1;
		//cout << numbersInsertion1000[i] << " ";
	}
	InsertionSort(numbersInsertion1000, size3);//function call
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	

	while (looper == 'y' || looper == 'Y')
	{
		string entry = "";
		cout << endl;
		cout << "Please make a selection from the following menu: " << endl;
		cout << "1. Display and transfer sorted integers to Linked List." << endl;
		cout << "2. Display contents of Linked List (Warning: List is about 1000 integers long)." << endl;
		cin >> entry;
		if (entry >= "1" || entry <= "2"){
			int selection = atoi(entry.c_str());
			switch (selection) {
			case 1:
				//Call function enabling display of functions with 10 items or less, also pushes sorted values into linked list
				printANDtransfer(numbersInsertion10, size1); cout << endl;//function call
				printANDtransfer(numbersInsertion100, size2);//function call
				printANDtransfer(numbersBubble10, size4); cout << endl;
				printANDtransfer(numbersBubble100, size5);
				printANDtransfer(numbersBubble1000, size6);
				passed = true;
				printANDtransfer(numbersInsertion1000, size3);//function call
				break;
			case 2:
				//display contents of linked list.
				cout << "Begin LL display" << endl;
				InsertionSorttt.PrintM();
				break;
			default:
				cout << "Invalid entry!" << endl;
				break;



			}
	}
		else cout << "Invalid entry, please try again!" << endl;

	cout << "Would you like to run this program again? (y/n): " << endl;
	cin >> looper;
	system("cls");














	}
	cout << "Thanks for using this program! Goodbye!" << endl;


	system("pause");
	return 0;



}





