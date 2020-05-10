#include <iostream>
using namespace std; 


int main()
{
	int *p0; 
	p0 = new int; //nameless variable

	cout << p0 << endl; 

	*p0 = 7; 

	cout << *p0 << endl; 

	delete p0; //deallocating -- erasing the value in the memory space  to open up space in the heap 

	cout << *p0 << endl; //unpredictable behavior

	cout << p0 << endl; 

	return 0; 
}