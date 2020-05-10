#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList(){
        head = NULL;
    }

LinkedList::~LinkedList(){
	Node* crawler;
	while(head!=nullptr){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}

// Add a new Node to the list
void LinkedList::insert(Node* prev, int newKey){

    //Check if head is Null i.e list is empty
    if(head == NULL){
        head = new Node;
        head->key = newKey;
        head->next = NULL;
    }

        // if list is not empty, look for prev and append our Node there
    else if(prev == NULL)
    {
        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = head;
        head = newNode;
    }

    else{

        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = prev->next;
        prev->next = newNode;

    }
}



// Building list
void LinkedList::loadList(int* keys , int length) {

    insert(NULL, keys[0]);

    Node* prev = head;

    for(int i = 1; i < length; i++)
    {
        insert(prev, keys[i]);
        prev = prev->next;
    }

}

// Print the keys in your list
void LinkedList::printList(){
    Node* temp = head;

    if (head == nullptr)
    {
        cout << "NULL" << endl; 
        return;
    }
    while(temp->next != NULL){
        cout<< temp->key <<" -> ";
        temp = temp->next;
    }

    cout<<temp->key<<" -> NULL"<<endl;
}

///////////////////////////////////////////////////////////////
// TODO : Complete the following function
void LinkedList::removeNthFromEnd(int n){
    int counter = 0; //have a counter that counts n from the head
    int length = 1; //have a length variable that starts at 1 to account for the head

    if (head == nullptr) //if the list is already empty
    {
        cout << "List is already empty." << endl; 
        return; 
    }

    Node *temp = head; 
    while (temp->next != NULL)
    {
        length++; //incrament the length as you traverse through the linked list 
        temp = temp->next; 
    }


    if (n == 1) //the last node 
    {
        temp = head;
        if (length == 1) //only the head
        {
            head = nullptr; //if the head is the only node on the lest 
            delete temp; 
            return;
        }

        while (temp->next->next!= nullptr) //gets to the second to last node 
        {
            temp = temp->next; 
        }
        Node* temp2 = temp->next; //the node to be deleted which will be at the end 
        temp->next = nullptr; 
        delete temp2; 

        return; 
    }

    if (n == length)
    {
        temp = head;
        if (head->next == nullptr) //if n is the length, then it is to delete the head
        {
            head = nullptr; //if the head is the only node on the lest 
            delete temp; 
            return;
        }
        else
        {
            head=head->next; 
            delete temp; 
            return;
        }
    }

    else 
    {
        temp = head; 
        for (int i = 0; i < length - n; i++) //length -n is the node that is to be deleted from the head
        {
            temp = temp->next; 
        }

        Node *temp2 = head; //temp2 traverses the linked list until before the node to be deleted. 
        while (temp2->next != temp)
        {
            temp2=temp2->next; 
        }
        temp2->next = temp->next; 
        delete temp; 
        return; 



    }




 }