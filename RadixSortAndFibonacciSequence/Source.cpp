/*
Rico Cintron
Radix Sort with Fibonacci Search
8/16/2017
University of Advancing Technology
*/
#include<iostream>
#include<string>
#include<queue>
#include"RadixSort.h"
#include"Fibonacci Search.h"

using namespace std;










int main() {
	cout << "**********************************************************" << endl;
	cout << "Welcome to Radix Sort with Fibonacci Search implementation" << endl;
	cout << "**********************************************************" << endl;
	
	int numbersArray[] = {900,4832,2929,38,1,333,76,9399,4,5,7,9509,9002};
	int firstPass[13];
	int secondPass[13];
	int thirdPass[13];
	int finalPass[13];
	int n = sizeof(numbersArray) / sizeof(numbersArray[2]);// calculation to determine the size of an array.
	//buckets for temporary position retention for values 0-9
	int one[13];
	int two[13];
	int three[13];
	int four[13];
	int five[13];
	int six[13];
	int seven[13];
	int eight[13];
	int nine[13];
	int zero[13];
	//end buckets

	//Function call radixSort 1-4
	radixSort1(numbersArray, firstPass, secondPass, thirdPass, finalPass, n, one, two, three, four, five, six, seven, eight, nine, zero);
	radixSort2(numbersArray, firstPass, secondPass, thirdPass, finalPass, n, one, two, three, four, five, six, seven, eight, nine, zero);
	radixSort3(numbersArray, firstPass, secondPass, thirdPass, finalPass, n, one, two, three, four, five, six, seven, eight, nine, zero);
	radixSort4(numbersArray, firstPass, secondPass, thirdPass, finalPass, n, one, two, three, four, five, six, seven, eight, nine, zero);

	//Function call for pass display
	cout << endl;
	cout << "Initiating Radix Sort..." << endl;
	sleep_for(500ms);
	cout << "Unsorted Array: "; printArray(numbersArray, n); cout << endl;
	cout << "First Pass: "; printArray(firstPass, n); cout << endl;
	cout << "Second Pass: "; printArray(secondPass, n); cout << endl;
	cout << "Third Pass: "; printArray(thirdPass, n); cout << endl;
	cout << "Final Pass: "; printArray(finalPass, n); cout << endl;
	


	//Fibonacci Implementation
	string selection = "y";
	cout << endl;
	cout << "Initiating Fibonacci Search Implementation..." << endl;
	sleep_for(500ms);
	int z = sizeof(finalPass) / sizeof(finalPass[0]);// calculation to determine the size of an array.
	int x;//integer we wish to look for
	while (selection == "y" || selection == "Y") {
		cout << "Final Pass: "; printArray(finalPass, n); cout << endl;
		cout << "Please enter the number you wish to look for: " << endl;
		cin >> x;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Invalid selection, please enter numbers only." << endl;
			cin >> x;
		}
		if (FibonacciSearch(finalPass, x, z) == -1) {
			cout << "We didn't find " << x << endl;
		}
		else {
			cout << "Found value "<< x<< " at position " << FibonacciSearch(finalPass, x, z);
			cout << endl;
		}
		cout << "Would you like to look for another number? (Y/N)" << endl;
		cin >> selection;
		system("cls");
	}
	cout << "Thank you for using this program!" << endl;
	system("pause");
	return 0;



}
