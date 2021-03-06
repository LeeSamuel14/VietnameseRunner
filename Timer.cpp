#include "Timer.h"

Timer::Timer()
	:	start_ticks_ { 0 }, 
		paused_ticks_ { 0 },
		started_ { false },
		paused_ { false }
{
}

void Timer::start()
{
	started_ = true;
	paused_ = false;
	start_ticks_ = SDL_GetTicks();
	paused_ticks_ = 0;
}

void Timer::stop()
{
	started_ = false;
	paused_ = false;
	start_ticks_ = 0;
	paused_ticks_ = 0;
}

void Timer::pause()
{
	if (started_ && !paused_)
	{
		paused_ = true;
		paused_ticks_ = SDL_GetTicks() - start_ticks_;
		start_ticks_ = 0;
	}
}

void Timer::unpause()
{
	if (paused_ && started_)
	{
		paused_ = false;

		start_ticks_ = SDL_GetTicks() - paused_ticks_;
		paused_ticks_ = 0;
	}
}

Uint32 Timer::get_ticks()
{
	Uint32 time { 0 };

	if (started_)
		time = paused_ ? paused_ticks_ : (SDL_GetTicks() - start_ticks_);

	return time;

}

bool Timer::is_started()
{
	return started_;
}

bool Timer::is_paused()
{
	return paused_ && is_started();
}
