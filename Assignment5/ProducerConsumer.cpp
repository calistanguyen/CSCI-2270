#include "ProducerConsumer.hpp"
#include <iostream>
using namespace std; 

ProducerConsumer::ProducerConsumer(){
	queueFront = 0; 
	queueEnd = 0; 
}

bool ProducerConsumer::isEmpty(){
	if (queueEnd == queueFront && counter == 0){
		return true;
	}
	return false;
}

bool ProducerConsumer::isFull(){
	if (queueEnd==queueFront && counter == 20){
		return true;
	}
	return false; 
}

void ProducerConsumer::enqueue(string item){
	if (isFull())
	{
		cout << "Queue full, cannot add new item" << endl;
		return; 
	}
	queue[queueEnd] = item; 
	counter++;

	if (queueEnd == 19){
		queueEnd = 0; 
	}
	else{

		queueEnd++; 
	}

	return; 
	//finish 

}

void ProducerConsumer::dequeue(){

	if(isEmpty()){
	
		cout << "Queue empty, cannot dequeue an item" << endl;
		return;

	}

	queue[queueFront] = ""; 
	counter --; 

	if (queueFront == 19)
	{
		queueFront = 0; 
	}
	else{
		queueFront++; 
	}

}

int ProducerConsumer::queueSize()
{
	return counter; 
}

string ProducerConsumer::peek(){

	if (isEmpty()){
		cout << "Queue empty, cannot peek" << endl; 
		return ""; 
	}

	return queue[queueFront]; 
}