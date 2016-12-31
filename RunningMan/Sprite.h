#pragma once

#include "Globals.h"

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Sprite
{
public:
	Sprite();
	Sprite(globals::Character character,
		char* filePath,
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
	/// Get the sprite's current SDL_Texture
	/// </summary>
	/// <returns>A pointer to the sprite's current SDL_Texture</returns>
	SDL_Texture* getSpriteSheet();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	int getFrame();

	/// <summary>
	/// 
	/// </summary>
	globals::Character getCharacter();

	char* getFilePath();
private:
	globals::Character _character;
	SDL_Texture* _spriteSheet;
	SDL_Rect _sourceRect;
	char* _filePath;
	int _x, _y, _frame;
};

