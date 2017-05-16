class MyList {
public:
	struct node {
		int data;
		node* next;
		node* previous;
	};
	//ATTR
	node* first;
	node* last;
private:
	int sizez;
public:
	//FUNC
	MyList::MyList();
	MyList::MyList(MyList &a);
	MyList::~MyList();

	int MyList::size();
	bool MyList::isEmpty();
};