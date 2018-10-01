#include "GameBase.h"

GameBase::GameBase() {
}

bool GameBase::Start() {

	std::cout << "Gamebase: Start" << std::endl;;
	bool good = true;
	window = new Window(800, 600, "motor sala");
	renderer = new Renderer(window);
	
	if (!window->Start()) {
		good = false;
	}
	if (!renderer->Start()) {
		good = false;
	}
	material = new Material(renderer);
	material->LoadShader();

	if (!OnStart()) { 
		good = false;
	}
	

	return good;
}

bool GameBase::Stop() {
	std::cout << "GameBase: Stop" << std::endl;
	bool good = true;
	if (!OnStop()) { 
		good = false;
	}
	if (!window->Stop()) {
		good = false;
	}
	if (!renderer->Stop()) {
		good = false; 
	}
	delete renderer;
	return good;
}

void GameBase::Loop() {
	bool loop = true;
	std::cout << "GameBase: Loop"<< std::endl;
	while (!window->ShouldClose()) {
		window->PollEvents();
		renderer->ClearColor();
		renderer->ClearScreen();
		OnUpdate();
		OnDraw();
		renderer->SwappBuffer();
	}

}