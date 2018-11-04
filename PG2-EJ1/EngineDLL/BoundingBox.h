#pragma once
#include "Exports.h"
#include <iostream>     // std::cout
#include <cmath>        // std::abs
using namespace std;
class ENGINEDLL_API BoundingBox
{
public:
	BoundingBox();
	void SetValues(float x, float y, int widht, int height);
	bool OnCollision(BoundingBox* boxB);
	void UpdatePosition(float x, float y);
public:
	bool collide;
private:
	float x,y;
	int BoundingWidht, boundingHeight;


};
