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
	
	void shiftLeft();
	void shiftRight();
	void rotateLeft();
	void rotateRight();
	void reverse();
	void remove(int value);

	void push_front(int value);
	void push_back(int value);
	void pop_front();
	void pop_back();
	int size();
	bool isEmpty();
};