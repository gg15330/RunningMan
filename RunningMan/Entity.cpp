#include "Entity.h"

#include <string>

Entity::Entity()
{
}

Entity::Entity(Sprite & const sprite, int x, int y) :
	_sprite	(sprite),
	_x		{ x },
	_y		{ y }
{
}

Entity::Entity(SDL_Renderer * renderer, const char * filePath, int sourceX, int sourceY, int width, int height, int posX, int posY) :
	_sprite	{ renderer, filePath, sourceX, sourceY, width, height, posX, posY },
	_x		{ posX },
	_y		{ posY }
{
}

Entity::~Entity()
{
}


Sprite * Entity::getSprite() noexcept
{
	return &_sprite;
}

std::string Entity::getCoords()
{
	std::string s;
	s.append(std::to_string(_x));
	s.append(", ");
	s.append(std::to_string(_y));
	s.append("\n");
	return s;
}

