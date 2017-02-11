#pragma once

#ifndef LEVEL_H
#define LEVEL_H

#include "Terrain.h"
#include "Player.h"

#include <vector>

class Level
{
public:
	Level();
	Level(const Player& player);
	~Level();

	/// <summary>
	/// Updates this <see cref="Level"/>'s objects
	/// </summary>
	void update();

	/// <summary>
	/// Add a <see cref="Terrain"/> to the vector of Terrains
	/// </summary>
	/// <param name="terrain"></param>
	void addTerrain(Terrain* terrain);

	/// <summary>
	/// Checks if the supplied <see cref="SDL_Rect*"/> collides with any <see cref="Terrain"/> and returns the <see cref="Direction"/> of the collision
	/// </summary>
	/// <returns>The <see cref="Direction"/> of the collision, or NONE if no collision is found</returns>
	Direction collisionSide(const SDL_Rect* playerRect) const;
private:
	Player _player;
	std::vector<Terrain*> _terrains;
};

#endif // !LEVEL_H
