#include "Stack.h"
#include <iostream>

using namespace std;

int main()
{
	Stack stuff;
	for (int i = 1; i<= 10; i++)
		stuff.push(i);
	while(!stuff.isEmpty())
	{
		cout << "The top of the stack is " << stuff.top() << endl;
		cout << "The stack is ";
		stuff.print();
		cout << endl;
		cout << "The size of the stack is " << stuff.size() << endl;
		stuff.pop();

		if(stuff.isEmpty())
			cout << "The stack is empty!" << endl;
		else
			cout << "The stack is not empty..." << endl;
	}
}

