#include <iostream>
using namespace std; 

void push(int *&intArray, int &capacity, int &numElements, int n){
	if(numElements == capacity)
	{
		int *tempArr = new int[2*capacity]; 
		for(int i = 0; i < numElements; i++)
		{
			tempArr[i] = intArray[i]; 
		}
		delete [] intArray; 
		capacity = 2*capacity; 
		intArray = tempArr; 
	}

	intArray[numElements] = n; 
	numElements++;
}
void pop(int *&intArray, int &capacity, int &numElements){

	int *tempArr = new int [capacity]; 

	for (int i = 0; i < numElements -1; i++)
	{
		tempArr[i] = intArray[i]; 

	}

	delete [] intArray; 
	intArray = tempArr; 
	numElements--; 


	if (numElements >= 5 && numElements <= (capacity/2))
	{
		tempArr = new int[capacity/2];
		for(int i = 0; i < numElements; i++)
		{
			tempArr[i] = intArray[i];
		}
		delete [] intArray; 
		capacity = capacity/2; 
		intArray = tempArr; 
		for(int i = 0; i < numElements; i++)
		{
			tempArr[i] = intArray[i];
		} 
	}
} 

void print(int intArr[], int capacity); 


int main()
{
	//Test case 1: 
	cout << "TEST CASE 1" << endl; 
	int capacity1 = 5;
	int numElements1 = 5;
	int *arr1 = new int[capacity1]; 
	for (int i = 0; i < capacity1; i++)
	{
		arr1[i] = i + 1; 
	}
	cout << "Old Capacity: " << capacity1 << endl;
	cout << "Number of Elements: " << numElements1 << endl; 
	cout << "Array before insert with capacity " << capacity1 << ": " << endl;  
	for (int i = 0; i < numElements1; i++)
	{
		cout << arr1[i] << " "; 
	}
	cout << endl; 
	push(arr1, capacity1, numElements1, 6);
	cout << "New Capacity After Push: " << capacity1 << endl; 
	cout << "Number of Elements: " << numElements1 << endl; 
	cout << "Array after insert with capacity " << capacity1 << ": " << endl;  
	for (int i = 0; i < numElements1; i++)
	{
		cout << arr1[i] << " "; 
	}
	cout << endl; 
	cout << endl; 

	//Test case 2: 
	cout << "TEST CASE 2" << endl; 
	int capacity2 = 5; 
	int numElements2 = 0; 
	int *arr2 = new int[capacity2]; 
	for (int i = 0; i < 10; i++)
	{
		push(arr2, capacity2, numElements2, i+1);
		cout << "Pushing: " << i + 1 << endl; 
		cout << "numElements: " << numElements2 << endl; 
		cout << "capacity: " << capacity2 << endl; 
		cout << "-----" << endl; 
 
	}

	cout << "Array after pushing elements: " << endl; 
	for (int i = 0; i < numElements2; i++)
	{
		cout << arr2[i] << " "; 
	}
	cout << endl;

	//Test case 3:

	cout << "TEST CASE 3" << endl; 

	for (int i = 0; i < 10; i++)
	{
		push(arr2, capacity2, numElements2, i+1);
		cout << "Pushing: " << i + 10 << endl; 
		cout << "numElements: " << numElements2 << endl; 
		cout << "capacity: " << capacity2 << endl; 
		cout << "-----" << endl; 

	}
	for (int i = 0; i < 10; i++)
	{
		pop(arr2, capacity2, numElements2);
	}
	cout << "NumElements: " << numElements2 << endl; 
	cout << "capacity: " << capacity2 << endl;

	for (int i = 0; i < numElements2; i++)
	{
		cout << arr2[i] << " "; 
	}

	cout << endl; 

	for (int i = 0; i < 3; i++)
	{
		pop(arr2, capacity2, numElements2);
	}
	cout << "NumElements: " << numElements2 << endl; 
	cout << "capacity: " << capacity2 << endl;
	cout << endl; 
	for (int i = 0; i < numElements2; i++)
	{
		cout << arr2[i] << " "; 
	}





}