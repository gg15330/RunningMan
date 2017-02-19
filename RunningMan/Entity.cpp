#include "Entity.h"


Entity::Entity()
{
}

Entity::Entity(SDL_Renderer* renderer, const char* const filePath, const float sourceX, const float sourceY, const int width, const int height, const float posX, const float posY) :
	_dx{ 0.0f },
	_dy{ 0.0f }
{
	std::cout << "Creating Entity: " << this << std::endl;
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

Entity::~Entity()
{
	std::cout << "Destroying Entity: " << this << std::endl;
}


void Entity::loadTexture(const char* filePath, SDL_Renderer* renderer)
{
	_texture = IMG_LoadTexture(renderer, filePath);
	if (_texture == NULL)
	{
		fprintf(stderr, "Could not load texture: %s\n", filePath);
	}
}

int Entity::roundToInt(const float f)
{
	return static_cast<int>(round(f));
}

void Entity::updateSourceRect(int x, int y)
{
	_sourceRect.x = x;
	_sourceRect.y = y;
}

void Entity::updateDestRect(Vector2 position)
{
	_destRect.x += roundToInt(position.x);
	_destRect.y += roundToInt(position.y);
}

SDL_Rect* Entity::getSourceRect() noexcept
{
	return &_sourceRect;
}

const SDL_Rect * Entity::getDestRect() const noexcept
{
	return &_destRect;
}

SDL_Texture * Entity::getTexture() noexcept
{
	return _texture;
}

Sprite * Entity::sprite() noexcept
{
	return &_sprite;
}

void Entity::setSprite(Sprite const & sprite)
{
	_sprite = sprite;
}

float Entity::x() const noexcept
{
	return _x;
}

float Entity::y() const noexcept
{
	return _y;
}

float Entity::w() const noexcept
{
	return _w;
}

float Entity::h() const noexcept
{
	return _h;
}

void Entity::setX(float x)
{
	_x = x;
}

void Entity::setY(float y)
{
	_y = y;
}