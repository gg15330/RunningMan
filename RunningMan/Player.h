#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

#include <SDL.h>

class Player
{
public:
	Player(SDL_Renderer* renderer,
		const char* filePath,
		int sourceX,
		int sourceY,
		int width,
		int height,
		int posX,
		int posY);
	~Player();

	/// <summary>
	/// Updates the spritesheet
	/// </summary>
	virtual void updatePos(int x, int y);

	Sprite* getSprite();

private:
	Sprite _sprite;

};

#endif // !PLAYER_H
