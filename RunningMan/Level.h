#pragma once

#ifndef LEVEL_H
#define LEVEL_H

#include "Player.h"

#include <vector>

class Level
{
public:
	Level();
	Level(const Player* player);
	~Level();

	/// <summary>
	/// Updates this <see cref="Level"/>'s objects
	/// </summary>
	void update();

	/// <summary>
	/// Add a <see cref="Terrain"/> to the vector of Terrains
	/// </summary>
	/// <param name="terrain"></param>
	void addTerrain(Entity* terrain);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	std::vector<Entity*> entityCollisions(Player* player);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	std::vector<Entity*> terrains() const noexcept;

private:
	const Player* _player;
	std::vector<Entity*> _terrains;
};

#endif // !LEVEL_H
