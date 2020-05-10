/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
	head = nullptr; 
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
	if (head == nullptr)
	{
		return true; 
	}

	return false; 

}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName) {

	Country* newCountry = new Country; 
	newCountry->name = countryName; 

	if (previous == NULL) //inserting head
	{
		if (head == nullptr)
		{
			head = newCountry; 
			head->next = nullptr;
		}
		else
		{
			newCountry->next = head; 
			head = newCountry;
		}

		cout << "adding: " << countryName << " (HEAD)" << endl;
	}
	else //inserting anywhere else :D
	{
		if (previous->next != nullptr)
		{
			newCountry->next = previous->next; 
			previous->next = newCountry; 
		}
		else
		{
			newCountry->next = nullptr; 
			previous->next = newCountry;

		}
		cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
	}
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName) {
	if (searchNetwork(countryName) == NULL)
	{
		cout << "Country does not exist." << endl; 
		return; 
	}

	Country *toBeDeleted = searchNetwork(countryName); //create a temporary pointer that points to the to be deleted pointer

	if (toBeDeleted == head)
	{
		if (head->next == nullptr)
		{
			head = nullptr;
			delete toBeDeleted; 
			return;  
		}
		else
		{
			head = head->next; 
			delete toBeDeleted; 
			return; 
		}
	}

	else
	{
		Country *crawler = head; //a pointer that traverses through the linked list

		while(crawler->next != toBeDeleted)
		{
			crawler = crawler->next; 
		}

		crawler->next = toBeDeleted->next; 
		delete toBeDeleted; 
		return;

	}


}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup() {
	deleteEntireNetwork(); 

	insertCountry(NULL, "United States");
	insertCountry(head, "Canada");
	insertCountry(head->next, "Brazil");
	insertCountry(head->next->next, "India");
	insertCountry(head->next->next->next, "China");
	insertCountry(head->next->next->next->next, "Australia");
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName) {

	Country *crawler = head;//temporary pointer that will traverse through the LL
	if (head == nullptr)
	{
		return NULL;
	}
	while(crawler->name != countryName  && crawler->next != nullptr)
	{
		crawler = crawler->next; 
	}
	if (crawler->name == countryName)
	{
		return crawler;
	}

	return NULL; 
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork() {
	Country *crawler = head; 
	Country *temp = head; 

	if (head == nullptr)
	{
		return;
	}

	while (crawler->next != nullptr)
	{
		cout << "deleting: " << crawler->name << endl; 
		temp = crawler; 
		crawler = crawler->next; 
		delete temp; 
	}

	if(crawler->next == nullptr)
	{
		cout << "deleting: " << crawler->name << endl; 
		delete crawler;
		head = nullptr; 
	}
	cout << "Deleted network" << endl;
	
}


/*
 * Purpose: Rotate the linked list i.e. move 'n' elements from
 * the back of the the linked to the front in the same order.
 * @param number elements to be moved from the end of the list to the beginning
 * @return none
 */
 void CountryNetwork :: rotateNetwork(int n) {
 	if (head == nullptr)
 	{
 		cout << "Linked List is Empty" << endl; 
 		return; 
 	}

 	int length = 0; //calculate the length of the linked list 
 	Country *temp = head; 
 	while (temp->next != nullptr)
 	{
 		length++; 
 		temp = temp->next; 
 	}
 	if(temp->next == nullptr)
 	{
 		length++; 
 	}

 	if (n < 1 || n >= length) //if n is not under the length or less than 1
 	{
 		cout << "Rotate not possible" << endl;
 		return;  
 	}

 	else
 	{
 		Country* oldHead = head; //have a pointer that points to the old head 
 		temp = head; //set temp equal to the head again
 		int counter = 0;  
 		while (temp->next != nullptr && counter != n) //traverse the linked list until you reach the new head
 		{
 			temp = temp->next; 
 			counter++; 
 		}

 		head = temp; //set head equal to the new head
 		temp = head; //set the temp to the now head

 		while(temp->next != nullptr)
 		{
 			temp = temp->next; 
 		}

 		temp->next = oldHead; //once the end of the list reaches null, set it equal to the old head 

 		Country *crawler = oldHead; //have a crawler pointer that goes from the old head

 		while (crawler->next != head) 
 		{
 			crawler = crawler->next; 
 		}
 		crawler->next = nullptr; //once crawler reaches the current head, set the pointer equal to null

 		cout << "Rotate Complete" << endl;

 	}

}

/*
 * Purpose: reverse the entire network
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork() {
	if (head == nullptr)
	{
		return;
	}
	int length = 0; //calculate the length of the linked list 
 	Country *temp = head; 
 	Country *oldHead = head;
 	while (temp->next != nullptr)
 	{
 		length++; 
 		temp = temp->next; 
 	}

 	head = temp;
 	temp = oldHead; 
 	Country *tail = head; 
 	int counter = 0; 

 	while(counter != length - 1)
 	{
 		while (temp->next->next != head)
	 	{
	 		temp = temp->next; 
	 	}

	 	tail->next = temp->next;
	 	temp->next = head;
	 	tail = tail->next; 
	 	tail->next = nullptr;
	 	temp = oldHead;  
	 	counter++;  

 	}

 	tail->next = oldHead;
 	tail = tail->next; 
 	tail->next = nullptr; 
 	return; 

}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() {
	
	cout << "== CURRENT PATH ==" << endl;
	if (head == nullptr)
	{
		cout << "nothing in path" << endl; 
		cout << "===" << endl;
		return;
	}
	
	Country *crawler = head; 
	while (crawler->next != nullptr)
	{
		cout << crawler->name << " -> ";
		crawler = crawler->next; 
	}
	cout << crawler->name << " -> "; 
	cout << "NULL" << endl;
	cout << "===" << endl;

	return;

}
