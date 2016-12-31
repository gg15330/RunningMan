#pragma once

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Globals.h"
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

	/// <summary>+
	/// Creates a texture from an image
	/// </summary>
	/// <param name="filePath">The file path of the image to be loaded into the texture</param>
	/// <returns>A pointer to the SDL_Texture that has been loaded</returns>
	//SDL_Texture* createTexture(const std::string & filePath);

	/// <summary>
	/// Draws everything to the screen
	/// </summary>
	void draw();

	/* void blitSurface
	* Draws a texture to a certain part of the screen
	*/
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/* void flip
	* Renders everything to the screen
	*/
	void flip();

	/* void clear
	* Clears the screen
	*/
	void clear();

	/// <summary>
	/// Adds a sprite to the sprite map
	/// </summary>
	/// <param name="sprite">The sprite to add</param>
	/// <param name="filePath">The file path of the sprite image</param>
	void addSpriteSheet(Sprite &sprite);

	SDL_Renderer* getRenderer();
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	std::map<globals::Character, SDL_Texture*> _spriteSheets;
	std::map<globals::Character, Sprite> _sprites;
	Sprite* _playerSprite;
};

#endif // !GRAPHICS_H
