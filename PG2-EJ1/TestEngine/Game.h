#pragma once
#include "GameBase.h"
#include <iostream>
#pragma comment(lib,"..\\external\\glew-2.1.0\\lib\\Release\\Win32\\glew32.lib")
#pragma comment(lib,"..\\external\\glfw-3.2.1\\lib-vc2015\\glfw3.lib")

class Game : public GameBase {
private:
	float i;

	Triangle* triangle;
	
	ColorShape* colorShape;
	Circle* circle;
	Avatar* hero;
	vector< Avatar*> asteroids;
	Avatar* avatar2;
	Avatar* backGround;
	vector<Avatar>* vecBackground;
	Avatar* avatar3;
	Avatar* avatar4;
	TileMap* tileMap;
	vector<Avatar*>vecEnemies;
	float xBack;
private:
	
protected:
	bool OnStop() override;
	bool OnStart() override;
	void OnDraw() override;
	bool OnUpdate(double elapsed) override;
public:
	Game();
	~Game();
};

