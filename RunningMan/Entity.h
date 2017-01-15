#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "Sprite.h"

#include <SDL.h>

class Entity
{
public:
	Entity();
	Entity(Sprite& const sprite);
	Entity(SDL_Renderer* renderer, const char* filePath, int sourceX, int sourceY, int width, int height, int posX, int posY);
	virtual ~Entity();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Sprite* getSprite() noexcept;

protected:
	int _x, _y;
	Sprite _sprite;
};

#endif // !ENTITY_H
