#include "Level.h"


Level::Level()
{
}

Level::Level(const Player & player)
{
	_player = player;
}


Level::~Level()
{
}

void Level::update()
{
}

void Level::addTerrain(Terrain * terrain)
{
	_terrains.push_back(terrain);
}

Direction Level::collisionDetected(Player* player)
{
	SDL_Rect playerRect = *player->sprite()->getDestRect();
	SDL_Rect rect2;
	for (Terrain* terrain : _terrains)
	{
		rect2 = *terrain->sprite()->getDestRect();
		float w = 0.5 * (playerRect.w + rect2.w);
		float h = 0.5 * (playerRect.h + rect2.h);
		float dx = (playerRect.x + (playerRect.w / 2.0f)) - (rect2.x + (rect2.w / 2.0f));
		float dy = (playerRect.y + (playerRect.h / 2.0f)) - (rect2.y + (rect2.h / 2.0f));

		if (abs(dx) <= w && abs(dy) <= h)
		{
			float wy = w * dy;
			float hx = h * dx;

			if (wy > hx)
			{
				if (wy > -hx)
				{
					std::cout << "UP" << std::endl;
					return UP;
				}
				else
				{
					std::cout << "LEFT" << std::endl;
					return LEFT;
				}
			}
			else
			{
				if (wy > -hx)
				{
					std::cout << "RIGHT" << std::endl;
					return RIGHT;
				}
				else
				{
					std::cout << "DOWN" << std::endl;
					return DOWN;
				}
			}
		}
	}
	return NONE;
}
