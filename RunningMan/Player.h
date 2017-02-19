#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Globals.h"
#include "Entity.h"
#include "Terrain.h"

#include <algorithm>
#include <vector>

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
	bool grounded() noexcept;

	/// <summary>
	/// Set whether the <see cref="Player"/> is jumping
	/// </summary>
	/// <param name="grounded"></param>
	void setGrounded(bool grounded);

	/// <summary>
	/// 
	/// </summary>
	void handleTileCollisions(std::vector<Entity*> others);

private:
	float _prevX, _prevY;
	bool _grounded;

	/// <summary>
	/// Checks if the supplied <see cref="SDL_Rect*"/> collides with any <see cref="Terrain"/> and returns the <see cref="Direction"/> of the collision
	/// </summary>
	/// <returns>The <see cref="Direction"/> of the collision, or NONE if no collision is found</returns>
	Direction collisionSide(Entity* rect) const;
};

#endif // !PLAYER_H
