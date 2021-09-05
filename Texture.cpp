#include "Texture.h"

Texture::Texture(SDL_Renderer* renderer)
{
	renderer_ = renderer;
	texture_ = nullptr;
	width_ = 0;
	height_ = 0;
}

Texture::~Texture()
{
	destroy();
}

bool Texture::load_from_file(std::string path)
{
	destroy();
	SDL_Surface* temp_surface { IMG_Load( path.c_str() ) };
	if (!temp_surface) { Utilities::print_error(); }
	set_transparent_background(temp_surface, 0, 0xFF, 0xFF);
	texture_ = SDL_CreateTextureFromSurface(renderer_, temp_surface);
	if (!texture_) { Utilities::print_error(); }
	width_ = temp_surface->w;
	height_ = temp_surface->h;
	SDL_FreeSurface(temp_surface);
	return true;
}

void Texture::destroy()
{
	if (texture_ != nullptr)
	{
		SDL_DestroyTexture(texture_);
		texture_ = nullptr;
		width_ = 0;
		height_ = 0;
	}
}

void Texture::set_transparent_background(SDL_Surface* surface, Uint8 r, Uint8 g, Uint8 b)
{
	Uint32 alpha_color = SDL_MapRGB(surface->format, r, g, b);
	SDL_SetColorKey(surface, SDL_TRUE, alpha_color);
	
}

void Texture::render(int x, int y)
{
	//SDL_SetTextureAlphaMod(texture_, 100);
	//SDL_SetTextureColorMod(texture_, 0, 150, 150);
	if (texture_ != nullptr)
	{
		SDL_Rect render_position{ x, y, width_, height_ };
		SDL_RenderCopy(renderer_, texture_, nullptr, &render_position);
	}
	else
	{
		throw std::string{ "Can't render, image not loaded" };
	}
	
}
int Texture::get_width()
{
	return width_;
}

int Texture::get_height()
{
	return height_;
}
