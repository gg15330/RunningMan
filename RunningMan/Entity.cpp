#include "Entity.h"


Entity::Entity()
{
}

Entity::Entity(Sprite const & sprite) :
	_sprite	{ sprite }
{
	std::cout << "Creating Entity: " << this << std::endl;
}


Entity::~Entity()
{
}


Sprite * Entity::getSprite() noexcept
{
	return &_sprite;
}


SDL_Rect* Entity::getDestRect() noexcept
{
	return _sprite.getDestRect();
}