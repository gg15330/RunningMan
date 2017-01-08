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

void Graphics::updateRect(int x, int y)
{
}

void Graphics::draw(Character character, SDL_Rect* sourceRect, SDL_Rect* destinationRect, int elapsedTime)
{
	clear();
	blitSurface(_spriteSheets[character], sourceRect, destinationRect);
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

SDL_Renderer * Graphics::getRenderer()
{
	return _renderer;
}
