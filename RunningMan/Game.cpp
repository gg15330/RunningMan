#include "Globals.h"
#include "Graphics.h"
#include "Input.h"
#include "Sprite.h"
#include "Game.h"

#include <SDL.h>
#include <iostream>

Graphics graphics;
Input input;

Game::Game()
{
}


Game::~Game()
{
}

void Game::init()
{
	_graphics = &graphics;
	_input = &input;
	_graphics->init();
}

void Game::gameLoop()
{
	Sprite sprite = Sprite(globals::PLAYER, globals::PLAYER_SPRITE_FILEPATH, 0, 0, 16, 16, 0, 0);
	_graphics->addSpriteSheet(sprite);

	while (true)
	{
		_input->clearKeyArrays();
		_input->processEvents();

		if (_input->wasKeyPressed(SDL_SCANCODE_ESCAPE)) 
		{
			_graphics->quit();
			return;
		}

		_graphics->draw();
	}
}
