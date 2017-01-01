#include "Sprite.h"


Sprite::Sprite(globals::Character character, int sourceX, int sourceY, int width, int height, int posX, int posY) :
	_character(character),
	_frameIndex(0)
{
	_sourceRect.x = sourceX;
	_sourceRect.y = sourceY;
	_sourceRect.w = width;
	_sourceRect.h = height;
}


Sprite::~Sprite()
{
}

void Sprite::update()
{
}

SDL_Rect* Sprite::getSourceRect()
{
	return &_sourceRect;
}

int Sprite::getFrameIndex()
{
	return _frameIndex;
}

globals::Character Sprite::getCharacter()
{
	return _character;
}
