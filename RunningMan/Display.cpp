#include "Display.h"


Display::Display()
{
}

Display::~Display()
{
}


void Display::registerEntity(Entity* sprite)
{
	_entities.push_back(sprite);
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
	SDL_Rect r;
	clear();
	for each (Entity* entity in _entities)
	{
		r = *entity->sprite()->getDestRect();
		r.x = entity->position().x;
		r.y = entity->position().y;
		blitSurface(entity->sprite()->getTexture(), entity->sprite()->getSourceRect(), &r);
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
