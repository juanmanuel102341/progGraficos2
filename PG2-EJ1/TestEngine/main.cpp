#include "Game.h"
#include <iostream>
using namespace std;
int main() {
	Game* juego = new Game();
	if (juego->Start()) {
		juego->Loop();
	}

	if (juego->Stop()) {
		cout << "Sale" << endl;
	}

	delete juego;

	return 0;
}