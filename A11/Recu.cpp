#include "Recu.h"
#include "time.h"
#include <random>

MyList::MyList() {
	sizez = 0;
	first = nullptr;
	last = nullptr;
}

MyList::MyList(MyList &a) {
	
	sizez = a.size();
}

MyList::~MyList() {
	node* tmp=first;
	while (!isEmpty()) {
		if (first->next != nullptr) {
			tmp = first->next;
			delete first;
			first = tmp;
			sizez--;
		}
	}
	first = nullptr;
	last = nullptr;
}

bool MyList::isEmpty() {
	if (first == nullptr) {
		return true;
	}
	return false;
}

int MyList::size() {
	return sizez;
}
void MyList::push_front(int value)
{
	node* tmp = new node;
	tmp->next = first;
	first->previous = tmp;
	tmp->data = value;
	first = tmp;
	sizez++;
}
void MyList::pop_front() {
	first = first->next;
	delete first;
	sizez--;
}
void MyList::push_back(int value) {
	node* tmp = new node;
	tmp->previous = last;
	last->next = tmp;
	tmp->data = value;
	last = tmp;
	sizez++;
}
void MyList::pop_back() {
	last = last->previous;
	delete last;
	sizez--;
}

void MyList::shiftLeft() {
	node* tmp = new node;
	tmp->data = rand();

	first = first->next;
	delete first->previous;
	last->next = tmp;
	tmp->previous = last;
	last = tmp;
	tmp->next = nullptr;
}

void MyList::shiftRight() {
	node* tmp = new node;
	tmp->data = rand();

	last = last->previous;
	delete last->next;
	first->previous = tmp;
	tmp->next = first;
	first = tmp;
	tmp->previous = nullptr;
}

void MyList::rotateLeft() {
	node* tmp;
	tmp = first;
	while (last != tmp) {
		last = last->previous;
		first->previous = last->next;

		last->next = nullptr;
		first = first->previous;
	}
	

}

void MyList::rotateRight() {
	node* tmp;
	tmp = last;
	while (first != tmp) {
		first = first->next;
		first->previous = last->next;

		first->previous = nullptr;
		last = last->next;
	}
}
void MyList::reverse() {

}
void MyList::remove(int value) {
	node* tmp;//+
	node* tmp2;//-
	tmp = first;
	tmp2 = first->next;

	while (tmp != last) {
		if (tmp->data == value) {
			delete tmp;
		}
		tmp = tmp2;
		tmp2 = tmp->next;
	}
}


void main() {
	MyList a;
	a.push_front(1);
	a.push_front(3);
	a.push_back(5);
}
