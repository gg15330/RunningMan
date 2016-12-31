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
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Running man");
}

void Graphics::quit()
{
	std::cout << "Shutting down SDL components...\n";
	SDL_DestroyRenderer(this->_renderer);
	SDL_DestroyWindow(this->_window);
	SDL_Quit();
}

void Graphics::draw()
{
	this->clear();
	SDL_Texture* spriteSheet = _spriteSheets[globals::PLAYER];
	if (spriteSheet == NULL)
	{
		fprintf(stderr, "ERROR: Could not fetch spritesheet");
	}
	std::cout << "Fetched texture: " << globals::PLAYER << "\n";
	this->blitSurface(spriteSheet, NULL, NULL);
	this->flip();
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) 
{
	int success = SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
	std::cout << success << "\n";
}

void Graphics::flip()
{
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() 
{
	SDL_RenderClear(this->_renderer);
}

void Graphics::addSpriteSheet(Sprite &sprite)
{
	std::cout << "PLAYER: " << sprite.getCharacter() << "\n";
	if (this->_spriteSheets.count(sprite.getCharacter()) == 0)
	{
		this->_spriteSheets[sprite.getCharacter()] = IMG_LoadTexture(_renderer, sprite.getFilePath());
		if (this->_spriteSheets[sprite.getCharacter()] == NULL)
		{
			fprintf(stderr, "Could not load texture: %s\n", sprite.getFilePath());
		}
		std::cout << "Spritesheet added to Graphics...\n";
	}
}

SDL_Renderer * Graphics::getRenderer()
{
	return this->_renderer;
}
