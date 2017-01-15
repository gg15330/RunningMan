#include "Entity.h"

#include <string>

Entity::Entity()
{
}

Entity::Entity(Sprite & const sprite) :
	_sprite	{ sprite }
{
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

