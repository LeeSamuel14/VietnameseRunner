#include "Time.h"

Time::Time()
{
	start_time = 0;
}

int Time::get_time_text()
{
	return (SDL_GetTicks() - start_time);
}
