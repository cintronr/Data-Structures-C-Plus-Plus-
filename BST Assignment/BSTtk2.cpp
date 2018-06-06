/*Rico Cintron
Binary Search Tree Assignment
6/18/2017
University of Advancing Technology
*/
//Preprocessor directives
#include<iostream>
#include<string>
#include"Tree.h"


using namespace std;



int main() {
	
	cout << "*************" << endl;
	cout << "Rico Cintron" << endl;
	cout << "BST Assignment" << endl;
	cout << "6/18/2017" << endl;
	cout << "*************" << endl;

	
	
	cout << endl;
	cout << endl;
	Tree <string> myTree1;//myTree1 creation for string
	Tree <int> myTree2;//myTree2 creation for integer

	//pass integer values in from array to integer tree class, while also populating tree class string with characters A-F
	int popIntTree[8] = { 3,334,33,212,13,23,132,434 };
	for (int i = 0; i < 8; i++) {

		myTree2.insert(popIntTree[i]);

	}
	myTree1.insert("A");
	myTree1.insert("B");
	myTree1.insert("C");
	myTree1.insert("D");
	myTree1.insert("E");
	myTree1.insert("F");
	myTree1.insert("G");

	char selectionW = 'y';//char for while loop selection
	while (selectionW == 'y' || selectionW == 'Y')//while loop for menu return
	{
	//brief menu for user
	cout << "BST Character/String contents: ";
	myTree1.show(); cout << endl;
	cout << "BST integer contents: ";
	myTree2.show(); cout << endl;
	cout << endl;
	cout << "Please make a selection." << endl;
	cout << "1. Input characters/string." << endl;
	cout << "2. Input number." << endl;
	cout << "3. Delete character/string." << endl;
	cout << "4. Delete number." << endl;
	cout << "5. Display highest value." << endl;
	int selection=0;//int for user selection
	string input1;
	int input2;
	int input4;
	string input3;
		
		cin >> selection;//ask for user input
		switch (selection)
		{
		case 1:
			
			cout << "Please enter the desired character for BST insertion." << endl;
			cin >> input1;
			myTree1.insert(input1);
			break;
		case 2:
			cout << "Please enter the desired number for BST insertion." << endl;
			cin >> input2;
			myTree2.insert(input2);
			break;
		case 4:
			cout << "Please enter the desired number for BST deletion." << endl;
			cin >> input4;
			if (input4 == 3) {
				cout << "You cannot remove the first value!" << endl;
				break;
			}
			else {
				myTree2.DeleteI(input4);
				break;
			}
		case 3:
			cout << "Please enter the desired character for BST insertion." << endl;
			cin >> input3;
			if(input3 == "A"){
				cout << "You cannot remove the first value!" << endl;
				break;
			}
			else {
				
				myTree1.DeleteI(input3);
				break;
			}
		case 5:
			//Call functions for finding maximum values for both myTree1 and myTree2
			myTree2.findMaxI();
			myTree1.findMaxI();
			
			break;
		default:
			//default portion for selections not relating to any cases above.
			cout << "Invalid Entry!" << endl;




		}
		cout << "Would you like to continue? (y/n)" << endl;
		cin >> selectionW;
		system("cls");
	}
	
	


	system("pause");
	return 0;
}

