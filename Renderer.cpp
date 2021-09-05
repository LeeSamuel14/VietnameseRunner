#include "Renderer.h"

Engine::Renderer::Renderer(Engine::Window* window)
{
	renderer_ = SDL_CreateRenderer(window->get_window(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer_) { std::cout << "Error"; };
	SDL_SetRenderDrawColor(renderer_, 0xFF, 0x56, 0x125, 0xFF);
}

Engine::Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer_);
}

SDL_Renderer* Engine::Renderer::get_renderer()
{
	return renderer_;
}
