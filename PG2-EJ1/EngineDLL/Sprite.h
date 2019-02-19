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
	void SetMyBackgroundData();
	void SetBackGroundVertices();
	void SetBackGroundFrames(int x,int y);
public:	
	int widthSprite;
	int heightSprite;
	int widthFrame;
	int heightFrame;
private:

private:
	
	
	float x, y;

	DataBmp data;
	ImporterBmp importBmp;

};
