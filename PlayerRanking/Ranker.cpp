#include <iostream>
#include <vector>
#include <string>
#include <map>



struct Player {
	std::string nombre;
	int puntuacion;
};

void SotringAlg(int a) {
	
}


void main() {

	Player Jose;
	Jose.nombre = "Jose";
	Jose.puntuacion = 2134;
	Player Manuel;
	Manuel.nombre = "Manuel";
	Manuel.puntuacion = 2134;
	Player Carlos;
	Manuel.nombre = "Carlos";
	Manuel.puntuacion = 3214;
	std::vector<Player>VectorRank({ Jose, Manuel, Carlos });
	int i = 0;
	Player temp;
	for (auto &it : VectorRank) {
		if (VectorRank[i].puntuacion < VectorRank[i++].puntuacion) {
			temp = VectorRank[i++];
			VectorRank[i++] = VectorRank[i];
			VectorRank[i] = temp;
		}
	}
}