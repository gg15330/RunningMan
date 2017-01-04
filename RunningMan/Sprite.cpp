#include "Sprite.h"


Sprite::Sprite(SDL_Renderer* renderer, const char* filePath, int sourceX, int sourceY, int width, int height, int posX, int posY) :
	_frameIndex(0)
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

int Sprite::getFrameIndex()
{
	return _frameIndex;
}

SDL_Texture * Sprite::getSpriteSheet()
{
	return _spriteSheet;
}
