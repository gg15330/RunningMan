#pragma once

#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>


/// <summary>
/// 
/// </summary>
class Sprite
{
public:
	Sprite();
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
	/// 
	/// </summary>
	void update(int elapsedTime);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void updateSourceRect(int x, int y);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void updateDestRect(int x, int y);

	/// <summary>
	/// Get the sprite's current source SDL_Rect
	/// </summary>
	/// <returns>A pointer to the sprite's current source SDL_Rect</returns>
	SDL_Rect* getSourceRect() noexcept;

	/// <summary>
	/// Get the sprite's current destination SDL_Rect
	/// </summary>
	/// <returns>A pointer to the sprite's current destination SDL_Rect</returns>
	SDL_Rect* getDestinationRect() noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	SDL_Texture* getTexture() noexcept;

private:
	SDL_Texture* _texture;
	SDL_Rect _sourceRect;
	SDL_Rect _destinationRect;
	int _x, _y;

	/// <summary>
	/// Loads a texture into the renderer
	/// </summary>
	/// <param name="filePath">the file path of the image to create a texture from</param>
	/// <returns>A pointer to the new texture</returns>
	SDL_Texture* loadTexture(const char* filePath, SDL_Renderer* renderer);
};

#endif // !SPRITE_H
