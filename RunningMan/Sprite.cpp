#include "Sprite.h"


Sprite::Sprite(Character character, int sourceX, int sourceY, int width, int height, int posX, int posY) :
	_character(character),
	_frameIndex(0),
	_x(posX),
	_y(posY)
{
	_sourceRect.x = sourceX;
	_sourceRect.y = sourceY;
	_sourceRect.w = width;
	_sourceRect.h = height;
}


Sprite::~Sprite()
{
}

void Sprite::update(SDL_Rect rect)
{
	_x = rect.x;
	_y = rect.y;
}

SDL_Rect* Sprite::getSourceRect()
{
	return &_sourceRect;
}

int Sprite::getFrameIndex()
{
	return _frameIndex;
}

Character Sprite::getCharacter()
{
	return _character;
}

int Sprite::getX()
{
	return _x;
}

int Sprite::getY()
{
	return _y;
}
