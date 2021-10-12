#pragma once
namespace Engine {
	namespace Interfaces
	{
		class IPhysics
		{
		public:
			virtual void set_direction(double degree) = 0;
			virtual void set_speed(double speed) = 0;
			virtual void move(int x, int y) = 0;
			virtual void update() = 0;
		};
	}
	
}


