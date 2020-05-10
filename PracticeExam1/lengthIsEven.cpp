#include <iostream>
using namespace std; 

struct Node
{
	int key; 
	Node *next; 
};

bool lengthIsEven(Node *head)
{
	Node *temp = head; 

	if (head == nullptr)
	{
		return true; 
	}

	int length = 1; 
	while (temp->next != nullptr)
	{
		temp = temp->next; 
		length++; 
	}

	if(length % 2 == 0)
	{
		return true; 
	}

	return false; 

}


int main()
{
	Node *head = nullptr; 

	Node *n1 = new Node; 
	n1->next = nullptr; 
	head = n1; 

	//test 1
	// Just the head should = false
	cout << "Test Case False: "; 
	cout<< lengthIsEven(head) << endl;

	//test 2
	//nothing = true
	head = nullptr; 
	cout << "Test Case True: ";
	cout << lengthIsEven(head) << endl;

	//test 3
	//Odd length = false 
	Node *n2 = new Node;
	Node *n3 = new Node; 

	head = n1; 
	head->next = n2; 
	n2->next = n3; 
	n3->next = nullptr;

	cout << "Test Case False: ";
	cout << lengthIsEven(head) << endl;

	//test 4
	//delete a node to make it even and return true

	Node *temp = head; 
	head = head->next; 
	delete temp;
	 
	cout << "Test Case True: ";
	cout << lengthIsEven(head) << endl;

}