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
	std::vector<Entity*> entityCollisions(const Player* player);

	std::vector<Entity*> terrains() const noexcept;
private:
	const Player* _player;
	std::vector<Entity*> _terrains;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="entity1"></param>
	/// <param name="entity2"></param>
	/// <returns></returns>
	bool collisionDetected(const Entity* entity1, const Entity* entity2);
};

#endif // !LEVEL_H
