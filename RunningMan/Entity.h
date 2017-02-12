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
	/// Setter for this <see cref="Entity"/>'s Sprite
	/// </summary>
	/// <param name="sprite"></param>
	void setSprite(Sprite const & sprite);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Vector2 position();

	void setPosition(float x, float y);

protected:
	Sprite _sprite;
	bool _passable;
	float _x, _y, _dx, _dy;
};

#endif // !ENTITY_H
