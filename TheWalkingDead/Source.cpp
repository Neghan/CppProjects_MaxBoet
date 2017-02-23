#include <iostream>
#include <string>
#include <ctime>

enum class Weapon {FISTS, GUN, SHOTGUN,REVOLVER,SNIPER,MACHINE_GUN,MAX};

class Zombie;
class Player {
public:
	Weapon weapon;
	float precission;
	int life;
	void attack(Zombie &);
	bool isAlive();
};


class Zombie {
public:
	int distanceToPlayer;
	float speed;
	float damage;
	int life;
	void attack(Player &);
	bool isAlive();
};

void Player::attack(Zombie &zombie) {
	zombie.life = zombie.life - (int(weapon) * 10)*precission;

}

void Zombie::attack(Player &jugador) {
	if (distanceToPlayer <= 0) {
		jugador.life = jugador.life - damage;
	}
	else {
		distanceToPlayer--;
	}
}

bool Player::isAlive() {
	if (life >= 0) {
		return true;
	}
	else {
		return false;
	}
}
bool Zombie::isAlive() {
	if (life >= 0) {
		return true;
	}
	else {
		return false;
	}
}

void main() {
	srand(time(nullptr));

	Player player;
	Zombie horda[10];

	player.weapon = Weapon(rand() % 6);
	player.precission = float(rand() % 2);
	player.life = rand() % 101;

	for (int i = 0; i < 10; i++) {
		horda[i].distanceToPlayer = rand() % 201;
		horda[i].speed = rand() % 21;
		horda[i].damage = rand() % 21;
		horda[i].life = rand() % 101;
	}
	
	bool ZombiesAreAlive=true;
	do {

		ZombiesAreAlive = false;
			for (int i = 0; i < 10; i++) {
				if (horda[i].isAlive == true && player.isAlive==true) {
					ZombiesAreAlive = true;
					player.attack(horda[i]);
					horda[i].attack(player);
					break;
				}
				else {
					ZombiesAreAlive = false;
				}
			}

	} while (player.isAlive == true && ZombiesAreAlive == true);

	if (ZombiesAreAlive == false) {
		std::cout << "YOU WON!" << std::endl;
	}
	else {
		std::cout << "GAME OVER" << std::endl;
	}

}