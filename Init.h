#pragma once
#include <SDL.h>
#include "Window.h"
#include "Renderer.h"
namespace Engine
{
	class Init
	{
		private:
			Engine::Window* window_;
			Engine::Renderer* renderer_;
			void create_window();
			void create_renderer();
			void init_game_loop();
		public:
			Init();
	};
}

