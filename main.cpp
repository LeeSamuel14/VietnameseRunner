#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <string>

#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Game.h"
#include "IGraphics.h"

void init_SDL()
{
    int is_init_SDL { SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) };
    int image_support = IMG_INIT_JPG | IMG_INIT_PNG;
    int is_init_image = IMG_Init(image_support);
    int is_TTF_init = TTF_Init();
    int is_mixer_int = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    if (is_init_SDL < 0)
    {
        std::cout << SDL_GetError();
        throw std::string { "Could not INIT SDL" };
    }

    if (is_init_image && image_support != image_support)
    {
        std::cout << IMG_GetError();
        throw std::string { "Could not INIT SDL IMAGE" };
    }

    if (is_TTF_init  == -1)
    {
        std::cout << TTF_GetError();
        throw std::string { "Could not INIT SDL TTF FONT" };
    }

    if (is_mixer_int  < 0)
    {
        std::cout << Mix_GetError();
        throw std::string{ "Could not INIT SDL MIXER SOUND" } ;
    }
    
}

void close_SDL()
{
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}


int main(int argc, char* args[]) {
    try
    {
        //std::cout << Engine::IGraphics::t;
        init_SDL();
        Game game{ };
        //game->init_game_loop();
        close_SDL();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    catch (const std::string& e)
    {
        std::cout << e << "\n";
    }
	return 0;
}