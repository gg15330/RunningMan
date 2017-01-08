#pragma once

#ifndef SPRITE_H
#define SPRITE_H

#include "Globals.h"

#include <SDL.h>
#include <SDL_image.h>


class Sprite
{
public:
	Sprite(SDL_Renderer* renderer,
		const char* filePath,
		int sourceX, 
		int sourceY, 
		int width, 
		int height, 
		int posX, 
		int posY);
	virtual ~Sprite();

	/// <summary>
	/// Loads a texture into the renderer
	/// </summary>
	/// <param name="filePath">the file path of the image to create a texture from</param>
	/// <returns>A pointer to the new texture</returns>
	SDL_Texture* loadTexture(char* filePath, SDL_Renderer* renderer);


	/// <summary>
	/// Updates the spritesheet
	/// </summary>
	virtual void updatePos(int x, int y);

	/// <summary>
	/// Get the sprite's current source SDL_Rect
	/// </summary>
	/// <returns>A pointer to the sprite's current source SDL_Rect</returns>
	SDL_Rect* getSourceRect();

	/// <summary>
	/// Get the sprite's current destination SDL_Rect
	/// </summary>
	/// <returns>A pointer to the sprite's current destination SDL_Rect</returns>
	SDL_Rect* getDestinationRect();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	SDL_Texture* getSpriteSheet();
private:
	SDL_Texture* _spriteSheet;
	SDL_Rect _sourceRect;
	SDL_Rect _destinationRect;
};

#endif // !SPRITE_H
