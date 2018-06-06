/*
Rico Cintron
Twitter Graph Assignment
8/10/2017
University of Advancing Technology
*/
//Pre processor directives
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include"Header.h"


int main()
{
	
	LinkedList<char> myList2;//class creation for strings
	bool join;
	myList2.AQ1 = NULL;//set list2 head to null;
	

	int selection = 0;
	int Menu1 = 0;
	int Menu2 = 0;
	int NumFrLL = 0;
	int NumEnLL = 0;
	int Num2Find = 0;
	char StrFrLL = ' ';
	char StrEnLL = ' ';
	char Str2Find = ' ';

	//greeting
	cout << "**********************************" << endl;
	cout << "Welcome to my Twitter Graph program!" << endl;
	cout << "**********************************" << endl;
	cout << endl;
	char Continue = 'y';// char for while loop, initialized to 'y;
	while (Continue == 'y' || Continue == 'Y')//while continue is 'y' or 'Y', do the following..
	{
		cout << "MAIN MENU" << endl;
		cout << "List contents, Letter edition:", myList2.PrintM();
		cout << endl;
		cout << "1. Integer menu." << endl;
		cout << "2. Character menu. " << endl;
		cin >> Menu1;
		switch (Menu1) {
		case 1:
			cout << "Unused!!!" << endl;
			break;
		case 2:
			cout << "<Character Menu>" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "WARNING: You can only enter one character at a time!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << endl;

			cout << endl;
			cout << "1.Add LETTER to Aquaintance 1 of Twitter Graph." << endl;
			cout << "2.Add LETTER to Aquaintance 2 of Twitter Graph." << endl;
			cout << "3.Print Aquaintances on path 1." << endl;
			cout << "4.Print Aquaintances on path 2." << endl;
			cout << "5.Calculate distance." << endl;
			cin >> Menu2;
			//switch providing a menu for users
			switch (Menu2) {
			case 1:

				cout << "Please enter desired letter to be added to Twitter Graph Aquaintance 1." << endl;
				cin >> StrFrLL;
				myList2.InsertAtHeadM(StrFrLL);
				break;
			case 2:
				cout << "Please enter desired letter to be added to Twitter Graph Aquaintance 2." << endl;
				cin >> StrEnLL;
				myList2.InsertAtTailM(StrEnLL);
				break;
			case 3:
				cout << "List contents" << endl;
				myList2.PrintM();
				break;
			case 4:
				cout << "List contents in reverse order" << endl;
				myList2.PrintReverseM();
				break;
			case 5:
				cout << "Calculating distance" << endl;
				myList2.DeleteEndM();
				break;
			
			default:
				cout << "Invalid Entry!";
				break;

			}//end string menu
			cout << "Would you like to continue? (Y/N)" << endl;
			break;
		default:
			cout << "Invalid Entry!";
			cout << "Would you like to continue? (Y/N)" << endl;
			break;
		}//end MAIN menu switch case


		cin >> Continue;//cin user selection.
		cout << "Would you like to continue (Y/N)?" << endl;
		system("cls");//clear screen contents.

	}//end while loop
	system("pause");
	return 0;
}//end main
