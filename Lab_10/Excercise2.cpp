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

void LinkedList::insertAtFront(int e)
{
        Node *temp = new Node;
        temp->val = e;
        temp->next = NULL;
        if (isEmpty())
        {
//              first = temp;
                last = temp;
//              last->next = NULL;
                cout << "inserted in front if empty" << endl;
        }
        else
        {
                Node *v = new Node;
                v->val = e;
                v->next = first;
                first = v;
                cout << "inserted in front" << endl;
        }
}

bool LinkedList::removeFromFront()
{
 if(isEmpty())
                return false;
        else
        {
                Node *temp = first;

                if(temp->next != NULL)
                {
                        temp->next = first;
                        delete temp;
                        cout << "removed";
                        return true;
                }

                else
                {
                        first = NULL;
                        last = NULL;
                        delete temp;
                        cout << "removed last";
                        return true;
                }
        }
}
