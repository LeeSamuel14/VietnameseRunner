#pragma once
#include <SDL.h>
#include <sstream>
class Time
{
private:
	Uint32 start_time;
public:
	Time();
	int get_time_text();
};

