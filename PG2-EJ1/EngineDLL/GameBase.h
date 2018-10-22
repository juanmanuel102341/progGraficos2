#pragma once
#include"TypeDef.h"
#include "Exports.h"
#include "Renderer.h"
 #include <iostream>
#include"Entity.h"
#include"Triangle.h"
#include"ColorShape.h"
#include"Material.h"
#include"Shape.h"
#include"Circle.h"
#include"Sprite.h"
class ENGINEDLL_API GameBase {

protected:
	Renderer* renderer;
	Material* material;
	Material* materialSprite;
private:
	
	Window* window;

protected:
	virtual bool OnStart() = 0;
	virtual bool OnStop() = 0;
	virtual bool OnUpdate() = 0;
	virtual void OnDraw() = 0;
public:
	bool Start();
	bool Stop();
	void Loop();
	GameBase();
	virtual ~GameBase() {};
};

