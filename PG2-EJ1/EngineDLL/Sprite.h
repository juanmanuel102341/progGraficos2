#pragma once
#include"Shape.h"
#include"ImporterBmp.h"

#include <cmath>        // std::abs

class ENGINEDLL_API Sprite: public Shape
{
public:
	Sprite(Renderer* renderer);
	void Start() override;
	void LoadBmp(const char* imagePath);
	void Stop()override;
	void SetFrame(int id);
	void SetFrameValues();
	void SetMyVertices(float* vertices);
	void PassingVerticesTileMap(float*vertices);
public:	
	int widthSprite;
	int heightSprite;
	
private:

private:
	int widthFrame;
	int heightFrame;
	
	float x, y;

	DataBmp data;
	ImporterBmp importBmp;

};
