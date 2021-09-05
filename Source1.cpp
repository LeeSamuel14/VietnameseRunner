#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <string>
#include <memory>

#include "SDL_image.h"
#include "Game.h"
const int SCREEN_WIDTH{ 640 };
const int SCREEN_HEIGHT{ 480 };
std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> gWindow{
                                                                    SDL_CreateWindow("Window name", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN),
                                                                    SDL_DestroyWindow
};
//SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Renderer* gRenderer = nullptr;
SDL_Texture* gTexture = nullptr;

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Surface* gCurrentSurface = NULL;

void print_error()
{
    printf("SDL_Error: %s\n", SDL_GetError());
}

bool init()
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        print_error();
        return false;
    }
    else
    {
        //gWindow = SDL_CreateWindow("Fire man!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            print_error();
            return false;
        }
        else
        {
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags))
            {
                print_error();
            }
            else
            {
                //Get window surface
                gScreenSurface = SDL_GetWindowSurface(gWindow.get());
            }
        }
    }

    return true;
}

SDL_Surface* loadMedia(std::string path)
{
    SDL_Surface* temp_image = nullptr;
    SDL_Surface* optimized_image = nullptr;
    temp_image = IMG_Load(path.c_str());
    if (temp_image == nullptr) { print_error(); }
    optimized_image = SDL_ConvertSurface(temp_image, gScreenSurface->format, 0);
    if (optimized_image == nullptr) { print_error(); }
    SDL_FreeSurface(temp_image);
    return optimized_image;
}

void load_all_media()
{
    std::string paths[]{ "fire-man.png", "1.png", "2.png", "3.png" };
    for (int i{ 0 }; i < 4; ++i)
    {
        gKeyPressSurfaces[i] = loadMedia(paths[i]);
    }
}

void scale_images()
{
    SDL_Rect screen_rect;
    screen_rect.x = 0;
    screen_rect.y = 0;
    screen_rect.w = SCREEN_WIDTH;
    screen_rect.h = SCREEN_HEIGHT;
    for (int i{ 0 }; i < 4; ++i)
    {
        SDL_BlitScaled(gKeyPressSurfaces[i], NULL, gScreenSurface, &screen_rect);
    }
}

void close()
{
    //SDL_FreeSurface(gHelloWorld);
    //gHelloWorld = NULL;
    //SDL_DestroyWindow(gWindow);
    //gWindow = NULL;
    SDL_Quit();
    //delete gKeyPressSurfaces;
}


int main(int argc, char* args[]) {
    init();
    bool quit{ false };
    SDL_Event e;
    load_all_media();
    scale_images();
    gCurrentSurface = gKeyPressSurfaces[0];

    SDL_Rect screen_rect;
    screen_rect.x = 0;
    screen_rect.y = 0;
    screen_rect.w = SCREEN_WIDTH;
    screen_rect.h = SCREEN_HEIGHT;

    while (!quit)
    {
        SDL_UpdateWindowSurface(gWindow.get());
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
                quit = true;
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_UP:
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                    SDL_BlitScaled(gKeyPressSurfaces[0], NULL, gScreenSurface, &screen_rect);
                    break;
                case SDLK_DOWN:
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                    SDL_BlitScaled(gKeyPressSurfaces[1], NULL, gScreenSurface, &screen_rect);
                    break;
                case SDLK_LEFT:
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                    SDL_BlitScaled(gKeyPressSurfaces[2], NULL, gScreenSurface, &screen_rect);
                    break;
                case SDLK_RIGHT:
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                    SDL_BlitScaled(gKeyPressSurfaces[3], NULL, gScreenSurface, &screen_rect);
                    break;

                }
            }
        }
    }
    close();
    return 0;
}