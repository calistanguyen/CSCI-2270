#include <iostream>
#include <fstream>
#include <sstream>
#include "MovieTree.hpp"

using namespace std; 

void displayMenu()
{
	cout << "======Main Menu======" << endl; 
	cout << "1. Print the inventory" << endl; 
	cout << "2. Delete a movie" << endl; 
	cout << "3. Quit" << endl;
}

int main(int argc, char *argv[])
{
	MovieTree tree; 
	int choice; 

	ifstream myfile; 
	myfile.open(argv[1]);
	if(myfile.is_open())
	{
		string line = "";
		while(getline(myfile,line))
		{
			stringstream str(line);
			string temp1, temp2, temp3, temp4; 
			getline(str, temp1, ',');
			getline(str,temp2, ','); 
			getline(str,temp3, ','); 
			getline(str,temp4, ',');

			tree.addMovie(stoi(temp1), temp2, stoi(temp3), stof(temp4));
		}
	}

	myfile.close();

	while(choice!=3)
	{
		displayMenu();
		cin>>choice; 

		switch(choice)
		{
			case 1:
			{
				tree.printMovieInventory();
				break;
			}

			case 2: 
			{
				string title; 
				cout << "Enter title:" << endl;
				cin.ignore(); 
				getline(cin, title);

				tree.deleteMovie(title);
				break;
			}

			default: 
			{
				cout << "Goodbye!" << endl;
				break;
			}
		}
	}
}