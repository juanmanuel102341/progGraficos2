#include "Game.h"



Game::Game() {
}


Game::~Game() {
}

bool Game::OnStart() {
	i = 0;
	std::cout << "Game: OnStart" << std::endl;
	//triangle = new Triangle(renderer);
	
	//colorShape = new ColorShape(renderer);
	//circle = new Circle(renderer);
	
	avatar1 = new Avatar(renderer);
	avatar2 = new Avatar(renderer);
	avatar3 = new Avatar(renderer);
	avatar4 = new Avatar(renderer);

	//triangle->SetMaterial(material);
	
	//colorShape->SetMaterial(material);
	//circle->SetMaterial(material);
	
	avatar1->SetMaterial(materialSprite);
	avatar2->SetMaterial(materialSprite);
	avatar3->SetMaterial(materialSprite);
	avatar4->SetMaterial(materialSprite);

	//triangle->SetPos(5, 0, 0);
	
	//colorShape->SetPos(7, 0, 0);
	//circle->SetPos(-5,5, 0);
	avatar1->SetPos(0,0, 0);
	avatar2->SetPos(0, -4, 0);
	avatar3->SetPos(4, 0, 0);
	avatar4->SetPos(4, 4, 0);

	//triangle->Start();
	
	//colorShape->Start();
	//circle->Start();
	avatar1->StartAvatar();
	avatar2->StartAvatar();
	avatar3->StartAvatar();
	avatar4->StartAvatar();

	avatar1->LoadBmp("testFrame2.bmp");
	//avatar1->SetFrame(0);
	avatar2->LoadBmp("testFrame2.bmp");
	avatar3->LoadBmp("testFrame2.bmp");
	avatar4->LoadBmp("testFrame2.bmp");

	//avatar2->SetFrame(2);
	
	avatar1->SetObjectValues(boxCollider, fijo, 1);
	avatar2->SetObjectValues(boxCollider, movil, 10);
	avatar3->SetObjectValues(circleCollider, fijo, 1);
	avatar4->SetObjectValues(circleCollider, movil, 10);

	colisionManager->RegisterBoundingBox(avatar1->box, A);
	colisionManager->RegisterBoundingBox(avatar2->box, B);
	colisionManager->RegisterBoundingCircle(avatar3->circle, A);
	colisionManager->RegisterBoundingCircle(avatar4->circle, B);
	
	animationManager->SetAnimation(avatar1, 1, 2,true);
	animationManager->SetAnimation(avatar2, 1, 2,true);
	animationManager->SetAnimation(avatar3, 1, 2, true);
	animationManager->SetAnimation(avatar4, 1, 2, true);
	return true;
}

bool Game::OnStop() {
	std::cout << "Game: Stop" << std::endl;
	//triangle->Stop();
	
	//colorShape->Stop();
	//circle->Stop();
	avatar1->StopAvatar();
	avatar2->StopAvatar();
	avatar3->StopAvatar();
	avatar4->StopAvatar();
	return true;
}
void Game::OnDraw() {
	//circle->Draw();
	//triangle->Draw();
	
	//colorShape->Draw();
	//sprite->Draw();
//	sprite2->Draw();
	avatar1->Draw();
	avatar2->Draw();
	avatar3->Draw();
	avatar4->Draw();
}

bool Game::OnUpdate(double elapsed) {
	i++;
	//std::cout << "Game: OnUpdate elapsed: "<<elapsed << std::endl;
	//triangle->SetMoveX(0.002f);
	
	//triangle->SetMoveY(-0.002f);
	//triangle->SetRotX(1.0f);
	//triangle->SetRotY(1.0f);
	//triangle->SetRotZ(0.2f);
	
	
	
	avatar1->UpdatePosition();
	avatar2->UpdatePosition();
	avatar3->UpdatePosition();
	avatar4->UpdatePosition();
	colisionManager->OnCheckCollisionBox();
	colisionManager->OnCheckCollisionCircle();
	animationManager->Update(elapsed);
	if (!avatar2->check) {
	
		//avatar2->SetMoveX(-0.002f);
		//avatar2->SetMoveX(0.002f);
	avatar2->SetMoveY(0.002f);
	}
	if (!avatar4->check) {
		avatar4->SetMoveY(-0.002f);
	}
	if (i >= 5) {
		return false;
	} else {
		return true;
	}
}
