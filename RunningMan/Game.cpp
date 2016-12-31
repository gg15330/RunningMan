#include "Game.h"

#include <SDL.h>
#include <iostream>

Game::Game()
{
}


Game::~Game()
{
}

void Game::init()
{
	this->_graphics.init();
}

void Game::gameLoop()
{
	Sprite sprite = Sprite(globals::PLAYER, globals::PLAYER_SPRITE_FILEPATH, 0, 0, 16, 16, 0, 0);
	_graphics.addSpriteSheet(sprite);
	_graphics.draw();

	//SDL_Texture* texture = IMG_LoadTexture(_graphics.getRenderer(), globals::PLAYER_SPRITE_FILEPATH);

	//SDL_Rect destinationRectangle;
	//destinationRectangle.x = 10;
	//destinationRectangle.y = 10;
	//destinationRectangle.w = 16;
	//destinationRectangle.h = 16;

	//SDL_RenderClear(this->_graphics.getRenderer());
	//SDL_RenderCopy(this->_graphics.getRenderer(), sprite.getSpriteSheet(), NULL);
	//SDL_RenderPresent(this->_graphics.getRenderer());

	//this->_graphics.addSprite(globals::Character::PLAYER, globals::PLAYER_SPRITE_FILEPATH);
	//this->_graphics.draw(&sprite);

	while (true)
	{
		this->_input.clearKeyArrays();
		this->_input.processEvents();

		if (this->_input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) 
		{
			this->_graphics.quit();
			return;
		}

		//this->_graphics.draw();
	}
}
