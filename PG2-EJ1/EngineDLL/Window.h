#pragma once
#include "Exports.h"
#include <iostream>
#include<string>
#include<iostream>
using namespace std;
class ENGINEDLL_API Window 
{
public:
	Window(int ancho, int alto, string nombre);
	
	bool Start();
	bool Stop();
	void PollEvents();
	bool ShouldClose();
	void* GetWindow();
private:
	void* window;
	int ancho;
	int alto;
	string nombre;

};

