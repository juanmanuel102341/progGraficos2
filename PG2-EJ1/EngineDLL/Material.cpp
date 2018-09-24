#include"Material.h"
#include"GL\glew.h"
#include"GLFW\glfw3.h"
Material::Material(Renderer* _renderer) {
	renderer = _renderer;
}
void Material::LoadShader() {

	programId = renderer->LoadShader("SimpleTransform.vertexshader", "SimpleFragmentShader.fragmentshader");
}
void Material::Bind() {
	renderer->Bind(programId);
}
void Material::SetMatrixMaterial(glm::mat4 &mat) {
	matrixId = glGetUniformLocation(programId, "MVP");
	glUniformMatrix4fv(matrixId, 1, GL_FALSE, &mat[0][0]);
}
void Material::Stop() {
	renderer->DeleteShader(programId);
}