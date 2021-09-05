#pragma once
#include <string>
#include <SDL.h>
#include "SDL_image.h"
#include "Utilities.h"

class Texture
{
private:
	SDL_Texture* texture_;
	SDL_Renderer* renderer_;
	int width_;
	int height_;
public: 
	Texture(SDL_Renderer* renderer);
	~Texture();
	bool load_from_file(std::string path);
	void set_transparent_background(SDL_Surface* surface, Uint8 r, Uint8 g, Uint8 b);
	void render();
	void destroy();
	//needs the rendered
	void render(int x, int y);
	int get_width();
	int get_height();
};

