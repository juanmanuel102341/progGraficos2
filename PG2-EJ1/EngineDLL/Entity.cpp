#include"Entity.h"
Entity::Entity(Renderer* _renderer):renderer(_renderer),posX(0),posY(0){
	
	matrizTraslacion = glm::mat4(1.0f);
	matrizRotX = glm::mat4(1.0f);
	matrizRotacionY = glm::mat4(1.0f);
	matrizRotacionZ = glm::mat4(1.0f);
	matrizScale = glm::mat4(1.0f);
}
void Entity::UpdateMatrix() {
	matrizModel = matrizTraslacion*matrizRotX*matrizRotacionY*matrizRotacionZ*matrizScale;
}
void Entity::SetPos(float _x, float _y, float z) {
	posX = _x;
	posY = _y;
	verticesM[0] = _x;
	verticesM[1] = _y;
	verticesM[2] = z;
	
	matrizTraslacion=glm::translate(glm::mat4(1.0f),verticesM);
	UpdateMatrix();
}
void Entity::SetScale(float amountX, float amountY, float amountZ){
	
	glm::vec3 scale;
	scale[0] = amountX;
	scale[1] = amountY;
	scale[2] = amountZ;
	matrizScale=glm::scale(glm::mat4(1.0f),scale) ;
	UpdateMatrix();
}
void Entity::SetRotX(float angle){
	glm::vec3 axis;
	axis[0] = 1;
	axis[1] = 0;
	axis[2] = 0;
	matrizRotX=glm::rotate(matrizRotX, glm::radians(angle), axis);
	UpdateMatrix();

}
void Entity::SetRotY(float angle) {
	glm::vec3 axis;
	axis[0] = 0;
	axis[1] = 1;
	axis[2] = 0;
	matrizRotacionY = glm::rotate(matrizRotacionY, glm::radians(angle), axis);
	UpdateMatrix();

}
void Entity::SetRotZ(float angle) {
	glm::vec3 axis;
	axis[0] = 0;
	axis[1] = 0;
	axis[2] = 1;
	matrizRotacionZ = glm::rotate(matrizRotacionZ, glm::radians(angle), axis);
	UpdateMatrix();

}
void Entity::SetMoveX(float velocity) {
	posX += velocity;
	//cout << "posx " << posX << endl;
	glm::vec3 axis;
	axis[0] = velocity;
	axis[1] = 0;
	axis[2] = 0;
	matrizTraslacion=glm::translate(matrizTraslacion, axis);
	UpdateMatrix();

	
}
void Entity::SetMoveY(float velocity) {
	posY += velocity;
	glm::vec3 axis;
	axis[0] = 0;
	axis[1] = velocity;
	axis[2] = 0;
	matrizTraslacion = glm::translate(matrizTraslacion, axis);
	UpdateMatrix();
}
void Entity::SetMaterial(Material* _material) {
	material = _material;
}
