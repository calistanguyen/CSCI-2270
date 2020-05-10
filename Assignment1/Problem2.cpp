#include <iostream>
#include <sstream>
#include <fstream>

using namespace std; 

struct Park
{
	string parkname; 
	string state; 
	int area;
};

//length: number of items stored in the array (index)
void addPark(Park parks[], string parkname, string state, int area, int length)
{
	parks[length].parkname = parkname;
	parks[length].state = state; 
	parks[length].area = area; 
}

//length: number of items stored in the array (index)
void printList(const Park parks[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << parks[i].parkname << " [" << parks[i].state<< "] area: " << parks[i].area << endl; 
	}
}

int main(int argc, char *argv[])
{
	Park parks[100];
	int minimum_area = stoi(argv[3]); 
	string inFile = argv[1];
	string outFile = argv[2];
	int idx = 0;

	ifstream myfile; 
	myfile.open(inFile);

	if (myfile.is_open())
	{
		string line = ""; 

		while(getline(myfile, line))
		{
			stringstream str(line);
			string temp1; //be the temp string for the park name
			string temp2; //temp string for the state
			string temp3; //temp string for the area

			getline(str, temp1, ',');
			getline(str, temp2, ',');
			getline(str,temp3, ',');

			addPark(parks, temp1, temp2, stoi(temp3), idx);

			idx++;
		}

		printList(parks, idx);

	}

	myfile.close(); 

	ofstream newfile(outFile);

	for (int i = 0; i < idx; i++)
	{
		if(parks[i].area > minimum_area)
		{
			newfile << parks[i].parkname << "," << parks[i].state << "," << parks[i].area << endl; 
		}
	}

	newfile.close(); 

	return 0; 
}