#pragma once
#include "Exports.h"
#include <iostream>
#include"Window.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
enum Primitive {
	strip, fun
};
class ENGINEDLL_API Renderer {
public:
	bool Start();
	bool Stop();

	void ClearColor();
	void ClearScreen();
	void SwappBuffer();
	unsigned int SetBufferData(float vertices[],int size );
	
	void BeginDraw(int id);
	void BindBuffer(unsigned int buffer,int id,char* num2);
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
	glm::mat4 GetMVP();
private:
	Window* window;
	glm::mat4 matrizProyection;
	glm::mat4 matrizView;
	glm::mat4 matrizModel;
	glm::mat4 MVP;
	unsigned int vertexArrayId;
private:
	void UpdateMVP();
	
};

