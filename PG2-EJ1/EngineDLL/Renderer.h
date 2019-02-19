#pragma once
#include "Exports.h"
#include"TypeDef.h"
#include <iostream>
#include"GL\glew.h"
#include"GLFW\glfw3.h"

#include"Window.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
const float SCROLL_SPEED = 0.2f;
enum Primitive {
	strip, fun,triangle
};
class ENGINEDLL_API Renderer {
public:
	bool Start();
	bool Stop();
	void ScrollCamera(float elapsed);
	void ClearColor();
	void ClearScreen();
	void SwappBuffer();
	unsigned int SetBufferData(float vertices[],int size );
	
	void BeginDraw(int id);
	void BindBuffer(unsigned int buffer, int id, int numberElements, int stride, char* offset);
	void BindTexture(unsigned int idText);
	void DrawBuffer(int tam,Primitive primitive);
	void EndDraw(int id);
	unsigned int LoadShader(const char * vertex_file_path, const char * fragment_file_path);
	void Bind(unsigned int idPorgram);
	void DeleteShader(unsigned int id);
	void DeleteVertexBuffer(unsigned int buffer);
	Renderer(Window* window);
	void LoadIdentity();
	void SetModelMatriz(glm::mat4 _model);
	~Renderer();
	glm::mat4& GetMVP();
	unsigned int GenTexture(int width,int height,unsigned char* data);
public:
	float mx;
	Window* window;
private:
	
	glm::mat4 matrizProyection;
	glm::mat4 matrizView;
	glm::mat4 matrizModel;
	glm::mat4 MVP;
	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	unsigned int vertexArrayId;
	float moveCamera;
	
	
private:
	void UpdateMVP();
	
};

