#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Globals.h"
#include "Entity.h"

#include <algorithm>

#define NOMINMAX


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
	/// Moves this <see cref="Player"/> in a given <see cref="Direction"/>
	/// </summary>
	/// <param name="direction"></param>
	void move(Direction direction);

	/// <summary>
	/// Change this <see cref="Player"/>'s coordinates
	/// </summary>
	/// <param name="timeElapsed"></param>
	void update(int timeElapsed);

	/// <summary>
	/// Stops this <see cref="Player"/> moving left or right
	/// </summary>
	void stop();

	/// <summary>
	/// Returns this <see cref="Player"/>'s _jumping property
	/// </summary>
	/// <returns></returns>
	bool grounded() const noexcept;

	/// <summary>
	/// Set whether the <see cref="Player"/> is jumping
	/// </summary>
	/// <param name="jumping"></param>
	void setGrounded(bool jumping);

private:
	bool _grounded;
};

#endif // !PLAYER_H
