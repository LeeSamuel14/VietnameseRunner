#pragma once
#include <SDL.h>
namespace Engine
{
	class Window
	{
		private:
			SDL_Window* window_;
			int SCREEN_WIDTH;
			int SCREEN_HEIGHT;
	public:
			Window();
			~Window();
			SDL_Window* get_window();
	};
}

