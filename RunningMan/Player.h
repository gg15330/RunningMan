#pragma once

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

	Sprite* getSprite();

private:
	Sprite _sprite;

};

