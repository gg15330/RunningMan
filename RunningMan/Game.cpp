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
	Sprite platformSprite{  _display.getRenderer(),
		globals::PLATFORM_SPRITE_FILEPATH,
		globals::PLATFORM_SOURCE_POS.x,
		globals::PLATFORM_SOURCE_POS.y,
		globals::PLATFORM_SPRITE_WIDTH,
		globals::PLATFORM_SPRITE_HEIGHT,
		globals::PLATFORM_STARTING_POS.x,
		globals::PLATFORM_STARTING_POS.y };
	Sprite playerSprite{ _display.getRenderer(),
		globals::PLAYER_SPRITE_FILEPATH,
		globals::PLAYER_SOURCE_POS.x,
		globals::PLAYER_SOURCE_POS.y,
		globals::PLAYER_SPRITE_WIDTH,
		globals::PLAYER_SPRITE_HEIGHT,
		globals::PLAYER_STARTING_POS.x,
		globals::PLAYER_STARTING_POS.y };
	_level = Level(_player);
	_platform = Terrain{ platformSprite };
	_level.addTerrain(&_platform);
	_platform.setSprite(platformSprite);
	_player.setSprite(playerSprite);
	_display.registerSprite(_platform.sprite());
	_display.registerSprite(_player.sprite());
}

void Game::gameLoop()
{
	int lastUpdateTime = SDL_GetTicks();
	int currentTimeMS = 0;
	int elapsedTime	= 0;
	while (true)
	{
		_input.clearKeyArrays();
		_input.processEvents();
		
		//check for exit command
		if (_input.pressed(SDL_SCANCODE_ESCAPE))
		{
			_display.quit();
			return;
		}	

		//move player
		else if (_input.held(SDL_SCANCODE_LEFT))
		{
			_player.move(LEFT);
		}
		else if (_input.held(SDL_SCANCODE_RIGHT))
		{
			_player.move(RIGHT);
		}
		else if (_input.held(SDL_SCANCODE_UP))
		{
			_player.move(UP);
		}
		else if (_input.held(SDL_SCANCODE_DOWN))
		{
			_player.move(DOWN);
		}
		if (!_input.held(SDL_SCANCODE_LEFT) && !_input.held(SDL_SCANCODE_RIGHT) && !_input.held(SDL_SCANCODE_UP) && !_input.held(SDL_SCANCODE_DOWN))
		{
			_player.stop();
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
	if (_timeElapsed < _timeToUpdate)			
	{
		return;
	}
	Direction collision = _level.collisionDetected(&_player);
	if (collision != NONE)
	{
		std::cout << collision << std::endl;
	}
	_player.update(timeElapsed);
	_timeElapsed = 0;
}

