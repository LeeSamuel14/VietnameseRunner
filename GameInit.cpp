#include "GameInit.h"

void Engine::GameInit::init_game_loop()
{
	bool quit{ false };
	SDL_Event event{};
	while (!quit)
	{
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
		
	}
}

	Engine::GameInit::GameInit()
	{
		
		init_game_loop();
	}
