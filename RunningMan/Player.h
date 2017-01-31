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
	void updatePos();

	/// <summary>
	/// Get this <see cref="Player"/>'s velocity
	/// </summary>
	/// <returns></returns>
	Vector2 velocity() const noexcept;

	/// <summary>
	/// Set this <see cref="Player"/>'s velocity
	/// </summary>
	void updateVel(const Vector2 acceleration);

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
	Vector2 _velocity;
};

#endif // !PLAYER_H
