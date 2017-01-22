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
	if (_timeElapsed < _timeToUpdate) { return; }
	SDL_Rect oldPlayerRect = SDL_Rect
	{
		_player.getDestRect()->x,
		_player.getDestRect()->y,
		_player.getDestRect()->w,
		_player.getDestRect()->h
	};
		

	//Gravity
	//_player.setVelocity(Vector2{ _player.getVelocity().x, globals::GRAVITY });
	
	//Left/right
	if (_input.isKeyHeld(SDL_SCANCODE_RIGHT))		
	{
		SDL_Rect newPlayerRect = SDL_Rect
		{
			oldPlayerRect.x + 1,
			oldPlayerRect.y,
			oldPlayerRect.w,
			oldPlayerRect.h
		};
		if (!SDL_HasIntersection(_platform.getDestRect(), &newPlayerRect)) 
		{
			_player.setVelocity(Vector2{ 1, 0 });
			_player.updatePos();
		}
	}
	if (_input.isKeyHeld(SDL_SCANCODE_LEFT))
	{
		SDL_Rect newPlayerRect = SDL_Rect
		{
			oldPlayerRect.x - 1,
			oldPlayerRect.y,
			oldPlayerRect.w,
			oldPlayerRect.h
		};
		if (!SDL_HasIntersection(_platform.getDestRect(), &newPlayerRect))
		{
			_player.setVelocity(Vector2{ -1, 0 });
			_player.updatePos();
		}
	}		

	//if (_input.isKeyHeld(SDL_SCANCODE_UP))
	//{
	//	if (!_player.jumping())
	//	{
	//		_player.setJumping(true);
	//		_player.setVelocity(Vector2(_player.getVelocity().x, -10));
	//		_player.updatePos();
	//	}
	//	_player.setVelocity((Vector2(_player.getVelocity().x, _player.getVelocity().y + globals::GRAVITY)));
	//}
	_timeElapsed = 0;
}

