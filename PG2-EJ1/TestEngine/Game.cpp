#include "Game.h"



Game::Game():vecEnemies(NULL),xBack(0) {
}


Game::~Game() {
}

bool Game::OnStart() {
	i = 0;
	
	std::cout << "Game: OnStart" << std::endl;
	//triangle = new Triangle(renderer);
	
	//colorShape = new ColorShape(renderer);
	//circle = new Circle(renderer);
	
	backGround = new Avatar(renderer);
	
	hero = new Avatar(renderer);

	//avatar2 = new Avatar(renderer);
	//avatar3 = new Avatar(renderer);
	//avatar4 = new Avatar(renderer);
	tileMap = new TileMap(renderer);
	//	triangle->SetMaterial(material);
	
	//colorShape->SetMaterial(material);
	//circle->SetMaterial(material);
	
	hero->SetMaterial(materialSprite);
	backGround->SetMaterial(materialSprite);
	//avatar2->SetMaterial(materialSprite);
	//avatar3->SetMaterial(materialSprite);
	//avatar4->SetMaterial(materialSprite);

	//tileMap->SetMaterial(materialSprite);

	//triangle->SetPos(5, 5, 0);
	
	//colorShape->SetPos(7, 0, 0);
	//circle->SetPos(-5,5, 0);
	//avatar1->SetPos(-10,10, 0);
	//avatar2->SetPos(0, -4, 0);
	//avatar3->SetPos(4, 0, 0);
	//avatar4->SetPos(4, 4, 0);
	//tileMap->SetPos(-10, 10, 0);
	//triangle->Start();
	
	//colorShape->Start();
	//circle->Start();
	
	//avatar2->StartAvatar();
	//avatar3->StartAvatar();
	//avatar4->StartAvatar();
	tileMap->Start();
	
	for (int i = 0; i < tileMap->asteroidsValues.size(); i++) {
		Avatar* asteroid = new Avatar(renderer);
		asteroid->SetMaterial(materialSprite);
		asteroid->SetMyVertices(tileMap->asteroidsValues[i]);
		asteroid->StartAvatar();
		asteroid->LoadBmp("recursosShooter.bmp");
		asteroid->posX = tileMap->dataAsteroids[i]->x;
		asteroid->posY = tileMap->dataAsteroids[i]->y;
		asteroid->SetObjectValues(boxCollider, movil, 1);
		asteroid->SetFrame(2);
		colisionManager->RegisterBoundingBox(asteroid->box, B);
		asteroids.push_back(asteroid);
	}
	for (int i = 0; i < tileMap->enemiesValues.size(); i++) {
		cout << "************entrando creacion enemy************" << endl;
		Avatar*enemy = new Avatar(renderer);
		enemy->SetMaterial(materialSprite);
		enemy->SetMyVertices(tileMap->enemiesValues[i]);
		enemy->StartAvatar();
		enemy->LoadBmp("recursosShooter.bmp");
		enemy->posX = tileMap->dataEnemies[i]->x;
		enemy->posY = tileMap->dataEnemies[i]->y;
		enemy->SetObjectValues(boxCollider, movil, 1);
		enemy->SetFrame(1);
	
		vecEnemies.push_back(enemy);
	}
	
	
	hero->SetMyVertices(tileMap->playerValues);

	hero->StartAvatar();
	backGround->SetBackGroundVertices();
	backGround->StartAvatar();
	backGround->SetMyBackgroundData();
	//tileMap->LoadBmp("testFrame2.bmp");
	//tileMap->SetFrame(1);
	hero->LoadBmp("recursosShooter.bmp");
	backGround->LoadBmp("backSpace.bmp");
	backGround->widthFrame = 1024.0f;
	backGround->heightFrame = 600.0f;
	backGround->SetBackGroundFrames(0,0);

	hero->SetFrame(0);
	//backGround->SetFrame(0);
	
	//avatar2->LoadBmp("testFrame2.bmp");
	//avatar3->LoadBmp("testFrame2.bmp");
	//avatar4->LoadBmp("testFrame2.bmp");

	hero->posX = tileMap->dataPlayer->x;
	hero->posY = tileMap->dataPlayer->y;
	hero->SetObjectValues(boxCollider, movil, 1);
	//avatar2->SetObjectValues(boxCollider, movil, 10);
	//avatar3->SetObjectValues(circleCollider, movil, 1);
	//avatar4->SetObjectValues(circleCollider, movil, 10);

	colisionManager->RegisterBoundingBox(hero->box, A);
	
	
	//colisionManager->RegisterBoundingCircle(avatar3->circle, A);
	//colisionManager->RegisterBoundingCircle(avatar4->circle, B);
	
	//hero->SetPos(tileMap->dataEnemies[2]->x, tileMap->dataEnemies[2]->y,0);
	//vecEnemies[2]->SetPos(, tileMap->dataPlayer.y+10, 0);
	//cout << "pos enemy 2 x" << tileMap->dataPlayer.x << endl;
	//cout << "pos enemy 2 y" << tileMap->dataPlayer.y << endl;
	
	//animationManager->SetAnimation(hero, tileMap->dataPlayer.idFrom, tileMap->dataPlayer.idTo,true);
	
	for (int i = 0; i < vecEnemies.size(); i++) {
		//animationManager->SetAnimation(vecEnemies[i], tileMap->dataEnemies[i]->idFrom, tileMap->dataEnemies[i]->idTo, true);
		if (i == 1) {
			colisionManager->RegisterBoundingBox(vecEnemies[i]->box,A);
		}
		else {
			colisionManager->RegisterBoundingBox(vecEnemies[i]->box, B);
		}
		}
	
	inputManager->StartEvent();
	
	//animationManager->SetAnimation(avatar3, 1, 2, true);
	//animationManager->SetAnimation(avatar4, 1, 2, true);
	return true;
}

