#pragma once

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
	/// Returns the Sprite's frame index
	/// </summary>
	/// <returns>The frame index of the sprite</returns>
	int getFrameIndex();

	/// <summary>
	/// Returns the sprite's character
	/// </summary>
	/// <returns>The character enum for this sprite</returns>
	globals::Character getCharacter();

	/// <summary>
	/// Returns the file path for this sprite's image file
	/// </summary>
	/// <returns>The file path of the sprite image</returns>
	char* getFilePath();
private:
	SDL_Rect _sourceRect;
	globals::Character _character;
	char* _filePath;
	int _x, _y, _frameIndex;
};

