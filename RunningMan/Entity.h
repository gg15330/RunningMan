#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "Globals.h"
#include "Sprite.h"

#include <SDL.h>


/// <summary>
/// Abstract class representing a game entity
/// </summary>
class Entity
{
public:
	Entity();
	Entity(Sprite const & sprite);
	virtual ~Entity() = 0;

	/// <summary>
	/// Returns this <see cref="Entity"/>'s <see cref="Sprite"/> object
	/// </summary>
	/// <returns></returns>
	virtual Sprite* getSprite() noexcept;

	/// <summary>
	/// Returns this <see cref="Entity"/>'s destination <see cref="SDL_Rect"/> object
	/// </summary>
	/// <returns></returns>
	virtual SDL_Rect* getDestRect() noexcept;

	/// <summary>
	/// Change this <see cref="Entity"/>'s coordinates
	/// </summary>
	/// <param name="direction">The <see cref="Direction"/> to move</param>
	virtual void move(Direction direction) = 0;

protected:
	Sprite _sprite;
};

#endif // !ENTITY_H
