#include "Entity.h"


Entity::Entity()
{
	std::cout << "Creating Entity: " << this << std::endl;
}

Entity::Entity(Sprite const & sprite, bool passable = false) :
	_sprite		{ sprite },
	_passable	{ passable },
	_dx			{ 0.0f },
	_dy			{ 0.0f }
{
	Entity{};
}


Entity::~Entity()
{
	std::cout << "Destroying Entity: " << this << std::endl;
}


Sprite * Entity::sprite() noexcept
{
	return &_sprite;
}

void Entity::setSprite(Sprite const & sprite)
{
	_sprite = sprite;
}

float Entity::x() const noexcept
{
	return _x;
}

float Entity::y() const noexcept
{
	return _y;
}

float Entity::w() const noexcept
{
	return _w;
}

float Entity::h() const noexcept
{
	return _h;
}

void Entity::setX(float x)
{
	_x = x;
}

void Entity::setY(float y)
{
	_y = y;
}