#pragma once
#include"Shape.h"
class ENGINEDLL_API ColorShape: public Shape
{
public:
	ColorShape(Renderer* renderer);
	void Start() override;
	
	void Stop()override;

private:
	

};
