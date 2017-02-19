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

std::vector<Entity*> Level::entityCollisions(const Player* player) {
	std::vector<Entity*> others;
	for each (Entity* terrain in _terrains) 
	{
		if (collisionDetected(player, terrain)) 
		{
			std::cout << "Collision" << std::endl;
			others.push_back(terrain);
		}
	}
	return others;
}

std::vector<Entity*> Level::terrains() const noexcept
{
	return _terrains;
}

bool Level::collisionDetected(const Entity * entity1, const Entity * entity2)
{
	return !(entity2->x() > (entity1->x() + entity1->w())
		|| (entity2->x() + entity2->w())< entity1->x()
		|| entity2->y() > (entity1->y() + entity1->h())
		|| (entity2->y() + entity2->h()) < entity1->y()
		);
}
