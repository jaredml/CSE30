#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

class Stack : public LinkedList
{
	public:
		Stack(); //default constructor
		~Stack(); //destructor
		void push(int); //inserts a new element at the front of the stack
		int pop(); //removes the first element of the Stack
		int& top(); //returns a reference to the top element of the Stack
};

#endif
