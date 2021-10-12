#include <iostream>
#include "Game.h"
#include "Time.h"

Game::Game()
{
	SCREEN_WIDTH =  1000;
	SCREEN_HEIGHT =  320;
	window_ = SDL_CreateWindow("Game Class Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window_) { Utilities::print_error(); }
	surface_ = SDL_GetWindowSurface(window_);
	if (!surface_) { Utilities::print_error(); }
	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer_) { Utilities::print_error(); }
	SDL_SetRenderDrawColor(renderer_, 0xFF, 0x00, 0xFF, 0xFF);
	init_game_loop_2();
}

Game::~Game()
{
	SDL_DestroyTexture(texture_);
	SDL_FreeSurface(surface_);
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
}

SDL_Renderer* Game::get_renderer()
{
	return renderer_;
}

void Game::init_game_loop()
{
	bool quit{ false };
	SDL_Event event{};
	SDL_Rect rect{ SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	while (!quit)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				quit = true;
				break;
			case SDL_MOUSEMOTION:
				break;
			}
		}

		SDL_RenderClear(renderer_);
		SDL_RenderPresent(renderer_);
	}
}

void Game::init_game_loop_2()
{
	bool quit{ false };
	SDL_Event event{};
	Uint32 times_mouse_moved{};
	SDL_Rect rect { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	int seconds{ 0 };
	int minutues{ 0 };
	int counted_frames { 0 };
	double avg_fps { 0.0 };

	Timer fps_timer{ };
	fps_timer.start();
	Text ui_text { 
					renderer_, 
					"Roblox.ttf", 
					60, 
					"1234",
					{255, 255, 0} 
				};
	Text time_text {
					renderer_,
					"Roblox.ttf",
					80,
					"Time",
					{135, 67, 150}
	};
	Text timer_text {
					renderer_,
					"Roblox.ttf",
					80,
					"Time",
					{135, 67, 150}
	};
	Text fps_timer_text {
					renderer_,
					"Roblox.ttf",
					80,
					"FPS",
					{80, 120, 40}
	};
	Time time{ };
	Timer timer{};
	Animation walking_man { 
					renderer_, 
					8, 
					100, 
					100, 
					std::string {"tut-pics/walking-animation.png"} 
	};
	Sound tap { "high.wav", true };
	Sound background_music{ "wind.wav", false };
	background_music.play(-1);
	//Texture man{ renderer_ };
	Texture background{ renderer_ };
	Texture background_2{ renderer_ };
	//man.load_from_file("tut-pics/man.png");
	background.load_from_file("tut-pics/landscape.png");
	background_2.load_from_file("tut-pics/landscape.png");
	int man_x_pos{ SCREEN_WIDTH / 2 - 100 / 2 };
	int background_pos_x{ 0 };
	int background_2_pos_x{ SCREEN_WIDTH + SCREEN_WIDTH/2 };
	load_media();
	while (!quit)
	{
		
		
		//event = get_user_input();
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_RIGHT)
					man_x_pos += 15;
				if (event.key.keysym.sym == SDLK_LEFT)
					man_x_pos -= 15;
				if (event.key.keysym.sym == SDLK_s)
					if (timer.is_started())
						timer.stop();
					else
						timer.start();
				if (event.key.keysym.sym == SDLK_p)
					if (timer.is_paused())
						timer.unpause();
					else
						timer.pause();
				//tap.play(0);
				break;
			case SDL_MOUSEMOTION:
				if (rect.x > SCREEN_WIDTH)
					rect.x = 0 - rect.w;
				else
					rect.x += 5;
				++times_mouse_moved;
				//std::cout << times_mouse_moved << "\n";
				break;
			}
		}
		
		SDL_RenderClear(renderer_);
		background.render(background_pos_x, 0);
		background_2.render(background_pos_x, 0);
		//background_pos_x -= 1;
		background_2_pos_x -= 1;
		if (background_pos_x + SCREEN_WIDTH < 0) {
			//background_pos_x = SCREEN_WIDTH;
		}
		if (background_2_pos_x + SCREEN_WIDTH < 0) {
			background_2_pos_x = SCREEN_WIDTH;
		}

		//man.render(man_x_pos, SCREEN_HEIGHT - man.get_height());
		walking_man.render(man_x_pos, SCREEN_HEIGHT - 100);
		if (seconds % 10 == 0)
		{
			time_text.update_text(std::to_string(time.get_time_text()));
		}

		timer_text.update_text(std::to_string( timer.get_ticks() / 1000));

		avg_fps = counted_frames / (fps_timer.get_ticks() / 1000.00);
		fps_timer_text.update_text(std::to_string(avg_fps));
		//time_text.update_text(std::to_string(time.get_time_text()));
		//std::cout << std::to_string(time.get_time_text()) <<'\n';
		//time_text.render(100, 100);
		//timer_text.render(100, 100);
		//fps_timer_text.render(0, 0);
		//ui_text.render(0, 0);
		SDL_RenderPresent(renderer_);
		++seconds;
		if (seconds % 10 == 0)
		{
			minutues++;
		}

		//render_shape(&rect);
		//render_image();
		//render_viewport();
		++counted_frames;
	}
}

void Game::load_media()
{
	
	
	//can delete lines below
	/*SDL_Surface* surface{ IMG_Load("fire-man.png") };
	if (!surface) { Utilities::print_error(); }
	texture_ = SDL_CreateTextureFromSurface(renderer_, surface);
	if (!texture_) { Utilities::print_error(); }

	SDL_FreeSurface(surface);*/

}

SDL_Event Game::get_user_input()
{
	SDL_Event event;

	while (SDL_PollEvent(&event) != 0)
	{
		return event;
	}
}

void Game::render_shape(SDL_Rect* rect)
{
	SDL_SetRenderDrawColor(renderer_, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer_);
	SDL_SetRenderDrawColor(renderer_, 0x00, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer_, rect);
	SDL_RenderPresent(renderer_);
}


void Game::render_image()
{
	SDL_RenderClear(renderer_);
	SDL_RenderCopy(renderer_, texture_, nullptr, nullptr);
	SDL_RenderPresent(renderer_);
}

void Game::render_viewport()
{
	SDL_Rect map{ 0, 0, 50, 50 };
	SDL_Rect world{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_RenderClear(renderer_);
	
	SDL_SetRenderDrawColor(renderer_, 0x00, 0x00, 0x00, 0x32);

	SDL_RenderSetViewport(renderer_, &world);
	SDL_SetRenderDrawColor(renderer_, 0x00, 0xFF, 0x00, 0);
	SDL_RenderFillRect(renderer_, &world);

	SDL_RenderSetViewport(renderer_, &map);
	SDL_SetRenderDrawColor(renderer_, 0x00, 0xFF, 0xFF, 0);
	SDL_RenderFillRect(renderer_, &map);


	SDL_RenderPresent(renderer_);
}

void Game::color_keying_alpha()
{

}
