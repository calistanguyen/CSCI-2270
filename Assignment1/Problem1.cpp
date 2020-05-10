#include <iostream>
#include <fstream>

using namespace std; 

int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{

	if (numEntries == 0)
	{
		myArray[numEntries] = newValue;
		cout << myArray[0] << " ";

		numEntries++;
	}

	else
	{
		myArray[numEntries] = newValue;
		for (int i = numEntries - 1; i >= 0; i--)
		{
			int comparedValue = myArray[i]; //the value in the array being compared to the new value
			if(newValue < comparedValue) 
			{
				myArray[i+1] = comparedValue; //switch the positions of the bigger value and the smaller value 
				myArray[i] = newValue; 
			}

		}

		numEntries++;

		for (int i = 0; i < numEntries; i ++)
		{
			if (i != numEntries - 1)
			{
				cout << myArray[i] << ",";
			}
			else
			{
				cout << myArray[i];
			}
		}
	}


	cout <<endl; 

    return numEntries;
};


int main(int argc, char *argv[])
{
	//declare numbers array with an index size of 100
	int numbers[100]; 

	//read in the file using the readFile function.
	string fileName = argv[1]; 
	ifstream myFile; 
	myFile.open(fileName);
	if (myFile.is_open())
	{
		string temp;
		int idx = 0; //counter

		while (getline(myFile, temp, '\n')) //as the program reads the file line by line, sort the numbers into the array and incrament the idx using 
											//the insertIntoSortedArray function
		{
			idx = insertIntoSortedArray(numbers, idx, stoi(temp));

		}

	}
	else
	{
		cout << "Failed to open the file." << endl; 
	}

	myFile.close();

	return 0; 
}
