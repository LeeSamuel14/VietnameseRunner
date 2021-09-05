#include "Window.h"
#include <iostream>

Engine::Window::Window()
	:	SCREEN_WIDTH { 1000 },
		SCREEN_HEIGHT { 400 }
{
	window_ = SDL_CreateWindow("Engine::Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window_) { std::cout << "Error"; };
	
}

Engine::Window::~Window()
{
	SDL_DestroyWindow(window_);
}

SDL_Window* Engine::Window::get_window()
{
	return window_;
}
