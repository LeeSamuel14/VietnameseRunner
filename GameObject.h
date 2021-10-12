#pragma once
#include "Point.h"
#include "MessageType.h"
#include "PhysicsComponent.h"
#include "GraphicsComponent.h"
namespace Engine
{
	class GameObject
	{
	protected:
		Engine::Point point;

	public:
		GameObject();
		GameObject(int x, int y);
		Engine::Point get_point();
		void set_point(int x, int y);
		virtual void receive(Engine::Enums::MessageType message) = 0;

	};

}

