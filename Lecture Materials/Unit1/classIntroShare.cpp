#include <iostream>
using namespace std; 

class Time12
{
private: 
	int hour; 
	int minute; 
	string mer; 

public: 
	//constructors: 
	Time12(int h, int m, string me); //initializes data for the object
	Time12(){}; //function overload. alternate definition based on how the caller calls the function

	//display function 
	void printTime(); 

	//mutator functions: 
	void setHour( int h ); 
	void setMinute(int m); 

	//accessor functions 
	int getHour(); 
	int getMinute(); 

	//mutator and accessors allows us to access and change the private data members 

};

int main()
{
	Time12 t(1, 25, "PM"); 

};
//:: = scope resolution operator
Time12::Time12(int h, int m, string me)
{

	if (h >= 0 && h <= 12)
	{
		hour = h;
	}

	else 
	{
		cout << "bad choice" << endl; 
	}


}