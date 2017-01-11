#pragma once

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Sprite.h"
#include "Globals.h"

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <vector>


class Sprite;

/// <summary>
/// 
/// </summary>
class Display
{
public:
	Display();
	~Display();

	/// <summary>
	/// 
	/// </summary>
	void registerSprite(Sprite* sprite);

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
	void draw(int elapsedTime);

	/// <summary>
	/// Returns the renderer
	/// </summary>
	/// <returns>A pointer to the SDL_Renderer for this class</returns>
	SDL_Renderer* getRenderer();

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	std::vector<Sprite*> _sprites;

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
