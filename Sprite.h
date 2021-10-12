#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Renderer.h"
#include <string>
namespace Engine
{
	namespace Types
	{
		namespace Graphics
		{
			class Sprite
			{
			private:
				
			public:
				SDL_Texture* texture_;
				int width_;
				int height_;
				Sprite(std::string path);
			};
		}
	}
}

