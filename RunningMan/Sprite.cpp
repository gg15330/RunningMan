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
	std::cout << "PLAYER: " << character << "\n";
	std::cout << "FILEPATH: " << filePath << "\n";

	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;
}


Sprite::~Sprite()
{
}

void Sprite::update()
{
}

SDL_Rect* Sprite::getSourceRect()
{
	return &this->_sourceRect;
}

SDL_Texture * Sprite::getSpriteSheet()
{
	return this->_spriteSheet;
}

int Sprite::getFrame()
{
	return this->_frame;
}

globals::Character Sprite::getCharacter()
{
	return _character;
}

char * Sprite::getFilePath()
{
	return this->_filePath;
}
