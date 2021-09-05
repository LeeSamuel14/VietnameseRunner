#pragma once
namespace Engine {
	class IPhysics
	{
		public:
			virtual void set_degree(double degree) = 0;
			virtual void set_speed(double speed) = 0;
			virtual void move() = 0;
	};
}


