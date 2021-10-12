#include "Renderer.h"

SDL_Renderer* Engine::Renderer::renderer = nullptr;

void Engine::Renderer::create()
{
	renderer = SDL_CreateRenderer(Engine::Window::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) { std::cout << "Error with renderer"; }; 
	SDL_SetRenderDrawColor(renderer, 0x80, 0x140, 0x170, 0x200);
}

void Engine::Renderer::destroy()
{
	SDL_DestroyRenderer(renderer);
}
