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

	/// <summary>
	/// Returns this <see cref="Player"/>'s _jumping property
	/// </summary>
	/// <returns></returns>
	bool getJumping() const noexcept;

	/// <summary>
	/// Set whether the <see cref="Player"/> is jumping
	/// </summary>
	/// <param name="jumping"></param>
	void setJumping(bool jumping);
private:
	bool _jumping;
};

#endif // !PLAYER_H
