#pragma once
#include"Shape.h"
class ENGINEDLL_API Triangle: public Shape
{
public:
	Triangle(Renderer* renderer);
	 void Start() override;
	
	 void Stop()override;
	 
	
	 
private:
	
	
};
