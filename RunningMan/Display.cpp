#include "Display.h"


Display::Display()
{
}

Display::~Display()
{
}


void Display::registerSprite(Sprite* sprite)
{
	_sprites.push_back(sprite);
}

void Display::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &_window, &_renderer);
	SDL_SetWindowTitle(_window, "Running man");
}

void Display::quit()
{
	std::cout << "Shutting down SDL components...\n";
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void Display::draw(int elapsedTime)
{
	clear();
	for each (Sprite* sprite in _sprites)
	{
		blitSurface(sprite->getTexture(), sprite->getSourceRect(), sprite->getDestRect());
	}
	flip();
}

void Display::blitSurface(SDL_Texture* texture, const SDL_Rect* sourceRectangle, const SDL_Rect* destinationRectangle) 
{
	SDL_RenderCopy(_renderer, texture, sourceRectangle, destinationRectangle);
}

void Display::flip()
{
	SDL_RenderPresent(_renderer);
}

void Display::clear() 
{
	SDL_RenderClear(_renderer);
}

SDL_Renderer * Display::getRenderer() noexcept
{
	return _renderer;
}
