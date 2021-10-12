#pragma once
#include <SDL.h>
#include "Window.h"
#include <iostream>
namespace Engine
{
	class Renderer
	{

		public:
			static SDL_Renderer* renderer;
			static void create();
			static void destroy();
	};

}
