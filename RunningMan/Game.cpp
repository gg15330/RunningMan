#include "Game.h"


int _timeElapsed				{ 0 };
constexpr int _timeToUpdate		{ 10 };
constexpr int FPS				{ 50 };
constexpr int MAX_FRAME_TIME	{ 1000 / FPS };


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
	int lastUpdateTime = SDL_GetTicks();
	int currentTimeMS = 0;
	int elapsedTime	= 0;
	Sprite playerSprite{ Sprite{ _display.getRenderer(),
		globals::PLAYER_SPRITE_FILEPATH,
		globals::PLAYER_SOURCE_POS.x,
		globals::PLAYER_SOURCE_POS.y,
		globals::PLAYER_SPRITE_WIDTH,
		globals::PLAYER_SPRITE_HEIGHT,
		globals::PLAYER_STARTING_POS.x,
		globals::PLAYER_STARTING_POS.y } };
	Sprite platformSprite{ Sprite{ _display.getRenderer(),
		globals::PLATFORM_SPRITE_FILEPATH,
		globals::PLATFORM_SOURCE_POS.x,
		globals::PLATFORM_SOURCE_POS.y,
		globals::PLATFORM_SPRITE_WIDTH,
		globals::PLATFORM_SPRITE_HEIGHT,
		globals::PLATFORM_STARTING_POS.x,
		globals::PLATFORM_STARTING_POS.y } };
	Terrain platform{ platformSprite };
	std::cout << "Terrain created: " << &platform << std::endl;
	Player player{ playerSprite };
	std::cout << "Player created: " << &player << std::endl;
	_display.registerSprite(player.getSprite());
	_display.registerSprite(platform.getSprite());
	while (true)
	{
		_input.clearKeyArrays();
		_input.processEvents();
		if (_input.wasKeyPressed(SDL_SCANCODE_ESCAPE))
		{
			_display.quit();
			return;
		}
		currentTimeMS = SDL_GetTicks();
		elapsedTime	= currentTimeMS - lastUpdateTime;
		update(std::min(elapsedTime, MAX_FRAME_TIME));
		lastUpdateTime = currentTimeMS;
		_display.draw(MAX_FRAME_TIME);
	}
}

void Game::update(int timeElapsed)
{
	_timeElapsed += timeElapsed;
	if (_timeElapsed < _timeToUpdate)				{ return; }
	//if (_input.isKeyHeld(SDL_SCANCODE_RIGHT))		{ player.move(RIGHT); }
	//if (_input.isKeyHeld(SDL_SCANCODE_LEFT))		{ player.move(LEFT); }
	//if (_input.isKeyHeld(SDL_SCANCODE_UP))			{ player.move(UP); }
	//if (_input.isKeyHeld(SDL_SCANCODE_DOWN))		{ player.move(DOWN); }
	_timeElapsed = 0;
}
