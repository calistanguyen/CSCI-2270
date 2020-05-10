#include <iostream>
int main ( int argc, char const *argv[])
{
	std :: cout << "Number of Arguments: "; 
	std :: cout << argc << std :: endl; 
	std :: cout << "Program arguments: " << std :: endl; 
	for (int i = 0; i < argc; i++)
	{
		std :: cout << "Argument #" << i << ": ";
		std :: cout << argv[i] << std :: endl; 
	}
}