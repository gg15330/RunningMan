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
	Sprite platformSprite{ Sprite{ _display.getRenderer(),
		globals::PLATFORM_SPRITE_FILEPATH,
		globals::PLATFORM_SOURCE_POS.x,
		globals::PLATFORM_SOURCE_POS.y,
		globals::PLATFORM_SPRITE_WIDTH,
		globals::PLATFORM_SPRITE_HEIGHT,
		globals::PLATFORM_STARTING_POS.x,
		globals::PLATFORM_STARTING_POS.y } };
	Sprite playerSprite{ Sprite{ _display.getRenderer(),
		globals::PLAYER_SPRITE_FILEPATH,
		globals::PLAYER_SOURCE_POS.x,
		globals::PLAYER_SOURCE_POS.y,
		globals::PLAYER_SPRITE_WIDTH,
		globals::PLAYER_SPRITE_HEIGHT,
		globals::PLAYER_STARTING_POS.x,
		globals::PLAYER_STARTING_POS.y } };
	_platform.setSprite(platformSprite);
	_player.setSprite(playerSprite);
	_display.registerSprite(_platform.getSprite());
	_display.registerSprite(_player.getSprite());
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
	SDL_Rect* platformRect = _platform.getDestRect();
	SDL_Rect* playerRect = _player.getDestRect();
	//SDL_Rect playerRect = { _player.getDestRect()->x - 1,
	//	_player.getDestRect()->y - 1,
	//	_player.getDestRect()->w + 2,
	//	_player.getDestRect()->h + 2 };
	if (_timeElapsed < _timeToUpdate) { return; }
	if (_input.isKeyHeld(SDL_SCANCODE_RIGHT) && 
		!collision(platformRect, playerRect))		
	{ 
		_player.move(RIGHT); 
	}
	if (_input.isKeyHeld(SDL_SCANCODE_LEFT) && 
		!collision(platformRect, playerRect))
	{ 
		_player.move(LEFT); 
	}
	if (_input.isKeyHeld(SDL_SCANCODE_UP) && 
		!collision(platformRect, playerRect))
	{
		_player.move(UP); 
	}
	if (_input.isKeyHeld(SDL_SCANCODE_DOWN) && 
		!collision(platformRect, playerRect))		
	{ 
		_player.move(DOWN); 
	}
	_timeElapsed = 0;
}

bool Game::collision(const SDL_Rect * rect1, const SDL_Rect *rect2)
{
	if (rect1->x - 1 < (rect2->x + rect2->w) &&
		(rect1->x + rect1->w) > rect2->x - 1 &&
		rect1->y - 1 < (rect2->y + rect2->h) &&
		(rect1->h + rect1->y) > rect2->y - 1)
	{
		return true;
	}
	return false;
}

