#include "Recu.h"

MyList::MyList() {
	sizez = 0;
	first = nullptr;
	last = nullptr;
}

MyList::MyList(MyList &a) {
	MyList tmp = a;
	node* f = new node;
	f = tmp.first;
	while (tmp.first != tmp.last) {
		f = f->next;
		f = tmp.first->next;
		tmp.first = tmp.first->next;
	}
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

void main(){
	MyList a;
	a.isEmpty();
}