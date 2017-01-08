#include "Globals.h"
#include "Sprite.h"
#include "Game.h"

#include <iostream>
#include <algorithm>

#define NOMINMAX


namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}



Game::Game() :
	_player(Sprite(_graphics.getRenderer(), globals::PLAYER_SPRITE_FILEPATH, 0, 0, globals::PLAYER_SPRITE_WIDTH, globals::PLAYER_SPRITE_HEIGHT, 0, 0))
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
