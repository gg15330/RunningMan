#include "Entity.h"


Entity::Entity()
{
}

Entity::Entity(Sprite & const sprite) :
	_sprite(sprite)
{
}

Entity::Entity(SDL_Renderer * renderer, const char * filePath, int sourceX, int sourceY, int width, int height, int posX, int posY) :
	_sprite(renderer, filePath, sourceX, sourceY, width, height, posX, posY)
{
}

Entity::~Entity()
{
}


Sprite * Entity::getSprite() noexcept
{
	return &_sprite;
}


