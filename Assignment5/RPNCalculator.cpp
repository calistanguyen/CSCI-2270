#include <iostream>
#include "RPNCalculator.hpp"
using namespace std; 

RPNCalculator::RPNCalculator(){
	stackHead = NULL; 
}

RPNCalculator::~RPNCalculator(){ 

	if (stackHead != NULL)
	{
		Operand *temp = stackHead; 

		while(temp->next != NULL){
			stackHead = stackHead->next; 
			delete temp; 
			temp = stackHead; 
		}

		stackHead = NULL; 
		delete temp; 
	}

}

bool RPNCalculator::isEmpty(){

	if(stackHead == NULL){
		return true; 
	}
	return false; 
}

void RPNCalculator::push(float number){

	Operand *newHead = new Operand; 
	newHead->number = number;

	if(stackHead == NULL){
		newHead->next = NULL; 
		stackHead = newHead; 
		return; 
	}

	newHead->next = stackHead; 
	stackHead = newHead; 
}

void RPNCalculator::pop(){

	if(stackHead == NULL){
		cout << "Stack empty, cannot pop an item." << endl; 
		return;
	}

	Operand *temp = stackHead; 

	if (temp->next == NULL){

		delete temp; 
		stackHead = NULL; 
		return;
	}

	stackHead = stackHead->next; 
	delete temp; 
}

Operand* RPNCalculator::peek(){

	if (stackHead == NULL){
		cout << "Stack empty, cannot peek." << endl; 
		return NULL; 
	}

	return stackHead; 

}

bool RPNCalculator::compute(string symbol)
{
	if (symbol != "*" && symbol != "+"){

		cout << "err: invalid operation" << endl; 
		return false; 
	}

	if (isEmpty())
	{
		cout << "err: not enough operands" << endl; 
		return false; 

	} 

	else
	{
		float num1 = stackHead->number; 
		pop(); 

		if (isEmpty())
		{
			cout << "err: not enough operands" << endl; 
			push(num1); 
			return false; 
		}

		float num2 = stackHead->number; 
		pop(); 

		if (symbol == "*"){

			push(num1*num2);
			return true; 
		}

		if (symbol == "+"){
			push(num1+num2); 
			return true; 
		}
	}

	return false; 
}

