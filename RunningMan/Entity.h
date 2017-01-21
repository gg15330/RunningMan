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
	Entity(Sprite const & sprite, bool passable);
	~Entity();

	/// <summary>
	/// Returns this <see cref="Entity"/>'s <see cref="Sprite"/> object
	/// </summary>
	/// <returns></returns>
	Sprite* getSprite() noexcept;

	/// <summary>
	/// Returns this <see cref="Entity"/>'s destination <see cref="SDL_Rect"/> object
	/// </summary>
	/// <returns></returns>
	SDL_Rect* getDestRect() noexcept;

	void setSprite(Sprite const & sprite);

protected:
	Sprite _sprite;
	bool _passable;
	Vector2 _velocity;
};

#endif // !ENTITY_H
