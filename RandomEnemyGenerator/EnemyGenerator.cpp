#include <iostream>
#include <string>
#include <ctime>


enum class EnemyType{ZOMBIE,VAMPIRE,GHOST,WITCH,MAX	};

struct Enemy{
	EnemyType type;
	std::string name;
	int health;

	std::string getEnemyTypeString() {
		switch (type) {
		case EnemyType::ZOMBIE: return "zombie";
		case EnemyType::VAMPIRE: return "vampire";
		case EnemyType::GHOST: return "ghost";
		case EnemyType::WITCH: return "witch";
		default: return "";
		}
	}
};

bool operator == (const Enemy &e1, const Enemy &e2) {
	return e1.name == e2.name && e1.type == e2.type;
}
static Enemy CreateRandomEnemy() {
	static const int MAX_LIFE{ 500 };
	static const std::string NAMES[]{
			"Khadgar",
			"Muradin",
			"Bolvar",
			"Jaina",
			"Medivh",
			"Kel'Thuzad"
	};
	return Enemy{
		static_cast<EnemyType>(rand() % static_cast<int>(EnemyType:: MAX)),
		NAMES[rand() % (sizeof NAMES / sizeof std::string)],
		rand() % MAX_LIFE
	};
}
void main() {
	srand(static_cast<unsigned>(time(nullptr)));
	const int MAX_ENEMIES{ 5 };
	Enemy enemies[MAX_ENEMIES];

	{
		int i{ 0 };
		while (i < MAX_ENEMIES) {
			enemies[i] = CreateRandomEnemy();
			int j{ i - 1 };
			while (j >= 0) {
				if (enemies[i] == enemies[j]) {
					--i;
					break;
				};
				j--;
			};
			++i;
		}
	}
		std::cout << "List of enemies:\n";
		for (auto &enemy : enemies) {
			std::cout << enemy.name <<
				"is a " << enemy.getEnemyTypeString() <<
				"whose life is " << enemy.health << std::endl;
		}
		return 0;
}