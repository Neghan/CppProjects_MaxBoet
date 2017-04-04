#include <vector>
#include <iostream>
#include<string>

class People {
private:
	std::string name;
	std::string birthdate;
	std::string DNI;
public:
	People::People(std::string n, std::string b, std::string D) {
		name = n;
		birthdate = b;
		DNI = D;
	}
};

//EJERCICIOS//

std::vector<int>v1(5);

std::vector<int>v2(10);

std::vector<int>v3(5);

std::vector<std::string>v4({"Gertrudiz","Pancracia","Anacleto","Hipolito","Eustaquio","Fulgencia"});

std::vector<int>v5(v3);

People p1("Manolo", "22-07-1998", "35986879N");
People p2("Carlos", "21-06-1993", "25985879C");
People p3("Helena", "16-02-1989", "35886679E");

std::vector<People>v6({p1,p2,p3});

std::vector<int>v7({ 5,4,2,1 });
std::vector<int>v8({ 6,2,4,5 });

void AddVectors(int a, int b) {

}
