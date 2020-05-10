#include <iostream>
using namespace std; 

struct Student
{
	string name; 
	int age; 
};


int main(){

	Student s0; 
	Student *sptr = &s0; 

	


	Student* sptr1 = new Student; 

	(*sptr1).name = "Maia"; 
	(*sptr1).age = 33; 

	//equivalent to above
	sptr1 -> name = "maia";
	sptr1 -> age = 33; 

}