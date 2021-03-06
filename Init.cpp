#include "Init.h"

Engine::Init::Init()
{
	create_window();
	create_renderer();
	init_game_loop();
}

Engine::Init::~Init()
{
	Engine::Window::destroy();
}

void Engine::Init::create_window()
{
	Engine::Window::create();
}

void Engine::Init::create_renderer()
{
	Engine::Renderer::create();
}

void Engine::Init::init_game_loop()
{
	bool quit{ false };
	SDL_Event event{};
	while (!quit)
	{
		SDL_RenderClear(Engine::Renderer::renderer);
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				break;
			case SDL_MOUSEMOTION:
				break;
			}
		}
		SDL_RenderPresent(Engine::Renderer::renderer);
	}
}
