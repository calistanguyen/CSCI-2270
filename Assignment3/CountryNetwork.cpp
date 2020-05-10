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
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
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
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */

//"United States", "Canada", "Brazil", "India", "China", "Austraila"
void CountryNetwork::loadDefaultSetup()
{
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
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
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
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
	if (head == nullptr)
	{
		cout << "Empty list" << endl; 
		return; 
	}

	Country *crawler = head; 

	if (searchNetwork(receiver) == NULL)
	{
		cout << "Country not found" << endl;
		return;

	}

	while(crawler->name != receiver && crawler->next != nullptr)
	{
		crawler->message = message; 
		crawler->numberMessages++;
		cout << crawler->name << " [# messages received: " << crawler->numberMessages << "] received: " << crawler->message << endl; 
		crawler = crawler->next; 

	}

	if (crawler->name == receiver)
	{
		crawler->message = message; 
		crawler->numberMessages++;
		cout << crawler->name << " [# messages received: " << crawler->numberMessages << "] received: " << crawler->message << endl; 
		return; 
	}

	return;

}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
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
