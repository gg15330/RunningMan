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
	/// Get this <see cref="Player"/>'s position
	/// </summary>
	/// <returns></returns>
	Vector2 position() const noexcept;
	
	/// <summary>
	/// Get this <see cref="Player"/>'s velocity
	/// </summary>
	/// <returns></returns>
	Vector2 velocity() const noexcept;

	/// <summary>
	/// Set this <see cref="Player"/>'s velocity
	/// </summary>
	void accelerate(const Vector2& acceleration);

	/// <summary>
	/// Stops this <see cref="Player"/> moving left or right
	/// </summary>
	void stop();

	/// <summary>
	/// Returns this <see cref="Player"/>'s _jumping property
	/// </summary>
	/// <returns></returns>
	bool jumping() const noexcept;

	/// <summary>
	/// Set whether the <see cref="Player"/> is jumping
	/// </summary>
	/// <param name="jumping"></param>
	void setJumping(bool jumping);

private:
	bool _jumping;
	Vector2 _position, _velocity;
};

#endif // !PLAYER_H
