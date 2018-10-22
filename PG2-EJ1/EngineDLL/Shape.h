#pragma once
#include"Entity.h"

class ENGINEDLL_API Shape: public Entity
{
protected:
	float* gvertices;
	unsigned int vertexBuffer;
	int numberOfVertices;//para draw
	Primitive primitive;//para draw
	bool applyUv;
	unsigned int idTexture;
	int tam;
public:
	Shape(Renderer* renderer);
	virtual void Start() = 0;
	 virtual void Stop() = 0;
	 void Draw();
private:

};

