#include "GameBase.h"

GameBase::GameBase() {
}

bool GameBase::Start() {
	std::cout << "Gamebase: Starts" << std::endl;
	//std::cout << "prueba bmp" << std::endl;
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
	material->LoadShader(normal);
	materialSprite = new Material(renderer);
	materialSprite->LoadShader(sprite);
	colisionManager = new ColisionManager;
	animationManager = new Animation;
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
	delete material;
	delete materialSprite;
	delete colisionManager;
	delete animationManager;
	return good;
}

void GameBase::Loop() {
	bool loop = true;
	double elapsed=0;
	clock_t end = clock();
	//std::cout << "GameBase: Loop"<< std::endl;
	while (!window->ShouldClose()) {
		
		clock_t begin = clock();
		elapsed= double(begin - end) / CLOCKS_PER_SEC;
		end = begin;
		window->PollEvents();
		renderer->ClearColor();
		renderer->ClearScreen();
		OnUpdate(elapsed);
		OnDraw();
		renderer->SwappBuffer();
	//	 t += elapsed;

	
	}

}