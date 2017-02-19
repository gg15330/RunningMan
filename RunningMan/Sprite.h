#pragma once

#ifndef SPRITE_H
#define SPRITE_H

#include "Globals.h"

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>


/// <summary>
/// Holds spritesheet and source/destination rectangles
/// </summary>
class Sprite
{
public:
	Sprite();
	Sprite(SDL_Renderer* renderer,
		const char* const filePath,
		const float sourceX, 
		const float sourceY,
		const int width,
		const int height,
		const float posX,
		const float posY);
	virtual ~Sprite();

private:

};

#endif // !SPRITE_H
