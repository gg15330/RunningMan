#include "Sprite.h"


Sprite::Sprite(globals::Character character, char* filePath, int sourceX, int sourceY, int width, int height, int posX, int posY) :
	_character(character),
	_filePath(filePath),
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

char * Sprite::getFilePath()
{
	return _filePath;
}
