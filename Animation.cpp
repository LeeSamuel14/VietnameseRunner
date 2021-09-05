#include "Animation.h"

Animation::Animation(SDL_Renderer* renderer, int frames, int frame_width, int frame_height, std::string path)
{
	renderer_ = renderer;
	current_frame_ = 0;
	frame_total_count_ = frames;
	frame_width_ = frame_width;
	frame_height_ = frame_height;
	for (int i { 0 }; i < frames; ++i)
	{
		SDL_Rect frame_rect{ i * frame_width, 0, frame_width, frame_height };
		frames_[i] = frame_rect;
	}
	load_from_file(path);

}

bool Animation::load_from_file(std::string path)
{
	SDL_Surface* temp_surface{ IMG_Load(path.c_str()) };
	if (!temp_surface) { Utilities::print_error(); }
	sprite_sheet_ = SDL_CreateTextureFromSurface(renderer_, temp_surface);
	if (!sprite_sheet_) { Utilities::print_error(); }
	SDL_FreeSurface(temp_surface);
	return true;
}

void Animation::render(int x, int y)
{

	SDL_Rect frame_position = frames_[current_frame_/ frame_total_count_];
	SDL_Rect render_position = { x, y, frame_width_, frame_height_ }; //100 needs to passed in as a paramter. As this this is relative to the window
	SDL_RenderCopy(renderer_, sprite_sheet_, &frame_position, &render_position);
	current_frame_++;
	if (current_frame_ / frame_total_count_ >= frame_total_count_)
	{
		current_frame_ = 0;
	}
}
