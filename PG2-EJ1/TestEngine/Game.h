#pragma once
#include "GameBase.h"
#include <iostream>

class Game : public GameBase {
private:
	float i;

	Triangle* triangle;

	ColorShape* colorShape;
	Circle* circle;
	Avatar* hero;
	Avatar* avatar2;

	Avatar* avatar3;
	Avatar* avatar4;
	TileMap* tileMap;
	vector<Avatar*>vecEnemies;

protected:
	bool OnStop() override;
	bool OnStart() override;
	void OnDraw() override;
	bool OnUpdate(double elapsed) override;
public:
	Game();
	~Game();
};

