#include "Stack.h"

using namespace std;

//Default constructor
Stack::Stack()
{

}

//Destructor
Stack::~Stack()
{

}

void Stack::push(int value)
{
LinkedList::insertAtFront(value);
}

int Stack::pop()
{
	int popped = first->val;
	LinkedList::removeFromFront(); 
	return popped;
}

int& Stack::top()
{
	//int &tops = first;
	return (first->val);
}

