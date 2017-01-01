#include "Globals.h"
#include "Sprite.h"
#include "Game.h"


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
	Sprite sprite = Sprite(globals::PLAYER, 0, 0, 16, 16, 0, 0);
	SDL_Texture* playerSpriteSheet = _graphics.loadTexture(globals::PLAYER_SPRITE_FILEPATH);
	_graphics.addSpriteSheet(sprite.getCharacter(), playerSpriteSheet);

	while (true)
	{
		_input.clearKeyArrays();
		_input.processEvents();

		if (_input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) 
		{
			_graphics.quit();
			return;
		}

		_graphics.draw();
	}
}
