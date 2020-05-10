#include <iostream>
#include <vector>
#include <string> 
using namespace std; 

struct myStruct {
	int numbers; 
	string words;
}; 

int main()
{
	vector<int> v0; 
	cout << "size = " << v0.size() << endl; //returns vector size 

	//initialize vector of size 5
	vector<int> v1(5, 2); //sets each space in the vector as 2 
	cout << "size = " << v1.size() << endl;  

	if (v1.empty())
	{
		cout << "vector is empty" << endl; 
	}

	//print contents 
	cout << "v1 = "; 
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl; 

	v1[2] = 3; //indexes of vectors are similar to arrays 
	v1[4] = 9; 

	v1.push_back(0); //appends a 0 to the end
	cout << "size = " << v1.size() << endl; 

	//vector of pointers 
	vector<int*>vecPtrs(5); 
	int * p0 = new int[3]; 
	p0[0] = 2; 
	p0[1] = 7; 
	p0[2] = 0; 

	vecPtrs[0] = p0; 

	cout << "vecPtrs: " << vecPtrs[0] << endl; //out puts the hexidecimal value/address bc it is a vector of pointer 
	cout << "vecPtrs: " << *vecPtrs[0] << endl;
	cout << "vecPtrs: " << *(vecPtrs[0] + 1)<< endl; //incraments the hexidecimal value to reach the next elememnt in p0

	//now define a vector of user defined structs
	vector <myStruct> vectorOfStructs; 


	return 0; 
}