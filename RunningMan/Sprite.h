#pragma once

#ifndef SPRITE_H
#define SPRITE_H

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

	/// <summary>
	/// Updates the position of the spritesheet's source rectangle
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void updateSourceRect(int x, int y);

	/// <summary>
	/// Updates the position of the spritesheet's destination rectangle
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void updateDestRect(int x, int y);

	/// <summary>
	/// Returns the sprite's current source SDL_Rect
	/// </summary>
	/// <returns>A pointer to the sprite's current source SDL_Rect</returns>
	SDL_Rect* getSourceRect() noexcept;

	/// <summary>
	/// Returns the sprite's current destination SDL_Rect
	/// </summary>
	/// <returns>A pointer to the sprite's current destination SDL_Rect</returns>
	SDL_Rect* getDestRect() noexcept;

	/// <summary>
	/// Get the spritesheet
	/// </summary>
	/// <returns></returns>
	SDL_Texture* getTexture() noexcept;

private:
	SDL_Texture* _texture;
	SDL_Rect _sourceRect;
	SDL_Rect _destRect;

	/// <summary>
	/// Loads a texture into the renderer
	/// </summary>
	/// <param name="filePath">the file path of the image to create a texture from</param>
	/// <param name="renderer">The SDL_Renderer to load the image to</param>
	void loadTexture(const char* filePath, SDL_Renderer* renderer);

	/// <summary>
	/// Helper function to round floats to int
	/// </summary>
	/// <param name="f"></param>
	/// <returns></returns>
	int roundToInt(const float f);
};

#endif // !SPRITE_H
