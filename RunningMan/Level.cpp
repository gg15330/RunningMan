#include "Level.h"


Level::Level()
{
}

Level::Level(const Player * player)
{
	_player = player;
}


Level::~Level()
{
}

void Level::update()
{
}

void Level::addTerrain(Entity * terrain)
{
	_terrains.push_back(terrain);
}

std::vector<Entity*> Level::entityCollisions(Player* player) {
	std::vector<Entity*> others;
	for each (Entity* terrain in _terrains) 
	{
		if (player->collisionDetected(terrain)) 
		{
			others.push_back(terrain);
		}
	}
	return others;
}

std::vector<Entity*> Level::terrains() const noexcept
{
	return _terrains;
}

