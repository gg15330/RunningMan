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

Vector2 Entity::position()
{
	return Vector2{ _x, _y };
}
