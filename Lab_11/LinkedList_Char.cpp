#include <iostream>
#include "LinkedList_char.h"

using namespace std;

Node *first, *last;

//constructor
LinkedList_char::LinkedList_char()
{
	first = last = NULL;
}

//destructor
LinkedList_char::~LinkedList_char()
{
	while(!isEmpty())
	removeFromBack();
	delete first;
	delete last;
}

//inserts a new element at the end of the list
void LinkedList_char::insertAtBack(char newval)
{
//do if list is empty
	if (first == NULL)
	{
		first = new Node;
		first->val = newval;
		first->next = NULL;
}

//do if list is not empty
	else
	{
		Node *temp = first;

//transverse to the end of the list
		while(temp->next != NULL)
			temp = temp->next;

//insert new element at the end of the list
		Node *u = new Node;
		u->val = newval;
		u->next = last;
		temp->next = u;
}
}

//removes the last element of the list
bool LinkedList_char::removeFromBack()
{

	Node *temp = first;
	Node *temp2 = first;

//if the list is empty, you can't remove anything
	if(isEmpty())
		return false;
	else
	{
//want to store the second to last element because it will become the new last
		while(temp->next != NULL)
		{
			temp2 = temp->next;

//check if traversed to the end
			if (temp2->next == NULL)
			{
				last = temp;
				last->next = NULL;
				delete temp2;
				return true;
			}
			else
			{
				temp = temp->next;
			}
		}

//do if there is only one element left
		if (temp->next == NULL)
		{
			first = NULL;
			last = NULL;
			delete temp;
			return true;
		}
	}
}

//prints the entire list
void LinkedList_char::print()
{
	Node *n = first;

//if the list is empty
	if (n == NULL)
		cout << " ";
	else
	{
//print value as long as there is something next
		while (n->next != NULL)
		{
			cout << n->val << ",";
			n = n->next;
		}

//print the last value
		if (n != NULL)
			cout << n->val;
	}
}

//check if the list is empty or not
bool LinkedList_char::isEmpty()
{
	if (first == NULL && last == NULL)
		return true;
	return false;
}

//returns the size of the list
int LinkedList_char::size()
{
	int counter = 0; //keep track of elements in list
	Node *length = first;

//list is empty, return 0
	if (length == NULL)
		return counter;
//traverse through list until there are no more elements, incrementing counter when there is an element
	else
	{
		while (length != NULL)
		{
			counter++;
			length = length->next;
		}
		return counter;
	}
}

//deletes the entire list if not already empty
void LinkedList_char::clear()
{
	while (!isEmpty())
	{
		removeFromBack();
	}
	delete first;
	delete last;
}

//IMPLEMENT THESE FUNCTIONS FOR EXERCISE2

//inserts a new element at the beginning of the list
void LinkedList_char::insertAtFront(char e)
{
//creates a new element with val set to e
	Node *newNode = new Node;
	newNode->val = e;

//do if the list is empty
	if (isEmpty())
	{
		newNode->next = NULL;
		first=newNode;
	}

//do if adding in front of an existing element
	else
	{
		newNode->next = first;
		first = newNode;
	}
}

//removes the first element of the list
bool LinkedList_char::removeFromFront()
{
	//cannot remove an element if the list is empty
	if(isEmpty())
		return false;

	else
	{
	Node *temp = first;
	first = first->next;
	delete temp;
	return true;
	}
}
