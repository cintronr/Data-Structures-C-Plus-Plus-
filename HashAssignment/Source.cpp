/*
Rico Cintron
Hash Table Assignment
7/1/2017
University of Advancing Technology
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include "Hash.h" 
#include <limits>







using namespace std;



int main() {
	cout << "**************************" << endl;
	cout << "Welcome to the Hash Table!" << endl;
	cout << "**************************" << endl;
	cout << endl;
	Hash test;// class creation
	// add several items via function call passing in name and number values
	string selection = "y";
	int selection2 = 0;
	string name;
	int number;
	while (selection == "y" || selection == "Y") {
		cout << "Make a selection from the menu below." << endl;
		cout << endl;
		cout << "1. Insert (Name, phone number)" << endl;
		cout << "2. Retrieve(Name)" << endl;
		cout << "3. Display table" << endl;
		cout << "4. Run Program Test" << endl;
	//cout << "Testing while loop" << endl;
	cin >> selection2;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Invalid entry! Please enter a number: " << endl;
		cin >> selection2;
	}//Switch error catch
		switch (selection2) {
		case 1:
			cout << "Please enter a name. No spaces! (example: JohnJames): ";
			cin >> name;
			cout << "Please enter 7 digit phone number. (example 1234444): ";
			cin >> number;
			while (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Invalid entry! Please enter a number: " << endl;
				cin >> number;
				//test.AddItem(name, number);
			}
			test.AddItem(name, number);

			break;
		case 2:
			cout << "Please enter the name you would like to find:";
			cin >> name;
			test.keySearch(name);
			break;
		case 3:
			test.displayTable();
			break;
		case 4:
			system("cls");
			cout << "Initiating test......................" << endl;
			cout << endl;
			cout << "************************************" << endl;
			cout << "Testing add user function and user lookup function." << endl;
			//Test add user
			test.AddItem("Test", 1111111);
			test.keySearch("Test");//Test name search with populated user
			cout << "If test above displays name 'Test' and number '1111111', test passed!" << endl;
			cout << endl;
			cout << "************************************" << endl;
			//Test name search with value not in table
			cout << "Testing lookup function when user data is not in table." << endl;
			cout << endl;
			test.keySearch("Test3");
			cout << "If function above displays: 'Key not found!', test passed!" << endl;
			break;

		default:
			cout << "Invalid entry. Please try again." << endl;
			break;
		
		}
	

	cout << "Would you like to continue? (Y/N)" << endl;
	cin >> selection;
	system("cls");






	}
	
	



	system("pause");
	return 0;

}



