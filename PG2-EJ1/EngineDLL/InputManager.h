#pragma once
#include"Renderer.h"


class ENGINEDLL_API InputManager
{
public:
	InputManager(Renderer* _renderer);
	void StartEvent();
	static void KeyCallBack(GLFWwindow* window, int key, int scanCode, int action, int mods);
private:
	Renderer* renderer;
	
	

	
};
