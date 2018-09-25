#pragma once
#include"Entity.h"
class ENGINEDLL_API ColorShape: public Entity
{
public:
	ColorShape(Renderer* renderer);
	void Start() override;
	void Draw()override;
	void Stop()override;

private:
	float* gvertices;

};
