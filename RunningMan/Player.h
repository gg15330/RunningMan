#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Sprite.h"
#include "Globals.h"

#include <SDL.h>


/// <summary>
/// 
/// </summary>
class Player : public Entity
{
public:
	Player();
	Player(Sprite& const sprite, int x, int y);
	Player(SDL_Renderer* renderer, const char* filePath, int sourceX, int sourceY, int width, int height, int posX, int posY);
	~Player();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="direction"></param>
	void move(Direction direction);
};

#endif // !PLAYER_H
