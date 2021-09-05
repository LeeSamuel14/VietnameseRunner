#pragma once
#include <string>
#include <SDL.h>
#include "SDL_image.h"
#include "Texture.h"
#include "Utilities.h"


class Animation
{
	private:
		SDL_Renderer* renderer_;
		SDL_Texture* sprite_sheet_;
		int current_frame_;
		int frame_total_count_;
		int frame_width_;
		int frame_height_;
		//make dynamic
		SDL_Rect frames_ [8];
		bool load_from_file(std::string path);
	public:
		//these class should inherrit from Texture/Game so they can access renderer, window etc all global
		//thats how you deal with global variables! Use inheritance??? Static?
		Animation(SDL_Renderer* renderer, int frames, int frame_width, int frame_height, std::string path);
		void render(int x, int y);
};

