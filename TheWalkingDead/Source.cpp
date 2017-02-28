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
	void attack(Zombie &zombie);
	bool isAlive();
};


class Zombie {
public:
	int distanceToPlayer;
	float speed;
	float damage;
	int life;
	void attack(Player &jugador);
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
	return life > 0;
}
bool Zombie::isAlive() {
	return life > 0;
}

void main() {
	srand(time(nullptr));

	Player player;
	const int MAX_ZOMBIES{10};
	Zombie horda[MAX_ZOMBIES];

	player.weapon = Weapon(rand() % 6);
	player.precission = float(rand() % 2);
	player.life = rand() % 101;
	std::cout << "Player\n\tinitial life: " << player.life <<
		", weapon: "<< 
		", precision: " << player.precission << std::endl;
	std::cout << "ZOMBIES ARE COMING!" << std::endl;

	for (int i = 0; i < MAX_ZOMBIES; i++) {
		horda[i].distanceToPlayer = rand() % 201;
		horda[i].speed = rand() % 21;
		horda[i].damage = rand() % 21;
		horda[i].life = rand() % 101;
	}
	
	bool ZombiesAreAlive=true;
	do {

		ZombiesAreAlive = false;
		std::cout << "Player\n\tlife: " << player.life << std::endl;
		
			for (int i = 0; i < MAX_ZOMBIES; i++) {
				std::cout << "Zombie["<<i<<
					"]\n\tlife: "<< horda[i].life <<
					", distance: "<< horda[i].distanceToPlayer<<
					", speed: "<< horda[i].speed<<
					", damage: "<< horda[i].damage << std::endl;
				if (horda[i].isAlive()) {
					player.attack(horda[i]);
					horda[i].attack(player);
					ZombiesAreAlive=true;
				}
			}
	std::cout << "----------------------------------------" << std::endl;
	} while (player.isAlive() && ZombiesAreAlive);

	if (ZombiesAreAlive == false) {
		std::cout << "YOU WON!" << std::endl;
	}
	else {
		std::cout << "GAME OVER" << std::endl;
	}

}
