#pragma once
//Preprocessor directives
#include <iostream>
#include <string>

using namespace std;
template <class T>//template <class> with data type "T"

class Tree//class "Tree"
{
private:
	struct Node//Struct Node with templated data option, node pointer for left branch and right branch.
	{
		T data; //data portion
		Node *left; //node* for left branch
		Node *right;// node* for right branch

		Node(T data, Node* left = NULL, Node* right = NULL) {//function which accepts data, sets sets left and right branch to null
			
			
			this->data = data;//member variable(data) equals data
			this->left = left;//member variable(left) equals left
			this->right = right;//member variable(right) equals right

		}
	};
	Node* root;//creates node pointer for root
	
	
	//Function for Inserting values, 
	void insert(Node*& tree, T data)
	{
	//if the tree is empty, insert node and reassign address from null to new node.
		if (tree == NULL) {//
			tree = new Node(data);
			return;
		}
		//if data is already in tree, state this...
		if(data == tree->data)
		{
			cout << "Data already in tree!" << endl;
			return;
		}
		// if value inserted is less than value in current node,
		//
		if (data < tree->data)
		{
			insert(tree->left, data);//if the value is less than, then insert data left
		}
		else
		{

			insert(tree->right, data);// if value if greater, insert data right
		}

	}

	Node* FindMinimum(Node* root) {//Search minimum function
		while (root->left != NULL)//while root->left is not empty, advance root->left
		{
			root = root->left;
		}
		return root;//return root



	}
	//

	//

	T FindMax(Node* root) {//Find max function
		if (root == NULL) {//if root is null, provide feedback stating such condition
			cout << "Missing contents of BST. Please add data.";
			return 0;
		}
		Node* current = root;// Node pointer current set to root
		while (current->right != NULL)//while current data right is not null
		{
			current = current->right;// Continue to right portion
	}
		cout << "Highest value is:" << current->data << endl;// Display highest value "Current data"
		return current->data;//return current->data
	
	}

	void display(Node* tree)
	{
		if (tree == NULL)//if tree is empty
		{
			
			return;//return
		}
		else//Otherwise
		{
			try {
			display(tree->left);//recursion, call function display (pass tree->left)
			}
			catch (int x) {
				cout << "You cannot remove the first value!" << endl;
			}
				cout << tree->data << " ";//cout tree data
				display(tree->right);//recursion, call function display(pass tree->right)
			
			
		}
	}


	struct Node* Delete(struct Node *root, T data) {//delete function paramaters accepted are pointer to root and data, function returns pointer to root node
		if (root == NULL) {
			return root;//if root is empty return root
		}
		else if (data < root->data) {//if data is less than (root->data), delete data in left portion
			root->left = Delete(root->left, data);//perform recursion, calling Delete function, set return as left child of current node
		}
		else if (data > root->data) {//if data is greater than (root->data), delete data in right portion
			root->right = Delete(root->right, data);//perform recursion, calling Delete function,set return as right child of current node
		}
		else{//value should be found, perform deletion
		
			if (root->left == NULL && root->right == NULL) {//if root portion left is empty and portion right is also empty, no children exist
				delete root;//delete this node
				root = NULL;// sets root as null
				return root;//return root
			}
			else if (root->left == NULL)//if left portion is empty
			{
				struct Node* temp = root;//store address of node that is being deleted by using this temp pointer
				root = root->right;//set right child as root
				delete temp;//delete temp
				return root;//return the root


			}
			else if (root->right == NULL)
			{
				struct Node *temp = root;//store address of node that is being deleted using temp pointer
				root = root->left;//left child set as root
				delete temp; //delete temp 
				return root;//return root

			}
			else {//else, if both right portion and left portion exist
				struct Node *temp = FindMinimum(root->right);// call function to find minimum data in tree and store in temp
				root->data = temp->data; //set data in node being deleted to minimum data
				root->right = Delete(root->right, temp->data);//delete minimum data from right portion 



			}
		}
		return root;//return root 
	



	}
	//Public accessors allowing function access while retaining integrity of private functions.
public:
	Tree() {
		root = NULL;
	}

	void insert(T data)
	{
		insert(root, data);

	}
	void show()
	{

		display(root);

	}
	void DeleteI(T data)
	{

		Delete(root, data);

	}
	void findMaxI()
	{
		 FindMax(root);
	}
};

