#include "Init.h"

Engine::Init::Init()
{
	create_window();
	create_renderer();
	init_game_loop();
}

void Engine::Init::create_window()
{
	window_ = new Engine::Window();
}

void Engine::Init::create_renderer()
{
	renderer_ = new Engine::Renderer(window_);
}

void Engine::Init::init_game_loop()
{
	bool quit{ false };
	SDL_Event event{};
	//SDL_Rect rect{ SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	while (!quit)
	{
		SDL_RenderClear(renderer_->get_renderer());
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				quit = true;
				break;
			case SDL_MOUSEMOTION:
				break;
			}
		}
		SDL_RenderPresent(renderer_->get_renderer());
	}
}
