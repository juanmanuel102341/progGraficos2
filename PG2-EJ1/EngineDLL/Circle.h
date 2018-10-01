#pragma once
#include"Shape.h"
#include     <iostream>
#include     <cmath>
class ENGINEDLL_API Circle: public Shape
{
public:
	 Circle(Renderer* renderer);
	 void Start() override;
	 void Stop()override;

private:
	float radius;
	float numberOfVerticesCircle;
	float totalAngle;
	int angle;
	float Pi = 3.14159f;
};
