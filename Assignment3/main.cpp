/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
using namespace std; 
// you may include more libraries as needed

// declarations for main helper-functions
void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    int choice; 
    while(choice != 5)
    {
        displayMenu(); 
        cin >> choice; 
        switch(choice)
        {
            case 1: 
            {
                CountryNet.loadDefaultSetup(); 
                CountryNet.printPath(); 
                break;
            }

            case 2:
            {
                CountryNet.printPath();
                break;
            }

            case 3:
            {
                string country; 
                string message;

                cout << "Enter name of the country to receive the message:" << endl; 
                cin >> country; 
                cin.ignore(); 

                cout << "Enter the message to send:" << endl;
                getline(cin, message);

                cout << endl; 

                CountryNet.transmitMsg(country, message);
                break;
            }

            case 4: 
            {
                string prev; 
                Country *prevCountry; 
                string newCountry; 

                cout << "Enter a new country name:" << endl; 
                cin >> newCountry; 
                cin.ignore();

                cout << "Enter the previous country name (or First):" << endl; 
                getline(cin, prev);

                if (prev == "First")
                {
                    CountryNet.insertCountry(NULL, newCountry);
                    CountryNet.printPath();
                    break;

                }

                CountryNet.searchNetwork(prev);
                while(CountryNet.searchNetwork(prev) == NULL )
                {

                    cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
                    getline(cin,prev); 
                    CountryNet.searchNetwork(prev);
                }
                prevCountry = CountryNet.searchNetwork(prev);

                CountryNet.insertCountry(prevCountry, newCountry);
                CountryNet.printPath();
                break;

            }

            default: 
            {
                cout << "Quitting..." << endl;
                cout << "Goodbye!" << endl;
            }

        }
        
    }


    return 0;
}


/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
