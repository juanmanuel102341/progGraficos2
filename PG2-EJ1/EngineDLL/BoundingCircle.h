#pragma once
#include "Exports.h"
#include <iostream>     // std::cout
#include <cmath>        // std::abs
using namespace std;
enum StateObjectCircle {
	fijoCircule, movileCircule,triggerCircle
};
class ENGINEDLL_API BoundingCircle
{
public:
	 BoundingCircle();
	 void SetValues(float x, float y, float radius);
	 void UpdatePosition(float x, float y);
	 bool OnCollision(BoundingCircle* circleB);
	 StateObjectCircle state;
	 bool collide;
	 BoundingCircle* targetColision;
	 float directionX;
	 float directionY;
	 float pen;
	 float mass;
private:
	float x, y, radius;
	
	
	
};

