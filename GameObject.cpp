#include "GameObject.h"


Engine::GameObject::GameObject()
    : point {}
{

}

Engine::GameObject::GameObject(int x, int y)
{
    set_point(x, y);
}

Engine::Point Engine::GameObject::get_point()
{
    return point;
}

void Engine::GameObject::set_point(int x, int y)
{
    point.x = x;
    point.y = y;
}

