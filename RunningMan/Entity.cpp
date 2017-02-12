#include "Entity.h"


Entity::Entity()
{
	std::cout << "Creating Entity: " << this << std::endl;
}

Entity::Entity(Sprite const & sprite, bool passable = false) :
	_sprite		{ sprite },
	_passable	{ passable },
	_velocity	{ 0, 0 }
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

Vector2 Entity::getVelocity() const noexcept
{
	return _velocity;
}

void Entity::setVelocity(Vector2 velocity)
{
	_velocity = velocity;
}

void Entity::setSprite(Sprite const & sprite)
{
	_sprite = sprite;
}
