#include <iostream> // predefined header file (defined for you)
using namespace std;

#include "SLL.hpp" // your own header file
// <> vs "" -- compiler looks for the file in the C++ implementation
// vs in the current directory


SLL::SLL(){ // constructor definition
	head = nullptr; 
}

SLL::~SLL(){
	Node *crawler; 
	while(head!=nullptr){
		crawler = head->next; 
		delete head; 
		head = crawler; 
	}

}

Node* SLL::search(string sKey){

	Node* crawler = head; // temporary pointer that allows us to start from the head and not change the LL

	while(crawler != nullptr && crawler->key != sKey){
		crawler = crawler -> next; 
	}

	return crawler; 


}

void SLL::displayList(){

	Node* crawler = head; 
	while (crawler != nullptr){
		cout << crawler -> key << "->";
		crawler = crawler->next; 
	}

	cout << "END" << endl; 

}


void SLL::insert(Node* afterMe, string newValue){
	if(head == nullptr) {
		//empty list
		head = new Node; 
		head->key = newValue; 
		head->next = nullptr; 

	}

	else if(afterMe == nullptr){
		//insert before head
		//if afterMe == nullptr, means user wants
		//to insert new node before the head (at the beginning of the list)
		Node *newNode = new Node; 
		newNode->key = newValue; 
		newNode->next = head; 
		head = newNode; 
	}

	else{
		Node *newNode = new Node; 
		newNode->key = newValue; 
		newNode->next = afterMe->next; 
		afterMe->next = newNode;
	}


}

void SLL::deleteNode(Node *deleteNode)
{
	if (deleteNode != nullptr){
		//case 1: head is the node to be deleted 
		if (deleteNode == head){
			head = head->next; 
			delete deleteNode; //since deleteNode points to the head 
		}
		else{
			Node *crawler = head; 
			while(crawler->next != deleteNode){ //allows us to stop right before the to be deleted node
				crawler = crawler->next;
			}
			//reconnect the LL around the node about to be removed 
			crawler->next = deleteNode->next; 
			//deallocate 
			delete deleteNode; 

		}

	}

	else{
		cout << "Node doesn't exist. Nothing to do." << endl; 
	}
}




