#include "Sound.h"

Sound::Sound(std::string path, bool is_chunk)
{
	if (is_chunk)
	{
		chunk_ = Mix_LoadWAV(path.c_str());
		if (!chunk_) { Utilities::print_error(); }
	}
	else
	{
		music_ = Mix_LoadMUS(path.c_str());
		if (!music_) { Utilities::print_error(); }

	}
}

Sound::~Sound()
{
	if (chunk_)
		Mix_FreeChunk(chunk_);
	if (music_)
		Mix_FreeMusic(music_);
	chunk_ = nullptr;
	music_ = nullptr;
}

void Sound::play(int loop)
{
	if (chunk_)
		Mix_PlayChannel(-1, chunk_, loop);
	if (music_)
		Mix_PlayMusic(music_, loop);
}
