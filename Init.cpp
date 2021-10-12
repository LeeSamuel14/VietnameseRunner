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
	//SDL_Rect rect{ SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	while (!quit)
	{
		SDL_RenderClear(Engine::Renderer::renderer);

		//SDL_RenderClear(Engine::Renderer::renderer);
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				/*if (event.key.keysym.sym == 's')
					ball->physics->move(0, 1000);
				if (event.key.keysym.sym == 'd')
					ball->physics->move(1000, 0);
				if (event.key.keysym.sym == 'w')
					ball->physics->move(0, -1000);
				if (event.key.keysym.sym == 'a')
					ball->physics->move(-1000, 0);*/

				break;
			case SDL_MOUSEMOTION:
				break;
			}
		}
		//SDL_RenderPresent(Engine::Renderer::renderer);
		SDL_RenderPresent(Engine::Renderer::renderer);
	}
}
