#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Globals.h"
#include "Entity.h"


/// <summary>
/// Class representing the player's character
/// </summary>
class Player : public Entity
{
public:
	Player();
	Player(Sprite const & sprite, bool passable);
	~Player();

	/// <summary>
	/// Change this <see cref="Player"/>'s coordinates
	/// </summary>
	/// <param name="direction"></param>
	void move(Direction direction);
};

#endif // !PLAYER_H
