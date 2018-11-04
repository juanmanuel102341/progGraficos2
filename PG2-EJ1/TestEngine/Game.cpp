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
	
	avatar1 = new Avatar(renderer);
	avatar2 = new Avatar(renderer);

	triangle->SetMaterial(material);
	triangle2->SetMaterial(material);
	colorShape->SetMaterial(material);
	circle->SetMaterial(material);
	avatar1->SetMaterial(materialSprite);
	avatar2->SetMaterial(materialSprite);

	triangle->SetPos(5, 0, 0);
	triangle2->SetPos(0, -5, 0);
	colorShape->SetPos(7, 0, 0);
	circle->SetPos(-5,5, 0);
	avatar1->SetPos(0, 0, 0);
	avatar2->SetPos(0, 4, 0);

	triangle->Start();
	triangle2->Start();
	colorShape->Start();
	circle->Start();
	avatar1->StartAvatar();
	avatar2->StartAvatar();
	
	avatar1->LoadBmp("testFrame.bmp");
	avatar1->SetFrame(0);
	avatar2->LoadBmp("testFrame.bmp");
	avatar2->SetFrame(0);

	colisionManager->RegisterBoundingBox(avatar1->box, A);
	colisionManager->RegisterBoundingBox(avatar2->box, B);

	
	return true;
}

bool Game::OnStop() {
	std::cout << "Game: Stop" << std::endl;
	triangle->Stop();
	triangle2->Stop();
	colorShape->Stop();
	circle->Stop();
	avatar1->StopAvatar();
	avatar2->StopAvatar();
	return true;
}
void Game::OnDraw() {
	circle->Draw();
	triangle->Draw();
	triangle2->Draw();
	colorShape->Draw();
	//sprite->Draw();
//	sprite2->Draw();
	avatar1->Draw();
	avatar2->Draw();
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
	
	
	avatar1->UpdatePosition();
	avatar2->UpdatePosition();
	colisionManager->OnCheckCollision();
	if (!avatar2->box->collide) {
	
		avatar2->SetMoveY(-0.002f);
	}
	if (i >= 5) {
		return false;
	} else {
		return true;
	}
}
