#include "Game.h"



Game::Game() {
}


Game::~Game() {
}

bool Game::OnStart() {
	i = 0;
	std::cout << "Game: OnStart" << std::endl;
	triangle = new Triangle(renderer);
	triangle2 = new Triangle(renderer);

	triangle->SetMaterial(material);
	triangle2->SetMaterial(material);
	triangle->SetPos(5, 0, 0);
	triangle2->SetPos(0, 5, 0);
	triangle->Start();
	triangle2->Start();
	
	return true;
}

bool Game::OnStop() {
	std::cout << "Game: Stop" << std::endl;
	triangle->Stop();
	triangle2->Stop();

	return true;
}
void Game::OnDraw() {

	triangle->Draw();
	triangle2->Draw();
}

bool Game::OnUpdate() {
	i++;
	std::cout << "Game: OnUpdate: "<<i << std::endl;
	
	if (i >= 5) {
		return false;
	} else {
		return true;
	}
}
