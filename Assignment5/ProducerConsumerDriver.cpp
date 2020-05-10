/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
	int choice; 

	ProducerConsumer ProdCon; 

	while (choice!=3)
	{
		menu(); 
		cin >> choice; 

		switch(choice)
		{
			case 1: 
			{
				string numItems;
				cout << "Enter the number of items to be produced:" << endl; 
				cin.ignore(); 
				getline(cin, numItems); 

				for (int i = 0; i < stoi(numItems); i++)
				{
					string item;
					cout << "Item" << i+1 << ":"<< endl;
					getline(cin, item); 
					ProdCon.enqueue(item); 
				}

				break; 

			}

			case 2: 
			{
				string numItems; 
				cout << "Enter the number of items to be consumed:" << endl;
				cin.ignore(); 
				getline(cin, numItems); 
				if (stoi(numItems) > ProdCon.queueSize())
				{
					int size = ProdCon.queueSize(); 
					for (int i = 0; i < size; i++)
					{
						cout << "Consumed: " << ProdCon.peek() << endl;
						ProdCon.dequeue(); 
					}
					cout<< "No more items to consume from queue" << endl;
					break; 
				}

				else
				{
					for (int i = 0; i < stoi(numItems); i++)
					{
						cout << "Consumed: " << ProdCon.peek() << endl;
						ProdCon.dequeue(); 
					}

					break;

				}
			}

			default: 
			{
				cout << "Number of items in the queue:" << ProdCon.queueSize() << endl; 
				break; 

			}
		}

	}



}
