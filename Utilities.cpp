#include "Utilities.h"

void Utilities::print_error()
{
	std::cerr << SDL_GetError();
	throw std::string{ "\nSDL Error. " };
}