#include "Window.h"
#include <iostream>

SDL_Window* Engine::Window::window = nullptr;

void Engine::Window::create()
{
	int SCREEN_WIDTH { 1000 };
	int SCREEN_HEIGHT { 400 };
	window = SDL_CreateWindow("Engine::Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window) { std::cout << "Error with Window"; };
}

void Engine::Window::destroy()
{
	if(Engine::Window::window)
		SDL_DestroyWindow(window);
}
