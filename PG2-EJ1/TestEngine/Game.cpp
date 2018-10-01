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
	colorShape = new ColorShape(renderer);
	circle = new Circle(renderer);

	triangle->SetMaterial(material);
	triangle2->SetMaterial(material);
	colorShape->SetMaterial(material);
	circle->SetMaterial(material);

	triangle->SetPos(5, 0, 0);
	triangle2->SetPos(0, -5, 0);
	colorShape->SetPos(0, 0, 0);
	circle->SetPos(-5,5, 0);
	
	triangle->Start();
	triangle2->Start();
	colorShape->Start();
	circle->Start();

	return true;
}

bool Game::OnStop() {
	std::cout << "Game: Stop" << std::endl;
	triangle->Stop();
	triangle2->Stop();

	return true;
}
void Game::OnDraw() {
	circle->Draw();
	triangle->Draw();
	triangle2->Draw();
	colorShape->Draw();
	
}

bool Game::OnUpdate() {
	i++;
	std::cout << "Game: OnUpdate: "<<i << std::endl;
	triangle->SetMoveX(0.002f);
	//triangle->SetMoveY(-0.002f);
	//triangle->SetRotX(1.0f);
	//triangle->SetRotY(1.0f);
	//triangle->SetRotZ(0.2f);
	triangle2->SetRotZ(0.2f);
	
	if (i >= 5) {
		return false;
	} else {
		return true;
	}
}
