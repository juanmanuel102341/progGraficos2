#pragma once
#include"Renderer.h"
enum MaterialType {
	normal,sprite
};
class ENGINEDLL_API Material
{
public:
	Material(Renderer* _renderer);
	void LoadShader(MaterialType mat);
	void Bind();
	void Stop();
	void SetMatrixMaterial(glm::mat4 &mat);
	void SetSpriteMaterial(unsigned int idTexture);
private:
	Renderer* renderer;
	unsigned int programId;
	unsigned int matrixId;
};
