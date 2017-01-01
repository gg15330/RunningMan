#pragma once

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Sprite.h"

#include <SDL.h>
#include <SDL_image.h>

#include <map>


class Graphics
{
public:
	Graphics();
	~Graphics();

	/// <summary>
	/// Initialises SDL components
	/// </summary>
	void init();

	/// <summary>
	/// Shuts down SDL components
	/// </summary>
	void quit();

	/// <summary>
	/// Draws everything to the screen
	/// </summary>
	void draw();

	/// <summary>
	/// Adds a spritesheet to the spritesheet map
	/// </summary>
	/// <param name="sprite">The spritesheet to add</param>
	void addSpriteSheet(Sprite &sprite);

	/// <summary>
	/// Returns the renderer
	/// </summary>
	/// <returns>A pointer to the SDL_Renderer for this class</returns>
	SDL_Renderer* getRenderer();
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	std::map<globals::Character, SDL_Texture*> _spriteSheets;

	/// <summary>
	/// Draws a texture to a certain part of the screen
	/// </summary>
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/// <summary>
	/// Renders everything to the screen
	/// </summary>
	void flip();

	/// <summary>
	/// Clears the screen
	/// </summary>
	void clear();
};

#endif // !GRAPHICS_H
