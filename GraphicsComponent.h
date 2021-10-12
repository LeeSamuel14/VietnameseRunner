#pragma once
#include "Renderer.h"
#include "IGraphics.h"
#include "Sprite.h"
#include "GameObject.h"
#include <string>

namespace Engine
{
	class GraphicsComponent : Interfaces::IGraphics
	{
		private:
			//Engine::GameObject* game_object_;
			Engine::Types::Graphics::Sprite* sprite_;

		public:
			GraphicsComponent(std::string path);
			virtual void update() override;
			Engine::Types::Graphics::Sprite* get_sprite() { return sprite_; };

	};
}

