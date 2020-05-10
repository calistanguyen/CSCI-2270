#include <iostream>
using namespace std;

struct Node{
	int key;
	Node *next;
};

Node *deleteNegatives(Node *head){
	Node *temp = head;

	while(head->key < 0)
	{
		if (head->next == nullptr)
		{
			head = nullptr;
			return head;  
		}
		else
		{
			head = head->next; 
			delete temp;
			temp = head;  
		}
	}

	while (temp->next != nullptr)
	{
		if(temp->key < 0)
		{
			Node *toDelete = temp; 
			Node *temp2 = head; 
			while (temp2->next != temp)
			{
				temp2 = temp2->next; 
			}
			temp2->next = temp2->next->next; 
			delete toDelete; 
		}

		temp = temp->next; 

	}

	if(temp->next == nullptr)
	{
		if(temp->key < 0)
		{
			Node *temp2 = head; 
			while(temp2->next!= temp)
			{
				temp2 = temp2->next; 
			}
			temp2->next = nullptr; 
			delete temp; 
		}
	}
	return head;

}

int main(){
	cout << endl; 

	//Test Case 1
	//Deleting the head  
	Node *n1 = new Node; 
	Node *head = n1; 
	n1->key = -5; 
	n1->next = nullptr;

	cout << "///TEST CASE 1///"<< endl; 
	cout << "Linked List before deletion: " << endl; 
	cout << head->key << " -> " << "NULL" << endl;
	cout << "Linked List after deletion: " << endl;   

	head = deleteNegatives(head); 
	if (head!=nullptr)
	{
		Node *temp = head; 
		cout << head->key << " -> " << "NULL" << endl; 
		cout << "FAIL" << endl; 
	}
	else
	{
		cout << "NULL" << endl;
		cout << "Successfully deleted" << endl; 

	}

	//Test Case 2
	cout << endl; 

	Node *a1 = new Node; 
	Node *a2 = new Node; 
	Node *a3 = new Node; 
	Node *a4 = new Node; 

	a1->key = -1; 
	a1->next = a2; 

	a2->key = 2; 
	a2->next = a3; 

	a3->key = -3; 
	a3->next = a4; 

	a4->key = 4; 
	a4->next = nullptr; 

	Node *head2 = a1; 

	cout << "///TEST CASE 2///"<< endl; 
	cout << "Linked List before deletion: " << endl; 
	Node*temp = head2; 

	while (temp->next != nullptr)
	{
		cout << temp->key << " -> "; 
		temp = temp->next; 
	}
	cout << temp->key << " -> " << "NULL" << endl; 

	cout << "Linked List after deletion: " << endl;   
	head2 = deleteNegatives(head2); 
	temp = head2; 
	if (head2->key!=2)
	{
		while (temp->next != nullptr)
		{
			cout << temp->key << " -> "; 
			temp = temp->next; 
		}
		cout << temp->key << " -> " << "NULL" << endl;
		cout << "FAIL" << endl; 

	}
	else
	{
		while (temp->next != nullptr)
		{
			cout << temp->key << " -> "; 
			temp = temp->next; 
		}
		cout << temp->key << " -> " << "NULL" << endl;
		cout << "Successfully deleted all negatives!" << endl; 

	}

	//Test Case 3
	cout << endl; 

	Node *b1 = new Node; 
	Node *b2 = new Node; 
	Node *b3 = new Node; 

	b1->key = 1;
	b1->next= b2;  
	b2->key = 2;
	b2->next = b3; 
	b3->key = 3;
	b3->next = nullptr; 

	Node *head3 = b1; 

	cout << "///TEST CASE 3///"<< endl; 
	cout << "Linked List before deletion: " << endl; 
	temp = head3; 

	while (temp->next != nullptr)
	{
		cout << temp->key << " -> "; 
		temp = temp->next; 
	}
	cout << temp->key << " -> " << "NULL" << endl; 

	cout << "Linked List after deletion: " << endl;   
	head3 = deleteNegatives(head3); 
	temp = head3; 
	if (head3->key!=1)
	{
		while (temp->next != nullptr)
		{
			cout << temp->key << " -> "; 
			temp = temp->next; 
		}
		cout << temp->key << " -> " << "NULL" << endl;
		cout << "FAIL" << endl; 

	}
	else
	{
		while (temp->next != nullptr)
		{
			cout << temp->key << " -> "; 
			temp = temp->next; 
		}
		cout << temp->key << " -> " << "NULL" << endl;
		cout << "Nothing deleted!" << endl; 

	}





}
