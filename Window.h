#pragma once
#include <SDL.h>
namespace Engine
{
	class Window
	{
		public:
			static SDL_Window* window;
			static void create();
			static void destroy();
	};
}

