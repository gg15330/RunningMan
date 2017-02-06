#pragma once

#ifndef LEVEL_H
#define LEVEL_H

#include "Terrain.h"

#include <vector>

class Level
{
public:
	Level();
	~Level();

private:
	std::vector<Terrain> _terrains;
};

#endif // !LEVEL_H
