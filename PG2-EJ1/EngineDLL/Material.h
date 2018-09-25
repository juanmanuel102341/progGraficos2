#pragma once
#include"Renderer.h"
class ENGINEDLL_API Material
{
public:
	Material(Renderer* _renderer);
	void LoadShader();
	void Bind();
	void Stop();
	void SetMatrixMaterial(glm::mat4 &mat);
	
private:
	Renderer* renderer;
	unsigned int programId;
	unsigned int matrixId;
};
