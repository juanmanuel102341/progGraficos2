#pragma once
#include "GameBase.h"
#include <iostream>

class Game : public GameBase {
private:
	int i;
	Triangle* triangle;
	Triangle* triangle2;
	ColorShape* colorShape;
	Circle* circle;
	Avatar* avatar1;
	Avatar* avatar2;
protected:
	bool OnStop() override;
	bool OnStart() override;
	void OnDraw() override;
	bool OnUpdate(double elapsed) override;
public:
	Game();
	~Game();
};

