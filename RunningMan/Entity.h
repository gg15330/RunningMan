#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "Sprite.h"
#include "Globals.h"

#include <SDL.h>

class Entity
{
public:
	Entity();
	Entity(Sprite& const sprite);
	virtual ~Entity();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Sprite* getSprite() noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	SDL_Rect* getDestRect() noexcept;
protected:
	Sprite _sprite;
};

#endif // !ENTITY_H
