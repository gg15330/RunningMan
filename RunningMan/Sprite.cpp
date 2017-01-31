#include "Sprite.h"


Sprite::Sprite()
{
}

Sprite::Sprite(SDL_Renderer* renderer, const char* const filePath, const float sourceX, const float sourceY, const int width, const int height, const float posX, const float posY)
{
	std::cout << "Creating Sprite: " << this << std::endl;
	_sourceRect = SDL_Rect 
	{ 
		static_cast<int>(sourceX), 
		static_cast<int>(sourceY), 
		width, 
		height 
	};
	_destRect = SDL_Rect 
	{ 
		static_cast<int>(posX), 
		static_cast<int>(posY), 
		width, 
		height 
	};
	loadTexture(filePath, renderer);
}


Sprite::~Sprite()
{
	std::cout << "Destroying sprite: " << this << std::endl;
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
