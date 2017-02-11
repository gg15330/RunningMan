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
	/// 
	/// </summary>
	/// <returns></returns>
	Direction collisionDetected(Player* player);
private:
	Player _player;
	std::vector<Terrain*> _terrains;
};

#endif // !LEVEL_H
