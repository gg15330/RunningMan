#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"
#include "Globals.h"

#include <SDL.h>


/// <summary>
/// 
/// </summary>
class Player : public Sprite
{
public:
	Player();
	Player(SDL_Renderer* renderer, const char* filePath, int sourceX, int sourceY, int width, int height, int posX, int posY);
	~Player();

	/// <summary>
	/// Updates the spritesheet
	/// </summary>
	virtual void updatePos(int x, int y);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="direction"></param>
	void move(Direction direction);
};

#endif // !PLAYER_H
