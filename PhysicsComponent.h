#pragma once
#include "IPhysics.h"
#include "Velocity.h"
namespace Engine
{
	class PhysicsComponent : IPhysics
	{
		private:
			Engine::PhysicsType::Velocity velocity_;
		public:
			  void set_degree(double degree) override;

	};
}

