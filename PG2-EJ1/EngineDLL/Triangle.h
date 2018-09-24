#pragma once
#include"Entity.h"
class ENGINEDLL_API Triangle: public Entity
{
public:
	Triangle(Renderer* renderer);
	 void Start() override;
	 void Draw()override;
	 void Stop()override;
	 
	
	 float* gvertices;
private:
	
	
};
