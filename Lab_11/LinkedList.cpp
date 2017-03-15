#include <iostream>
#include "LinkedList.h"

using namespace std;

Node *first, *last;

LinkedList::LinkedList()
{
        first = NULL;
        last = NULL;
}

LinkedList::~LinkedList()
{
        while(!isEmpty())
                removeFromBack();
        delete first;
        delete last;
}

void LinkedList::insertAtBack(int newval)
{
        if (first == NULL)
        {
                first = new Node;
                first->val = newval;
                first->next = NULL;
                return;
        }

        Node *temp = first;

        while(temp->next != NULL)
                temp = temp->next;

        Node *u = new Node;
        u->val = newval;
        u->next = last;
        temp->next = u;
}

bool LinkedList::removeFromBack()
{

        Node *temp = first;
        Node *temp2 = first;
		
		 if(isEmpty())
                return false;

        while(temp->next != NULL)
        {
                temp2 = temp->next;

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

        if (temp->next == NULL)
        {
                first = NULL;
                last = NULL;
                delete temp;
                return true;
        }
}

void LinkedList::print()
{
        Node *n = first;

        if (n == NULL)
                cout << " ";
        else
        {
                while (n->next != NULL)
                {
                        cout << n->val << ",";
                        n = n->next;
                }

                if (n != NULL)
                        cout << n->val;
        }
}
bool LinkedList::isEmpty()
{
        if (first == NULL && last == NULL)
                return true;
        return false;
}

int LinkedList::size()
{
        int counter = 0;
        Node *length = first;
        if (length == NULL)
                return counter;
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
void LinkedList::clear()
{
        while (!isEmpty())
        {
                removeFromBack();
        }
        delete first;
        delete last;
}
