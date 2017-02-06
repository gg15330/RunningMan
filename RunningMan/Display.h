#pragma once

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Sprite.h"
#include "Globals.h"

#include <SDL.h>
#include <SDL_image.h>

#include <vector>


/// <summary>
/// Creates SDL window/renderer components and draws <see cref="Sprite"/> objects
/// </summary>
class Display
{
public:
	Display();
	~Display();

	/// <summary>
	/// Adds a <see cref="Sprite"/> to the list
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
	/// <returns></returns>
	SDL_Renderer* getRenderer() noexcept;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	std::vector<Sprite*> _sprites;

	/// <summary>
	/// Draws a texture to a certain part of the screen
	/// </summary>
	void blitSurface(SDL_Texture* source, const SDL_Rect* sourceRectangle, const SDL_Rect* destinationRectangle);

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
