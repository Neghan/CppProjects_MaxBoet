#include <iostream>
#include <stack>
#include <string.h>
#include <set>
#include <queue>

std::stack<int> Merged;
std::stack<int> superMerge(std::stack<int> a, std::stack<int> b) {
	
	while (!(a.empty() || b.empty())) {
		if (a.top() >= b.top()) {
			Merged.push(a.top());
			a.pop();
		}
		else {
			Merged.push(b.top());
			b.pop();
		}
	}
	if (a.empty()) {
		while (!b.empty()) {
			Merged.push(b.top());
			b.pop();
		}
	}
	else {
		while (!a.empty()) {
			Merged.push(a.top());
			a.pop();
		}
	}
	while (!Merged.empty()) {
		std::cout << Merged.top() << std::endl;
		Merged.pop();
	}
	return Merged;
}

std::stack<std::string> putHat(std::stack<std::string> a, std::stack<std::string> b) {
	while (!a.empty()) {
		b.push(a.top());
		a.pop();
	}
	return b;
}
std::queue<int> transformToQ(std::stack<int> &a) {
	std::queue<int> res;
	while (!a.empty()) {
		res.push(a.top());
		a.pop();
	}
	return res;
}
bool isHat(std::stack<int> a, std::stack<int> b) {

}
bool balancedP(std::queue<char> a) {
	if (a.back() == a.front()) {

	}
	return true;
}
void change(std::stack<int> &a) {
	std::deque<int> d;
	while (!a.empty()) {
		d.push_back(a.top());
		a.pop();
	}
	int tmp;
	tmp = d.front();
	d.front() = d.back();
	d.back() = tmp;
	while (!d.empty()) {
		a.push(d.back());
		d.pop_back();
	}
	while (!a.empty()) {
		std::cout << a.top();
		a.pop();
	}
}
void main() {
	std::stack<int>StackA;
	std::stack<int>StackB;
	StackA.push(10);
	StackA.push(9);
	StackA.push(8);
	StackA.push(7);
	StackA.push(6);
	StackA.push(5);

	StackB.push(3);
	StackB.push(2);
	StackB.push(1);

	std::stack<std::string>StackC;
	std::stack<std::string>StackD;
	StackC.push("A");
	StackC.push("B");
	StackC.push("C");

	StackD.push("D");
	StackD.push("E");
	StackD.push("F");

	superMerge(StackA, StackB);
	putHat(StackC, StackD);
	change(StackA);
	transformToQ(StackB);
}