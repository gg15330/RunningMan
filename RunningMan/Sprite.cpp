#include "Sprite.h"


Sprite::Sprite()
{
}

Sprite::Sprite(SDL_Renderer* renderer, const char* filePath, int sourceX, int sourceY, int width, int height, int posX, int posY) :
	_sourceRect		{ sourceX, sourceY, width, height },
	_destRect		{ posX, posY, width, height }
{
	loadTexture(filePath, renderer);
}


Sprite::~Sprite()
{
}


void Sprite::loadTexture(const char* filePath, SDL_Renderer* renderer)
{
	_texture = IMG_LoadTexture(renderer, filePath);
	if (_texture == NULL)
	{
		fprintf(stderr, "Could not load texture: %s\n", filePath);
	}
}

void Sprite::updateSourceRect(int x, int y)
{
	_sourceRect.x = x;
	_sourceRect.y = y;
}

void Sprite::updateDestRect(int x, int y)
{
	_destRect.x = x;
	_destRect.y = y;
}

SDL_Rect* Sprite::getSourceRect() noexcept
{
	return &_sourceRect;
}

SDL_Rect * Sprite::getDestRect() noexcept
{
	return &_destRect;
}

SDL_Texture * Sprite::getTexture() noexcept
{
	return _texture;
}
