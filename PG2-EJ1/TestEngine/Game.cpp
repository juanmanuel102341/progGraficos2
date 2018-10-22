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
	sprite = new Sprite(renderer);

	triangle->SetMaterial(material);
	triangle2->SetMaterial(material);
	colorShape->SetMaterial(material);
	circle->SetMaterial(material);
	sprite->SetMaterial(materialSprite);

	triangle->SetPos(5, 0, 0);
	//triangle->SetScale(3.0f, 3.0f, 3.0f);
	triangle2->SetPos(0, -5, 0);
	colorShape->SetPos(7, 0, 0);
	circle->SetPos(-5,5, 0);
	sprite->SetPos(0, 0, 0);
	
	triangle->Start();
	triangle2->Start();
	colorShape->Start();
	circle->Start();
	sprite->LoadBmp("testFrame.bmp");
	sprite->Start();
	sprite->SetFrame(0);
	return true;
}

bool Game::OnStop() {
	std::cout << "Game: Stop" << std::endl;
	triangle->Stop();
	triangle2->Stop();
	colorShape->Stop();
	circle->Stop();
	sprite->Stop();
	return true;
}
void Game::OnDraw() {
	circle->Draw();
	triangle->Draw();
	triangle2->Draw();
	colorShape->Draw();
	sprite->Draw();
}

bool Game::OnUpdate() {
	i++;
	//std::cout << "Game: OnUpdate: "<<i << std::endl;
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
