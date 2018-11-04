#pragma once
#include"Renderer.h"
#include"Material.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;
class ENGINEDLL_API Entity
{
protected:
	Renderer* renderer;
	Material* material;
	glm::mat4 matrizModel;
	
public:
	//	Entity();
	Entity(Renderer* _renderer);
	virtual void Start() = 0;
	virtual void Draw() = 0;
	virtual void Stop() = 0;
	void SetPos(float x, float y, float z);
	void SetRotX(float angle);
	void SetRotY(float angle);
	void SetRotZ(float angle);
	void SetScale(float amountX,float amountY,float amountZ);
	void SetMoveX(float velocity);
	void SetMoveY(float velocity);
	//~Entity();
	void SetMaterial(Material* material);

public:
	float posX, posY;
	//unsigned int bufferColor;
private:
	glm::vec3 verticesM;
	glm::mat4 matrizTraslacion;
	glm::mat4 matrizRotX;
	glm::mat4 matrizRotacionY;
	glm::mat4 matrizRotacionZ;
	glm::mat4 matrizScale;

private:
	void UpdateMatrix();
		
};
