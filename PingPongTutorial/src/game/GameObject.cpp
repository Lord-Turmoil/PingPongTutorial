#include "../../inc/game/GameObject.h"

GameObject::GameObject(double width, double height)
    : _width(width), _height(height)
{
}

GameObject* GameObject::SetCoordinate(const Coordinate& coord)
{
    _pos = coord;
    return this;
}

GameObject* GameObject::SetX(double x)
{
    _pos.x = x;
    return this;
}

GameObject* GameObject::SetY(double y)
{
    _pos.y = y;
    return this;
}

GameObject* GameObject::SetWidth(double width)
{
    _width = width;
    return this;
}

GameObject* GameObject::SetHeight(double height)
{
    _height = height;
    return this;
}

Rect GameObject::GetBorder() const
{
    return { _pos.x, _pos.y, _width, _height };
}
