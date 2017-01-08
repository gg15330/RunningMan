#include "Sprite.h"

#include <iostream>

Sprite::Sprite(SDL_Renderer* renderer, const char* filePath, int sourceX, int sourceY, int width, int height, int posX, int posY)
{
	_spriteSheet = IMG_LoadTexture(renderer, filePath);
	_sourceRect.x = sourceX;
	_sourceRect.y = sourceY;
	_sourceRect.w = width;
	_sourceRect.h = height;
	_destinationRect.w = width; 
	_destinationRect.h = height;
	_destinationRect.x = posX;
	_destinationRect.y = posY;
}


Sprite::~Sprite()
{
}


SDL_Texture * Sprite::loadTexture(char * filePath, SDL_Renderer* renderer)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL)
	{
		fprintf(stderr, "Could not load texture: %s\n", filePath);
	}

	return texture;
}

void Sprite::updatePos(int x, int y)
{
}

SDL_Rect* Sprite::getSourceRect()
{
	return &_sourceRect;
}

SDL_Rect * Sprite::getDestinationRect()
{
	return &_destinationRect;
}

SDL_Texture * Sprite::getSpriteSheet()
{
	return _spriteSheet;
}
