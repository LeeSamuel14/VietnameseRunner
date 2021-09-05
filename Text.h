#pragma once
#include <SDL_ttf.h>
#include <string>
#include "Utilities.h"

class Text
{
	private:
		TTF_Font* font_;
		int font_size_;
		SDL_Texture* font_texture_;
		SDL_Renderer* renderer_;
		int width_;
		int height_;
		std::string font_path_;
		SDL_Color color_;

	public:
		Text(SDL_Renderer* renderer, std::string font_path, int font_size, std::string text, SDL_Color color);
		~Text();
		void render(int x, int y);
		void update_text(std::string text);
		void destroy();


};

