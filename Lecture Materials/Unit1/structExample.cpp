// Read in student info from txt file and store in an 
// array of structs.

// TO BE COMPLETED IN LECTURE

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Student{
	int idNumber;
	string name;
	string dept;
};


// Function prototypes

// Read in file-
// input arguments:
//  1)array of strings
//  2)array length
//  3)name of text file
void readInFile(Student strArr[], int arrL, string fileName);

int main(int argc, char *argv[])
{
	if(argc != 2){
		cout << "incorrect number of arguments " << endl;
		return -1;
	}
	else{
		
	//fixed array size 
	int N = 10;

	//Declare array pf structs for storing student info
	Student strArr[N];
	cout << "Executable name " << argv[0] << endl;
	cout << "Reading in file: " << argv[1] << endl;

	readInFile(strArr, N, argv[1]);
	return 0;
	}
}

void readInFile(Student strArr[], int arrL, string fileName)
{
	//Declare an object of ifstream class
	ifstream inStream; //Remember inStream is a custome name

	//connect stream objext to the externam file 
	inStream.open(fileName);
	string sidString,studentName,major;

	if(inStream.is_open()){ //makes sure that file opens properly 
		for(int i = 0; i<arrL; i++){
			//use getline and set delimeter to ','	
			getline(inStream,sidString,',');
			//since getline reads the number as a string, convert it to int 
			//using stoi (string to integer)
			strArr[i].idNumber = stoi(sidString);
			cout << strArr[i].idNumber << endl;
			//use getline and set delimeter to ',''
			getline(inStream,studentName,',');
			strArr[i].name = studentName;
			cout << strArr[i].name << endl;

			//use getline and set delimeter to '\n'(new line)
			getline(inStream,major,'\n');
			strArr[i].dept = major;
			cout << strArr[i].dept << endl;
		}
	}
	else{
		cout << "file open error" << endl;
		exit(0);
	}
	inStream.close(); //Always include .close() after .open(fileName)
}


