#pragma once
#include <SDL_mixer.h>
#include <string>
#include "Utilities.h"

class Sound
{
private:
	Mix_Chunk* chunk_;
	Mix_Music* music_;
public:
	Sound(std::string path, bool chunk = false);
	~Sound();
	void play(int loop = 0);
};

