#pragma once

class myStack
{
struct node {
	int data;
	node *next;
};
node *first;

public:
	myStack();
	myStack(const myStack &a);
	myStack(int* &a);
	myStack();

	void pop();
	void push(int a);
	int front();
	bool isEmpty();
	int size();
	~myStack();
};

