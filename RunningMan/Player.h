#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Sprite.h"
#include "Globals.h"

#include <SDL.h>

#include <string>


/// <summary>
/// 
/// </summary>
class Player : public Entity
{
public:
	Player();
	Player(Sprite& const sprite);
	~Player();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="direction"></param>
	void move(Direction direction);
};

#endif // !PLAYER_H
