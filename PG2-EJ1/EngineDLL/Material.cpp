#include"Material.h"
#include"GL\glew.h"
#include"GLFW\glfw3.h"
Material::Material(Renderer* _renderer) {
	renderer = _renderer;
}
void Material::LoadShader(MaterialType mat) {
	switch (mat)
	{
	case normal:
		programId = renderer->LoadShader("SimpleTransform.vertexshader", "SimpleFragmentShader.fragmentshader");
		break;
	case sprite:
		programId= renderer->LoadShader("SimpleTransformUV.vertexshader", "SimpleFragmentShaderUV.fragmentshader");
		break;
	default:
		break;
	}
	
}
void Material::Bind() {
	renderer->Bind(programId);
}
void Material::SetMatrixMaterial(glm::mat4 &mat) {
	matrixId = glGetUniformLocation(programId, "MVP");
	glUniformMatrix4fv(matrixId, 1, GL_FALSE, &mat[0][0]);
}
void Material::SetSpriteMaterial(unsigned int idTexture) {
	unsigned int TextureID= glGetUniformLocation(programId, "myTextureSampler");
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, idTexture);
	glUniform1i(TextureID, 0);

}

void Material::Stop() {
	renderer->DeleteShader(programId);
}