#include "Sprite.h"


Sprite::Sprite()
{
}

Sprite::Sprite(SDL_Renderer* renderer, const char* const filePath, const float sourceX, const float sourceY, const int width, const int height, const float posX, const float posY)
{
	std::cout << "Creating Sprite: " << this << std::endl;
	_sourceRect = SDL_Rect 
	{ 
		roundToInt(sourceX), 
		roundToInt(sourceY), 
		width, 
		height 
	};
	_destRect = SDL_Rect
	{ 
		roundToInt(posX), 
		roundToInt(posY), 
		width, 
		height 
	};
	loadTexture(filePath, renderer);
}


Sprite::~Sprite()
{
	std::cout << "Destroying Sprite: " << this << std::endl;
}


void Sprite::loadTexture(const char* filePath, SDL_Renderer* renderer)
{
	_texture = IMG_LoadTexture(renderer, filePath);
	if (_texture == NULL)
	{
		fprintf(stderr, "Could not load texture: %s\n", filePath);
	}
}

int Sprite::roundToInt(const float f)
{
	return static_cast<int>(round(f));
}

void Sprite::updateSourceRect(int x, int y)
{
	_sourceRect.x = x;
	_sourceRect.y = y;
}

void Sprite::updateDestRect(Vector2 position)
{
	_destRect.x += roundToInt(position.x);
	_destRect.y += roundToInt(position.y);
}

SDL_Rect* Sprite::getSourceRect() noexcept
{
	return &_sourceRect;
}

const SDL_Rect * Sprite::getDestRect() const noexcept
{
	return &_destRect;
}

SDL_Texture * Sprite::getTexture() noexcept
{
	return _texture;
}
