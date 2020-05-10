#include <iostream>
#include <fstream>
#include <sstream>
#include "MovieTree.hpp"
using namespace std; 



void printMenu()
{
	cout << "======Main Menu======" << endl ;
	cout << "1. Find a movie" << endl ;
	cout << "2. Query movies" << endl ;
	cout << "3. Print the inventory" << endl ;
	cout << "4. Average Rating of movies" << endl ;
	cout << "5. Quit" << endl ;

}
int main(int argc, char *argv[])
{
	MovieTree tree; 
	int choice;

	ifstream myfile; 
	myfile.open(argv[1]);
	if (myfile.is_open())
	{
		string line = ""; 

		while (getline(myfile, line))
		{
			stringstream str(line);
			string temp1; 
			string temp2; 
			string temp3; 
			string temp4; 

			getline(str, temp1, ',');
			getline(str, temp2, ',');
			getline(str, temp3, ',');
			getline(str, temp4, ',');

			tree.addMovieNode(stoi(temp1), temp2, stoi(temp3), stof(temp4));
		}
	}

	myfile.close(); 


	while(choice!=5)
	{
		printMenu(); 
		cin >> choice; 

		switch(choice)
		{
			case 1: 
			{
				string title;
				cout << "Enter title:" << endl;
				cin.ignore(); 
				getline(cin, title);

				tree.findMovie(title);
				break; 
			}

			case 2: 
			{
				float rating; 
				int year;
				cin.ignore(); 
				cout << "Enter minimum rating:" << endl ;
				cin >> rating;
				
				cout << "Enter minimum year:" << endl ;
				cin >> year; 

				tree.queryMovies(rating, year);
				break; 
			}

			case 3: 
			{
				tree.printMovieInventory();
				break; 
			}

			case 4: 
			{
				tree.averageRating();
				break; 
			}

			default: 
			{
				cout << "Goodbye!" << endl ;
				break;
			}
		}
	}


}