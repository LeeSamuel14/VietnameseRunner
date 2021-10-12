#pragma once
#include <SDL.h>
#include <iostream>
#include "IPhysics.h"
#include "Velocity.h"
#include "GameObject.h"
#include "Point.h"
namespace Engine
{
	class PhysicsComponent //: Interfaces::IPhysics
	{
		/*private:
			Engine::Types::Physics::Velocity velocity_;
			Engine::GameObject* game_object_;
			Engine::Point* destination_point;
			SDL_Rect* collision_box_;
			bool collision_active_;
			PhysicsComponent* other_physics_object_;
			void is_overlapping();
		public:
			PhysicsComponent(Engine::GameObject* game_object);
			void set_direction(double degree) override;
			void set_speed(double speed) override;
			void move(int x, int y) override;
			void update() override;
			void init_collison(int width, int height, PhysicsComponent*  other_physics_object);
			void check_collision();
			SDL_Rect* get_collision_box() { return collision_box_; };
			bool get_collision_active() { return collision_active_; };*/

	};
}

