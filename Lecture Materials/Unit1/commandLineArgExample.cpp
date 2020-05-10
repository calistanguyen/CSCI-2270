#include <iostream>

int main(int argc, char *argv[])
{
	std :: cout << "Hello, you called the program with " << argc << " arguments." << std :: endl; 

	std :: cout << "\n Let's list the arguments: " << std :: endl; 

	for(int i = 0; i < argc ; i++)
	{
		std :: cout << argv[i] << std :: endl; 
	}

	return 0; 
}