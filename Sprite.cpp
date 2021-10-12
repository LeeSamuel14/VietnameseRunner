#include "Sprite.h"

Engine::Types::Graphics::Sprite::Sprite(std::string path)
{
	SDL_Surface* temp_surface{ IMG_Load(path.c_str()) };
	texture_ = SDL_CreateTextureFromSurface(Engine::Renderer::renderer, temp_surface);
	width_ = temp_surface->w;
	height_ = temp_surface->h;
	SDL_FreeSurface(temp_surface);
}
