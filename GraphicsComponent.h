#pragma once
#include "Renderer.h"
#include "IGraphics.h"
namespace Engine
{
	class GraphicsComponent : IGraphics
	{
		private:
			//Engine::Renderer* renderer_ = Engine::Engine::renderer;
		public:
			virtual void render() override;
	};
}

