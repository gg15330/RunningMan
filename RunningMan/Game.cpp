#include "Globals.h"
#include "Sprite.h"
#include "Game.h"

#include <iostream>
#include <algorithm>

#define NOMINMAX


namespace {
	const int FPS{ 50 };
	const int MAX_FRAME_TIME{ 5 * 1000 / FPS };
}



Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	_display.init();
}

void Game::gameLoop()
{
	Player player(_display.getRenderer(), globals::PLAYER_SPRITE_FILEPATH, 0, 0, globals::PLAYER_SPRITE_WIDTH, globals::PLAYER_SPRITE_HEIGHT, 0, 0);
	_display.registerSprite(player.getSprite());

	int x = 0;
	int y = 0;
	int lastUpdateTime = SDL_GetTicks();
	while (true)
	{
		_input.clearKeyArrays();
		_input.processEvents();
		if (_input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) 
		{
			_display.quit();
			return;
		}
		else if (_input.wasKeyPressed(SDL_SCANCODE_DOWN))
		{
			player.updatePos(x++, y++);
		}
		const int currentTimeMS = SDL_GetTicks();
		int elapsedTime = currentTimeMS - lastUpdateTime;
		_display.draw(MAX_FRAME_TIME);
	}




	//_sprites[Character::PLAYER] = &_player;
	//SDL_Texture* playerSpriteSheet = _graphics.loadTexture(globals::PLAYER_SPRITE_FILEPATH);
	//_graphics.addSpriteSheet(Character::PLAYER, playerSpriteSheet);
	//int x = 0;
	//int y = 0;
	//int lastUpdateTime = SDL_GetTicks();
	//while (true)
	//{
	//	_input.clearKeyArrays();
	//	_input.processEvents();
	//	if (_input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) 
	//	{
	//		_graphics.quit();
	//		return;
	//	}
	//	_player.updatePos(x++, y++);
	//	//_graphics.draw();
	//	const int currentTimeMS = SDL_GetTicks();
	//	int elapsedTime = currentTimeMS - lastUpdateTime;
	//	_graphics.draw(Character::PLAYER, _player.getSourceRect(), _player.getDestinationRect(), std::min(elapsedTime, MAX_FRAME_TIME));
	//}
}

void Game::update(int elapsedTime)
{
}
