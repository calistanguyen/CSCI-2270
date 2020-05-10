/****************************************************************/
/*                   Assignment 4 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
  

    int choice;

    while (choice != 8)
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
                string newCountry;
                string prevCountry;
                cout << "Enter a new country name:" << endl;
                cin.ignore();
                getline(cin, newCountry);

                cout << "Enter the previous country name (or First):" << endl;

                getline(cin, prevCountry);

                Country *prevPtr = CountryNet.searchNetwork(prevCountry);

                while (prevPtr == NULL && prevCountry != "First")
                {
                    cout << "INVALID country...Please enter a VALID previous country name:" << endl;
                    cin >>prevCountry;
                    prevPtr = CountryNet.searchNetwork(prevCountry);
                }
                if (prevCountry == "First")
                {
                    CountryNet.insertCountry(NULL, newCountry);
                }
                else
                {
                    CountryNet.insertCountry(prevPtr, newCountry);
                }

                CountryNet.printPath();
                break;
            }

            case 4:
            {
                string deletedCountry;
                cout << "Enter a country name:" << endl;
                cin.ignore();
                getline(cin, deletedCountry);


                CountryNet.deleteCountry(deletedCountry);
                CountryNet.printPath();
                break;

            }

            case 5:
            {
                CountryNet.reverseEntireNetwork();
                CountryNet.printPath();
                break;
            }

            case 6:
            {
                int n;
                cout << "Enter the count of values to be rotated:" << endl;
                cin.ignore();
                cin >>n;

                CountryNet.rotateNetwork(n);
                CountryNet.printPath();
                break;
            }

            case 7:
            {
                cout << "Network before deletion" << endl;
                CountryNet.printPath();
                CountryNet.deleteEntireNetwork();
                cout << "Network after deletion" << endl;
                CountryNet.printPath();
                break;
            }

            default:
            {
                cout << "Quitting... cleaning up path: " << endl;

                CountryNet.printPath();
                CountryNet.deleteEntireNetwork();

                if (CountryNet.isEmpty() == true)
                {
                    cout << "Path cleaned" << endl;
                }
                else
                {
                    cout << "Error: Path NOT cleaned" << endl;
                }

                cout << "Goodbye!" << endl;
                break;
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
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network" << endl;
    cout << " 6. Rotate Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
