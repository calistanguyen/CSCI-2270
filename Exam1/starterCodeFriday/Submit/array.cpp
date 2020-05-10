#include<iostream>
#include<string>
using namespace std;

/* 
// Split 'arr' into 'even_arr' & 'odd_arr'
//  - 'arr': pointer to original array
//  - 'even_arr': pointer to even array
//  - 'odd_arr': pointer to odd array
*/
void split(int* &arr, int* &even_arr, int* &odd_arr, int size, int &even_size, int &odd_size)
{
	//Implement this function
    int evenCounter = 0; //counts the even numbers
    int oddCounter = 0; //counts the odd numbers

    for (int i = 0; i < size; i++)
    {
        if(arr[i]%2==0) // if the value in the array is even
        {
            even_arr[evenCounter] = arr[i]; //put it in the even array
            evenCounter++; //incrament the even array counter which serves as an index
        }
        else
        {
            odd_arr[oddCounter] = arr[i];
            oddCounter++; 
        }
    }; 

    //reset the arrays to proper size
    int *tempArrEven = new int[evenCounter]; 
    for (int i = 0; i < evenCounter; i++) //copies and pastes old array into new array with proper size
    {
        tempArrEven[i] = even_arr[i]; 
    }

    delete [] even_arr; //delete old array 
    even_arr = tempArrEven; 
    even_size = evenCounter; //reset the size

    int *tempArrOdd = new int[oddCounter]; 
    for( int i = 0; i < oddCounter; i++)
    {
        tempArrOdd[i] = odd_arr[i];
    } 
    delete [] odd_arr; 
    odd_arr = tempArrOdd; 
    odd_size = oddCounter; 

// this ksjhdlsdjolsfjo this thjsnlasdijwalskj9fkjsihw9hfadkfhakosdnfasifhaklsfhasiojm

}

void printArray(int* arr, int size) {
    for(int i = 0; i<size; i++)
    {
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;
}

int main(int argc, char* argv[])
{
    if(argc<2)
    {
      cout<<"usage: a.out <#>";
      return -1;
    }

	// Create input array:
    int size = stoi(argv[1]);
    int *arr = new int[size];

    cout<< "original array: ";
    for(int i = 0; i<size; i++)
    {
        arr[i] = rand()%100;
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;

	// Call your function with new arrays:
    int even_size = size; 
    int *even_arr = new int[even_size]; //deallocate memory for new odd and even arrays 

    int odd_size = size; 
    int *odd_arr = new int [odd_size]; 
	split(arr, even_arr, odd_arr, size, even_size, odd_size);

	//Output 
    cout << "Evens: "; 
    if (even_size == 0)
    {
        cout << "no even items in the array" << endl; 
    }
    else
    {
        printArray(even_arr, even_size);

    }

    cout << "Odds: "; 
    if (odd_size == 0)
    {
        cout << "no odd items in the array" << endl; 
    }
    else
    {
        printArray(odd_arr, odd_size);

    }

	// Clean up (delete)
    delete [] arr; //deallocate the old array

    return 0;
}
