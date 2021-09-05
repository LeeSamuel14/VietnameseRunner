#include "GameInit.h"

void Engine::GameInit::init_game_loop()
{
	bool quit{ false };
	SDL_Event event{};
	//SDL_Rect rect{ SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
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
