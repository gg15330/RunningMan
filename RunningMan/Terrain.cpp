#include "Terrain.h"


Terrain::Terrain()
{
}

Terrain::Terrain(Sprite const & sprite) :
	Entity		{ sprite },
	_passable	{ false }
{
}


Terrain::~Terrain()
{
}
