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
	float x() const noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	float y() const noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	float w() const noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	float h() const noexcept;
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="x"></param>
	void setX(float x);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="y"></param>
	void setY(float y);

protected:
	Sprite _sprite;
	bool _passable;
	float _x, _y, _w, _h, _dx, _dy;
};

#endif // !ENTITY_H
