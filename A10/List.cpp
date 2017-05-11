#include <list>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

std::list<int> superMerge(std::list<int> a,std::list<int> b) {
	std::list<int> merged;
	while (!(a.empty() && b.empty())) {
		if (a.empty()) {
			while (!b.empty()) {
				merged.push_back(b.front());
				b.pop_front();
			}
		}
		else if (b.empty()) {
			while (!a.empty()) {
				merged.push_back(a.front());
				a.pop_front();
			}
		}
		else {
			if (a.front() >= b.front()) {
				merged.push_back(a.front());
				a.pop_front();
			}
			else if (a.front() < b.front()) {
				merged.push_back(b.front());
				b.pop_front();
			}
		}
	}

///////////////////////////////////////////////////////////
	while (!merged.empty()) {
		std::cout<< merged.front() << " ";
		merged.pop_front();
	}
	std::cout << std::endl;
///////////////////////////////////////////////////////////
	return merged;
 }

void change(std::list<int> &a) {
	int tmp;
	tmp = a.front();
	a.front() = a.back();
	a.back() = tmp;

///////////////////////////////////////////////////////////
	while (!a.empty()) {
		std::cout << a.front() << " ";
		a.pop_front();
	}
	std::cout << std::endl;
///////////////////////////////////////////////////////////
}

int getElementPos(std::list<int> a, int pos) {
	std::deque<int> s;
	while (!a.empty()) {
		s.push_back(a.front());
		a.pop_front();
	}

///////////////////////////////////////////////////////////
	std::cout << s[pos] << std::endl;
///////////////////////////////////////////////////////////
	return s[pos];
}

void removeDuplicates(std::list<int> &a) {
	std::set<int> remove;
	while (!a.empty()) {
		remove.insert(a.front());
		a.pop_front();
	}
	while (!remove.empty()) {
		a.push_front(*remove.begin());
		remove.erase(remove.begin());
	}

///////////////////////////////////////////////////////////
	for (auto it = a.begin(); it != a.end();++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
///////////////////////////////////////////////////////////
}

void removeElement(std::list<int> &a, int val) {
	for (auto it = a.begin(); it != a.end(); ++it) {
		if (*it == val) {
			a.erase(it);
		}
	}

///////////////////////////////////////////////////////////
	for (auto it = a.begin(); it != a.end(); ++it) {
		std::cout << *it<< " ";
	}
	std::cout << std::endl;
///////////////////////////////////////////////////////////
}

bool palindrome(std::list<int> a) {
	bool palindromity=false;
	bool controller=false;
	if (a.size() == 1) {
		return true;
	}
		while (!a.empty()&&controller==false) {
			if (a.front() == a.back()) {
				a.pop_back();

				if (!a.empty()) {
					a.pop_front();
				}
				
			}
			else {
				controller = true;
			}

		}
	if (a.empty()) {
		palindromity = true;
	}

///////////////////////////////////////////////////////////
	std::cout << palindromity;
///////////////////////////////////////////////////////////
	return palindromity;
}
void main() {
	std::list<int>E = { 9,8,5,3,1 };
	std::list<int>F = { 6,3,2,1 };
	std::list<int>G = { 1,2,3,3,3,2,4,5,5 };
	std::list<int>H = { 1,3,4,4,4,5,7,3,2,4 };
	std::list<int>pal = { 5,4,3,2,1,2,3,4,5 };

	std::list<int>Merged = superMerge(E, F);
	change(E);
	getElementPos(F, 3);
	removeDuplicates(G);
	removeElement(H, 4);
	palindrome(pal);
}