#include "Text.h"

Text::Text( SDL_Renderer* renderer ,std::string font_path, int font_size, std::string text, SDL_Color color)
	:	renderer_ { renderer },
		font_path_{ font_path },
		font_size_{ font_size },
		color_ { color }
{
	font_ = TTF_OpenFont(font_path.c_str(), font_size);
	if (!font_) { Utilities::print_error(); }

	SDL_Surface* temp_text_surface = TTF_RenderText_Solid(font_, text.c_str(), color);
	if (!temp_text_surface) { Utilities::print_error(); }

	font_texture_ = SDL_CreateTextureFromSurface(renderer_, temp_text_surface);
	if (!font_texture_) { Utilities::print_error(); }

	width_ = temp_text_surface->w;
	height_ = temp_text_surface->h;

	SDL_FreeSurface(temp_text_surface);
}

Text::~Text()
{
	destroy();
}
void Text::render(int x, int y)
{
	if (font_texture_ != nullptr)
	{
		SDL_Rect render_position{ x, y, width_, height_ };
		SDL_RenderCopy(renderer_, font_texture_, nullptr, &render_position);
	}
	else
	{
		throw std::string{ "Can't render, text not loaded" };
	}

}

void Text::update_text(std::string text)
{
	font_ = TTF_OpenFont(font_path_.c_str(), font_size_);
	if (!font_) { Utilities::print_error(); } 
	SDL_Surface* temp_text_surface = TTF_RenderText_Solid(font_, text.c_str(), color_);
	if (!temp_text_surface) { Utilities::print_error(); }

	font_texture_ = SDL_CreateTextureFromSurface(renderer_, temp_text_surface);
	if (!font_texture_) { Utilities::print_error(); }
	width_ = temp_text_surface->w;
	height_ = temp_text_surface->h;

	SDL_FreeSurface(temp_text_surface);
} 


void Text::destroy()
{
	if (font_)
	{
		TTF_CloseFont(font_);
	}
	if (font_texture_)
	{
		SDL_DestroyTexture(font_texture_);
		font_texture_ = nullptr;
		width_ = 0;
		height_ = 0;
	}
}
