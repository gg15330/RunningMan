#pragma once

#ifndef SPRITE_H
#define SPRITE_H

#include "Globals.h"

#include <SDL.h>


class Sprite
{
public:
	Sprite(globals::Character character,
		int sourceX, 
		int sourceY, 
		int width, 
		int height, 
		int posX, 
		int posY);
	virtual ~Sprite();

	/// <summary>
	/// Updates the spritesheet
	/// </summary>
	virtual void update();

	/// <summary>
	/// Get the sprite's current SDL_Rect
	/// </summary>
	/// <returns>A pointer to the sprite's current SDL_Rect</returns>
	SDL_Rect* getSourceRect();

	/// <summary>
	/// Returns the Sprite's frame index
	/// </summary>
	/// <returns>The frame index of the sprite</returns>
	int getFrameIndex();

	/// <summary>
	/// Returns the sprite's character
	/// </summary>
	/// <returns>The Character enum for this sprite</returns>
	globals::Character getCharacter();
private:
	SDL_Rect _sourceRect;
	globals::Character _character;
	int _x, _y, _frameIndex;
};

#endif // !SPRITE_H
