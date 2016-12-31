#include "Sprite.h"

#include <iostream>

Sprite::Sprite()
{
}

Sprite::Sprite(globals::Character character, char* filePath, int sourceX, int sourceY, int width, int height, int posX, int posY) :
	_character(character),
	_filePath(filePath),
	_frame(0)
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

SDL_Texture * Sprite::getSpriteSheet()
{
	return _spriteSheet;
}

int Sprite::getFrame()
{
	return _frame;
}

globals::Character Sprite::getCharacter()
{
	return _character;
}

char * Sprite::getFilePath()
{
	return _filePath;
}
