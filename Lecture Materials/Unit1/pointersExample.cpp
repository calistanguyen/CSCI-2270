#include <iostream>
using namespace std; 

void foo(int *z)
{
	cout << z << endl << *z << endl;
	z = 22; 
}

int main()
{
	int x = 2, *p; //pointer p that points to integer type 
	p = &x; //points to the address of x

	// //Let's look at the value of x and x's address
	// cout << x << endl << &x << endl; 

	// //output p 
	// cout << p << endl;

	// //dereferencing the pointer using '*' to see what is at the address 
	// cout << *p << endl;  

	// //dereference a pointer to write to original variable 
	// // *p = 5; 
	// // cout << x << endl; //x now is valued 5

	// //Make a function to accept a pointer - foo()
	// //foo(x); -- invalid since the function only accepts pointers, not int
	foo(p); 
	cout << x << endl; 



	return 0; 
}