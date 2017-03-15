#ifndef _STACK_CHAR_H
#define _STACK_CHAR_H

#include <iostream>
#include <string>
#include "LinkedList_char.h"

using namespace std;

class Stack_char : public LinkedList_char
{
	public:
		Stack_char(); //default constructor
		~Stack_char(); //destructor
		void push(char); //inserts a new element at the front of the stack
		char pop(); //removes the first element of the Stack
		char& top(); //returns a reference to the top element of the Stack
};

#endif
