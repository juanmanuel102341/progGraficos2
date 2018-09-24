#pragma once
#include "GameBase.h"
#include <iostream>
class Game : public GameBase {
private:
	int i;
	Triangle* triangle;
	Triangle* triangle2;
protected:
	bool OnStop() override;
	bool OnStart() override;
	void OnDraw() override;
	bool OnUpdate() override;
public:
	Game();
	~Game();
};

