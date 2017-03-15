#include "Stack_char.h"

using namespace std;

//Default constructor
Stack_char::Stack_char()
	{

	}

//Destructor
Stack_char::~Stack_char()
	{

	}

void Stack_char::push(char value)
	{
		LinkedList_char::insertAtFront(value);
	}

char Stack_char::pop()
	{
		char popped = first->val;
		LinkedList_char::removeFromFront(); 
		return popped;
	}

char& Stack_char::top()
	{
		//int &tops = first;
		return (first->val);
	}

