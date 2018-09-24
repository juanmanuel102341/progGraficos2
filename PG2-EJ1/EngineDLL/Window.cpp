#include"Window.h"
#include"GLFW\glfw3.h"
Window::Window(int _ancho, int _alto, string _nombre) {
	ancho = _ancho;
	alto = _alto;
	nombre = _nombre;
}
bool Window::Start() {
	if (!glfwInit()) {
		cout << "glfw3 no inicializado ";
		//return false;
	}
	window = glfwCreateWindow(640, 480, "VENTANA DE EJEMPLO", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return false;
	}
	return true;
}
bool Window::Stop() {

	if (window != NULL)
	glfwDestroyWindow((GLFWwindow*)window);
	
	window = NULL;

	glfwTerminate();
	cout << "saliendo de ventana";
	return true;
}
bool Window::ShouldClose() {
	if (window) {
		return glfwWindowShouldClose((GLFWwindow*)window);
	}
}
void Window::PollEvents() {
	glfwPollEvents();
}
void* Window::GetWindow() {
	return window;
}
