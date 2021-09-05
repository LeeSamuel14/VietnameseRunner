#pragma once
#include <SDL.h>
class Timer
{
	private:
		Uint32 start_ticks_;
		Uint32 paused_ticks_;
		bool started_;
		bool paused_;
	public:
		Timer();
		void start();
		void stop();
		void pause();
		void unpause();
		Uint32 get_ticks();
		bool is_started();
		bool is_paused();

};

