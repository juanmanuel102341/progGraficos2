#include"InputManager.h"

void InputManager::KeyCallBack(GLFWwindow* window, int key, int scanCode, int action, int mods) {
	if (key == GLFW_KEY_A&&action==GLFW_PRESS) {
		cout << "apretando a" << endl;
	
	}
	cout << "entrando tecla " << endl;

}
void InputManager::StartEvent() {
	glfwSetKeyCallback(renderer->window->GetWindow(), KeyCallBack);
	glfwSetInputMode(renderer->window->GetWindow(), GLFW_STICKY_KEYS, 1);
}
InputManager::InputManager(Renderer* _render) :renderer(_render) {
	
	cout << "**************entrando manager********************" << endl;
}


