#include "Sprite.h"


Sprite::Sprite()
{
}

Sprite::Sprite(SDL_Renderer* renderer, const char* filePath, int sourceX, int sourceY, int width, int height, int posX, int posY) :
	_texture{ loadTexture(filePath, renderer) },
	_sourceRect{ sourceX, sourceY, width, height },
	_destinationRect{ posX, posY, width, height },
	_x{ 0 },
	_y{ 0 }
{
}


Sprite::~Sprite()
{
}

void Sprite::update(int x, int y)
{
		updateDestRect(x, y);
}


SDL_Texture * Sprite::loadTexture(const char* filePath, SDL_Renderer* renderer)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL)
	{
		fprintf(stderr, "Could not load texture: %s\n", filePath);
	}

	return texture;
}

void Sprite::updateSourceRect(int x, int y)
{
	_sourceRect.x = x;
	_sourceRect.y = y;
}

void Sprite::updateDestRect(int x, int y)
{
	_destinationRect.x = x;
	_destinationRect.y = y;
}

SDL_Rect* Sprite::getSourceRect() noexcept
{
	return &_sourceRect;
}

SDL_Rect * Sprite::getDestinationRect() noexcept
{
	return &_destinationRect;
}

SDL_Texture * Sprite::getTexture() noexcept
{
	return _texture;
}
