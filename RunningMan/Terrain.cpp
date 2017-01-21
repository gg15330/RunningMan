#include "Terrain.h"


Terrain::Terrain()
{
}

Terrain::Terrain(Sprite const & sprite) :
	Entity{ sprite, false }
{
}

Terrain::~Terrain()
{
}
