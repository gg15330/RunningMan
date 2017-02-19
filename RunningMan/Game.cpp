#include "Game.h"


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
	_platform = Entity{ _display.getRenderer(),
		globals::PLATFORM_SPRITE_FILEPATH,
		globals::PLATFORM_SOURCE_POS.x,
		globals::PLATFORM_SOURCE_POS.y,
		globals::PLATFORM_SPRITE_WIDTH,
		globals::PLATFORM_SPRITE_HEIGHT,
		globals::PLATFORM_STARTING_POS.x,
		globals::PLATFORM_STARTING_POS.y };
	_player = Player{ _display.getRenderer(),
		globals::PLAYER_SPRITE_FILEPATH,
		globals::PLAYER_SOURCE_POS.x,
		globals::PLAYER_SOURCE_POS.y,
		globals::PLAYER_SPRITE_WIDTH,
		globals::PLAYER_SPRITE_HEIGHT,
		globals::PLAYER_STARTING_POS.x,
		globals::PLAYER_STARTING_POS.y };
	_level = Level(&_player);
	_level.addTerrain(&_platform);
	_player.setX(50.0f);
	_player.setY(150.0f);
	_platform.setX(50.0f);
	_platform.setY(400.0f);
	_display.registerEntity(&_platform);
	_display.registerEntity(&_player);
}

void Game::gameLoop()
{
	int LAST_UPDATE_TIME = SDL_GetTicks();
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

		}
		else if (_input.held(SDL_SCANCODE_DOWN))
		{

		}
		else if (!_input.held(SDL_SCANCODE_LEFT) && !_input.held(SDL_SCANCODE_RIGHT))
		{
			_player.stop();
		}
		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;
		_display.draw(MAX_FRAME_TIME);
	}
}

void Game::update(int timeElapsed)
{
	if (timeElapsed > MAX_FRAME_TIME)
	{
		return;
	}
	_player.handleTileCollisions(_level.entityCollisions(&_player));
	_player.update(timeElapsed);
}

