#include "myClass.h"



myStack::myStack()
{

}

myStack::myStack(int* &a) {

}

void myStack::push(int a) {
	node *x = new node;
	x->data = a;
	x->next = first;

	first = x;
}

myStack::~myStack()
{

}
