#include <iostream>
using namespace std; 


void arrayDouble(int *&a, int length);

int main()
{
	int n = 5; 

	//Allocate on the heap 

	int *p = new int[n]; 

	//Here we would fill the array with some data
	//p[0] = something

	//Ket's begin the array doubling algorithm 

	int *temp = new int[2*n];

	//Copy over first n elements 

	for (int i = 0; i < n; i++)
	{
		temp[i] = p[i]; 
	}

	//deallocate original memory 
	delete [] p; 

	//point p to the new block of memory that's 2n in length 
	p = temp; 

	return 0; 
}