#pragma once
#include <SDL.h>
#include "SDL_image.h"
#include <SDL_mixer.h>
#include "Texture.h"
#include "Utilities.h"
#include "Animation.h"
#include "Text.h"
#include "Sound.h"
#include "Timer.h"

class Game
{
private:
	SDL_Window* window_;
	SDL_Surface* surface_;
	SDL_Renderer* renderer_;
	SDL_Texture* texture_;

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	SDL_Event get_user_input();
	void load_media();

	void render_image();
	void render_shape(SDL_Rect* rect);
	void render_viewport();

public:
	Game();
	~Game();
	void init_game_loop();
	SDL_Renderer* get_renderer();

};