#include <iostream>
#include <string>
#include <ctime>


enum EnemyType{zombie,vampire,ghost,witch};

struct Enemy{
	EnemyType type;
	std::string name;
	int health;
};

bool operator == (Enemy e1, Enemy e2) {
	bool isTheSame = false;
	if (e1.type == e2.type && e1.name == e2.name) {
		isTheSame = true;
	}
	else {
		isTheSame = false;
	}
	return isTheSame;
}
Enemy CreateRandomEnemy() {
	EnemyType tipo;
	tipo = rand()%5;
	return tipo;
}
void main() {
	srand(time(NULL));

	std::string names[];
}