#include "GraphicsComponent.h"

Engine::GraphicsComponent::GraphicsComponent( std::string path)
	//:	game_object_{ game_object }
{
	sprite_ = new Engine::Types::Graphics::Sprite(path);
}

void Engine::GraphicsComponent::update()
{
	//SDL_RenderClear(Engine::Renderer::renderer);
	//SDL_Rect render_position{ game_object_->get_point().x, game_object_->get_point().y, sprite_->width_, sprite_->height_ };
	//SDL_RenderCopy(Engine::Renderer::renderer, sprite_->texture_, nullptr, &render_position);
	//SDL_RenderPresent(Engine::Renderer::renderer);
}
