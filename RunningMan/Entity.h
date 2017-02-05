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
	Sprite* sprite() noexcept;

	/// <summary>
	/// Returns this <see cref="Entity"/>'s destination <see cref="SDL_Rect"/> object
	/// </summary>
	/// <returns></returns>
	SDL_Rect* getDestRect() noexcept;

	/// <summary>
	/// Getter for this <see cref="Entity"/>'s velocity
	/// </summary>
	/// <param name="velocity"></param>
	/// <returns></returns>
	Vector2 getVelocity() const noexcept;

	/// <summary>
	/// Setter for this <see cref="Entity"/>'s velocity
	/// </summary>
	/// <param name="velocity"></param>
	void setVelocity(Vector2 velocity);
	
	/// <summary>
	/// Setter for this <see cref="Entity"/>'s Sprite
	/// </summary>
	/// <param name="sprite"></param>
	void setSprite(Sprite const & sprite);

protected:
	Sprite _sprite;
	bool _passable;
	Vector2 _velocity;
};

#endif // !ENTITY_H
