#include <deque>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <random>
#include <time.h>

std::priority_queue<int> superMergeP(std::priority_queue<int> a, std::priority_queue<int> b) {
	while(!a.empty()) {
		b.push(a.top());
		a.pop();
	}
	std::priority_queue<int> m(b);
}

std::queue<std::string> concatQueue(std::queue<std::string> a, std::queue<std::string> b) {
	while (!a.empty()) {
		b.push(a.front());
		a.pop();
	}
	std::queue<std::string> v(b);
	return v;
}
/*
std::queue<int> shiftRight(std::queue <int> &a) {
	int tmp;
	for (auto it = a.front(); it <= a.size; it++) {
		a.push(rand());
		tmp = a.back();

		a.front()=tmp;

		
	}
}
*/
/*
std::queue<int>	rotateLeft(std::queue<int> &a) {
	for (auto it : a.size/2) {
		a.front()+it.swap(a.back()-it);
	}
	return a;
}
*/
void eraseElements(std::deque<int> &a, int b) {
	for (auto it = 0; it < a.size()-1; it++) {
		if (a[it] == b) {
			a.erase(a.begin+it);
		}
		
	}
}

void eraseRepeated(std::deque<int> &a) {
	for (auto it = 0; it < a.size() - 1; it++) {
		for (auto i = 1; i < a.size() - 1; i++) {
			if (a[it] == a[i]) {
				a.erase(a.begin() + i);
			}
		}
	}
}

void main() {
	//DEQUE
	std::deque<float> prices(10, 10.50);
	prices.pop_back();
	prices.push_back(32.43);
	prices.pop_front();
	std::deque<float> prices2(prices);
	prices2.push_front(5.64);
	prices2.push_front(20.31);
	prices2.insert(prices2.begin() + 1, 10);

	for (auto it = prices.rbegin(); it == prices.rend(); it++) {
		std::cout << *it << std::endl;
	}

	for (auto &it : prices2) {
		std::cout << it << std::endl;
	}

	//VECTOR
	std::vector<float> prices3(10, 10.50);
	prices3.pop_back();
	prices3.push_back(32.43);
	prices3.erase(prices3.begin());
	std::vector<float> prices4(prices3);
	prices4.insert(prices4.begin(), (5.64));
	prices4.insert(prices4.begin(), (20.31));
	prices4.insert(prices4.begin() + 1, 10);

	for (auto it = prices3.rbegin(); it == prices3.rend(); it++) {
		std::cout << *it << std::endl;
	}

	for (auto &it : prices4) {
		std::cout << it << std::endl;
	}
	std::queue<std::string> h;
	h.push("Q");
	h.push("U");
	h.push("E");
	h.push("?");
	std::queue<std::string> c;
	c.push("H");
	c.push("O");
	c.push("L");
	c.push("A");
	std::priority_queue<int> x;
	x.push(20);
	x.push(34);
	x.push(2);
	x.push(18);
	std::priority_queue<int> z;
	z.push(45);
	z.push(56);
	z.push(12);
	z.push(8);

	superMergeP(x,z);
	concatQueue(c, h);

}