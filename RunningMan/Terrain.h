#pragma once

#ifndef TERRAIN_H
#define TERRAIN_H

#include "Entity.h"


/// <summary>
/// Terrain (non-passable, stationary Entity)
/// </summary>
class Terrain : public Entity
{
public:
	Terrain(Sprite const &sprite);
	~Terrain();

private:
	bool _passable;
};

#endif // !TERRAIN_H
