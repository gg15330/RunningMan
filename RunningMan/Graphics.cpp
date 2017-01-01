#include "Graphics.h"

#include <iostream>


Graphics::Graphics()
{
}


Graphics::~Graphics()
{
}

void Graphics::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &_window, &_renderer);
	SDL_SetWindowTitle(_window, "Running man");
}

void Graphics::quit()
{
	std::cout << "Shutting down SDL components...\n";
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void Graphics::draw(int x, int y)
{
	SDL_Rect destRect;
	destRect.h = 16;
	destRect.w = 16;
	destRect.x = x;
	destRect.y = y;

	clear();
	blitSurface(_spriteSheets[Character::PLAYER], NULL, &destRect);
	flip();
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) 
{
	SDL_RenderCopy(_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip()
{
	SDL_RenderPresent(_renderer);
}

void Graphics::clear() 
{
	SDL_RenderClear(_renderer);
}

void Graphics::addSpriteSheet(Character character, SDL_Texture* spriteSheet)
{
	if (_spriteSheets.count(character) == 0)
	{
		_spriteSheets[character] = spriteSheet;

		if (_spriteSheets[character] == NULL)
		{
			fprintf(stderr, "ERROR: Could not load texture\n");
		}
	}
}

SDL_Texture * Graphics::loadTexture(char * filePath)
{
	SDL_Texture* texture = IMG_LoadTexture(_renderer, filePath);

	if (texture == NULL)
	{
		fprintf(stderr, "Could not load texture: %s\n", filePath);
	}

	return texture;
}

SDL_Renderer * Graphics::getRenderer()
{
	return _renderer;
}
