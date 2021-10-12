#include "GraphicsComponent.h"

Engine::GraphicsComponent::GraphicsComponent( std::string path)
{
	sprite_ = new Engine::Types::Graphics::Sprite(path);
}

void Engine::GraphicsComponent::update()
{
}
