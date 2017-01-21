#include "Entity.h"


Entity::Entity()
{
	std::cout << "Creating Entity: " << this << std::endl;
}

Entity::Entity(Sprite const & sprite, bool passable = false) :
	_sprite		{ sprite },
	_passable	{ passable }
{
	Entity{};
}


Entity::~Entity()
{
	std::cout << "Destroying Entity: " << this << std::endl;
}


Sprite * Entity::getSprite() noexcept
{
	return &_sprite;
}


SDL_Rect* Entity::getDestRect() noexcept
{
	return _sprite.getDestRect();
}

void Entity::setSprite(Sprite const & sprite)
{
	_sprite = sprite;
}
