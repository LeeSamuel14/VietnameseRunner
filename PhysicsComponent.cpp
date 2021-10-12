#include "PhysicsComponent.h"

//void Engine::PhysicsComponent::is_overlapping()
//{
//	auto rect = other_physics_object_->get_collision_box();
//	SDL_HasIntersection(collision_box_, rect);
//	bool is_overlap = SDL_HasIntersection(collision_box_, rect);
//	if (is_overlap)
//		game_object_->receive(Engine::Enums::MessageType::COLLISION_DETECTED);
//}
//
//Engine::PhysicsComponent::PhysicsComponent(Engine::GameObject* game_object)
//	:	game_object_ { game_object}, 
//		collision_active_ { false }
//{
//	//collion_box_ = SDL_Rect()
//	destination_point = new Engine::Point;
//	
//}
//
//void Engine::PhysicsComponent::set_direction(double degree)
//{
//}
//
//void Engine::PhysicsComponent::set_speed(double speed)
//{
//}
//
//void Engine::PhysicsComponent::move(int x, int y)
//{
//	destination_point->x = x;
//	destination_point->y = y; 
//
//}
//
//void Engine::PhysicsComponent::update()
//{
//	int current_x = game_object_->get_point().x;
//	int current_y = game_object_->get_point().y;
//
//	int destination_x = destination_point->x;
//	int destination_y = destination_point->y;
//
//	if (destination_x < current_x) {
//		game_object_->set_point(--current_x, current_y);
//	}
//	else if (destination_x > current_x) {
//		game_object_->set_point(++current_x, current_y);
//	}
//
//	if (destination_y < current_y) {
//		game_object_->set_point(current_x, --current_y);
//	}
//	else if (destination_y > current_y) {
//		game_object_->set_point(current_x, ++current_y);
//	}
//
//	check_collision();
//}
//
//void Engine::PhysicsComponent::init_collison(int width, int height, PhysicsComponent*  other_physics_object)
//{
//	collision_active_ = true;
//
//	other_physics_object_ = other_physics_object;
//
//	SDL_Rect collision_box;
//	collision_box.x = game_object_->get_point().x;
//	collision_box.y = game_object_->get_point().y;
//	collision_box.w = width;
//	collision_box.h = height;
//
//	collision_box_ = &collision_box;
//}
//
//void Engine::PhysicsComponent::check_collision()
//{
//	
//	if (collision_active_)
//	{
//		if (other_physics_object_->get_collision_active())
//		{
//			is_overlapping();
//		}
//
//	}
//}
//
//
//
//
