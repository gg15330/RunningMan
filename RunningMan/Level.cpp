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

Direction Level::collisionSide(const SDL_Rect* playerRect) const
{
	SDL_Rect terrainRect;
	float wy, hx;
	for (Terrain* terrain : _terrains)
	{
		terrainRect = *terrain->sprite()->getDestRect();
		if (SDL_HasIntersection(playerRect, &terrainRect))
		{
			wy = (0.5f * (playerRect->w + terrainRect.w)) * ((playerRect->y + (0.5f * playerRect->h)) - (terrainRect.y + (0.5f * terrainRect.h)));
			hx = (0.5f * (playerRect->h + terrainRect.h)) * ((playerRect->x + (0.5f * playerRect->w)) - (terrainRect.x + (0.5f * terrainRect.w)));
			return (wy > hx) ? ((wy > -hx) ? UP : LEFT) : ((wy > -hx) ? RIGHT : DOWN);
		}
	}
	return NONE;
}
