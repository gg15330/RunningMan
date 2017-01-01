#include "Globals.h"
#include "Sprite.h"
#include "Game.h"

#include <iostream>


Game::Game()
{
}


Game::~Game()
{
}

void Game::init()
{
	_graphics.init();
}

void Game::gameLoop()
{
	Sprite sprite = Sprite(Character::PLAYER, 0, 0, 16, 16, 0, 0);
	SDL_Texture* playerSpriteSheet = _graphics.loadTexture(globals::PLAYER_SPRITE_FILEPATH);
	_graphics.addSpriteSheet(sprite.getCharacter(), playerSpriteSheet);

	int x = 0;
	SDL_Rect rect;
	rect.h = 16;
	rect.w = 16;
	rect.x = x;
	rect.y = 10;

	while (true)
	{
		_input.clearKeyArrays();
		_input.processEvents();

		if (_input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) 
		{
			_graphics.quit();
			return;
		}

		rect.x++;
		std::cout << rect.x << "\n";
		sprite.update(rect);
		_graphics.draw(sprite.getX(), sprite.getY());
		//_graphics.draw();
	}
}