bool Game::OnStop() {
	std::cout << "Game: Stop" << std::endl;
	//triangle->Stop();
	
	//colorShape->Stop();
	//circle->Stop();
	//hero->StopAvatar();
	//avatar2->StopAvatar();
	//avatar3->StopAvatar();
	//avatar4->StopAvatar();
	return true;
}
void Game::OnDraw() {
	//tileMap->Draw();
	//circle->Draw();
	//triangle->Draw();
	
	//colorShape->Draw();
	
	backGround->Draw();
	for (int i = 0; i < vecEnemies.size(); i++) {
		vecEnemies[i]->Draw();
	}
	for (int i = 0; i < asteroids.size(); i++) {
		asteroids[i]->Draw();
	}
	//avatar2->Draw();
	//avatar3->Draw();
	//avatar4->Draw();
	hero->Draw();
	
}

bool Game::OnUpdate(double elapsed) {
	i++;
	//std::cout << "Game: OnUpdate elapsed: "<<elapsed << std::endl;
	//triangle->SetMoveX(0.002f);
	
	//triangle->SetMoveY(-0.002f);
	//triangle->SetRotX(1.0f);
	//triangle->SetRotY(1.0f);
	//triangle->SetRotZ(0.2f);
	backGround->SetBackGroundFrames(xBack,0);
	backGround->SetMoveX(SCROLL_SPEED, elapsed);
	//cout << tileMap->target;
	if (renderer->mx > tileMap->target) {
	cout << "mx mayor " << endl;
	tileMap->MovingMap();
	//hero->PassingVerticesTileMap(tileMap->playerValues);
	int numEnemies = tileMap->dataEnemies.size()-vecEnemies.size();
	cout << "cantidad de enemigos nuevos " << numEnemies<<endl;
	int indexEnemy = tileMap->dataEnemies.size() - numEnemies;
	for (int i = 0; i < numEnemies; i++) {
		
		Avatar*enemy = new Avatar(renderer);
		enemy->SetMaterial(materialSprite);
		enemy->SetMyVertices(tileMap->enemiesValues[indexEnemy]);
		enemy->StartAvatar();
		enemy->LoadBmp("recursosShooter.bmp");
		enemy->posX = tileMap->dataEnemies[indexEnemy]->x;
		enemy->posY = tileMap->dataEnemies[indexEnemy]->y;
		enemy->SetObjectValues(boxCollider, movil, 1);
		//animationManager->SetAnimation(enemy, tileMap->dataEnemies[indexEnemy]->idFrom, tileMap->dataEnemies[indexEnemy]->idTo, true);
		enemy->SetFrame(1);
		if (i == 0) {
			colisionManager->RegisterBoundingBox(enemy->box, A);
		}
		else if (i == 1) {
			colisionManager->RegisterBoundingBox(enemy->box, B);
		}
		
		vecEnemies.push_back(enemy);
		indexEnemy++;
	}
	
	}
	
	renderer->ScrollCamera(elapsed);
	
	
	hero->UpdatePosition();
	//cout << "pos x hero " << hero->posX << endl;
	//cout << "pos y hero " << hero->posY << endl;
	//cout << "pos y hero " << hero->posY<<endl;
	for (int i = 0; i < vecEnemies.size(); i++) {
		vecEnemies[i]->UpdatePosition();
		//cout << "pos x enemy " << vecEnemies[0]->posX << endl;
		//cout << "pos y enemy " << vecEnemies[0]->posY << endl;
	}
	//avatar2->UpdatePosition();
	//avatar3->UpdatePosition();
	//avatar4->UpdatePosition();
	colisionManager->OnCheckCollisionBox();
	//colisionManager->OnCheckCollisionCircle();
	animationManager->Update(elapsed);
	if (!vecEnemies[vecEnemies.size()-2]->check) {
		//vecEnemies[vecEnemies.size()-2]->SetMoveY(-1.9f, elapsed);
		vecEnemies[vecEnemies.size() - 2]->SetMoveX(-1.9f, elapsed);
	
	}
	xBack += 2.8f*elapsed;
	if (xBack >= 3072.0f) {
		xBack = 0;
		cout << "cambiando!!!!!!!!! reseteo" << endl;
	}
	//cout << "xback " << xBack << endl;
	//if (!avatar4->check) {
		//avatar4->SetMoveY(-0.8f,elapsed);
	//}
	if (i >= 5) {
		return false;
	} else {
		return true;
	}
}
