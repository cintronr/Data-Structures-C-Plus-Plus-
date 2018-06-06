/*
Rico Cintron
LL Experimentation
5/25/2017
University of Advancing Technology
*/
//Pre processor directives
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>


using namespace std;
struct Node* head;// Pointer to head node  
struct Node* tail;//Pointer to tail node
struct Node* mark;//Pointer for search funtion
struct Node* DeleteN;//Pointer for node deletion

struct Node {//struct node for linked list
	int data;//integer to hold numbers
	struct Node* next;// for next portion
	struct Node* prev;//for previous portion


};


struct Node* GetNewNode(int x) {
	//struct Node myNode;//local variable, cleared from memory when function is finished
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //reserving heap of memory, object stored for retention 
	newNode->data = x;//pass int x into data position
	newNode->prev = NULL;//set previous to null
	newNode->next = NULL;//set next to null
	return newNode;//return new node


}

void InsertAtHead(int x) {//function to insert at head
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

void InsertAtTail(int x)//function to insert at tail
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


void Print() {
	
	struct Node* temp = head;//Set struct Node temp to head address
	
	
	while (temp != NULL)//While temp is not equal to Null
	{
		//printf("%d ", temp->data);//print data in temp
		std::cout << temp->data;//set temp to next


	}
	std::cout << endl;//print new line

}

void PrintReverse() {
	
	struct Node* temp = head;
	if (temp == NULL) return;//if list is empty, exit
							 //Traverse till last node
	while (temp->next != NULL)//while next pos is not equal to null
	{
		temp = temp->next;//temp is temp(next)
	}
	//Traverse backward using previous pointer

	while (temp != NULL)//while temp is not equal to null
	{
		std::cout << temp->data;//print data from temp(data)

		temp = temp->prev;//(temp is temp(prev)
	}

	std::cout << endl;//print new line
}

void find(int number) {
	
	if (head == NULL) {//if head is empty, state such condition
		std::cout << "Your list is empty!";
		}
	mark = head;//mark is head
	int place=0;//Integer for place where number was found
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

	std::cout << "Not in list, sorry" << number;

}


void DeleteBegining() {
	
	
	if (head == NULL) {//if list is empty, state such condition
		std::cout << "List is empty";//std cout stating list is empty
	}
	else//otherwise
	{
		struct Node* DeleteN = head;//move head into temp  DeleteN
		head = head->next;//reposition head
		head->prev = NULL;//
		delete DeleteN;//clear data from memory, exception thrown when clearing, Troubleshoot.


	}
	







}

void DeleteEnd() {

	
	if (tail == NULL) {//if list is empty, state such condition
		std::cout << "List is empty";//std cout stating list is empty
	}
	else//otherwise
	{
		struct Node* DeleteN = tail;//move head into temp  DeleteN
		tail = tail->prev;//reposition head
		tail->next = NULL;//
		delete DeleteN;//clear data from memory, exception thrown when clearing, Troubleshoot.


	}
}
int main()
{
	head = NULL;// Empty list
	for (int i = 0; i < 10; i++) {//for loop, calling Insert at head,passing in number,incrementing by 1
		InsertAtHead(i);

	}
	int selection = 0;
	int NumFrLL = 0;
	int NumEnLL = 0;
	int Num2Find = 0;
	cout << "**********************************" << endl;
	cout << "Welcome to my linked list program!" << endl;
	cout << "**********************************" << endl;
	cout << endl;
	char Continue = 'y';
	while (Continue == 'y' || Continue == 'Y')
	{
	cout << "<Main Menu>" << endl;
	cout << endl;
	cout << "List contents:", PrintReverse();
	cout << endl;
	cout << "1.Add number to the front of linked list." << endl;
	cout << "2.Add number to the end of linked list." << endl;
	cout << "3.Print List." << endl;
	cout << "4.Print List starting from end." << endl;
	cout << "5.Delete from front of list." << endl;
	cout << "6.Delete from the end of list." << endl;
	cout << "7.Find number in list." << endl;
	
		cin >> selection;
		switch (selection) {
		case 1:

			cout << "Please enter desired number to be added to linked list" << endl;
			cin >> NumFrLL;
			InsertAtHead(NumFrLL);
			break;
		case 2:
			cout << "Please enter desired number to be added to linked list" << endl;
			cin >> NumEnLL;
			InsertAtTail(NumEnLL);
			break;
		case 3:
			cout << "List contents" << endl;
			PrintReverse();
			break;
		case 4:
			cout << "List contents in reverse order" << endl;
			Print();
			break;
		case 5:
			cout << "Delete from front of list." << endl;
			DeleteBegining();
			break;
		case 6:
			cout << "Delete from end of list." << endl;
			DeleteEnd();
			break;
		case 7:
			cout << "Please enter the number you wish to find:" << endl;
			cin >> Num2Find;
			find(Num2Find);
			break;
		default:
			cout << "Invalid Entry!";
			break;















		}
		
		cout << "Would you like to continue?" << endl;
		cin >> Continue;
		system("cls");
		
	}
	

	system("pause");
 	return 0;



}