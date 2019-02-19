#pragma once
#include "Exports.h"
#include <iostream>
#include<string>
#include<iostream>
#include"GLFW\glfw3.h"
using namespace std;
class ENGINEDLL_API Window 
{
public:
	Window(int ancho, int alto, string nombre);
	
	bool Start();
	bool Stop();
	void PollEvents();
	bool ShouldClose();
	GLFWwindow* GetWindow();
	GLFWwindow* window;
private:
	
	int ancho;
	int alto;
	string nombre;

};

