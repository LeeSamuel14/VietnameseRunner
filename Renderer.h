#pragma once
#include <SDL.h>
#include "Window.h"
#include <iostream>
namespace Engine
{
	class Renderer
	{
	private:
		Engine::Window* window_;
		SDL_Renderer* renderer_;

	public:
		Renderer(Engine::Window* window);
		~Renderer();
		SDL_Renderer* get_renderer();
	};

}
