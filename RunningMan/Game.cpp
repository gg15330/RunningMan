#include "Game.h"


constexpr int FPS{ 50 };
constexpr int MAX_FRAME_TIME{ 1000 / FPS };
constexpr int STARTING_POSX{ (globals::SCREEN_WIDTH - globals::PLAYER_SPRITE_WIDTH) / 2 };
constexpr int STARTING_POSY{ globals::SCREEN_HEIGHT - globals::PLAYER_SPRITE_HEIGHT };
const Vector2 STARTING_POS{ STARTING_POSX, STARTING_POSY };


Game::Game() :
	_timeToUpdate{ 10 },
	_timeElapsed{ 0 },
	_x{ 0 },
	_y{ 0 }
{
}

Game::~Game()
{
}

void Game::init()
{
	_display.init();
	_player = Player(_display.getRenderer(),
		globals::PLAYER_SPRITE_FILEPATH,
		0,
		0,
		globals::PLAYER_SPRITE_WIDTH,
		globals::PLAYER_SPRITE_HEIGHT,
		STARTING_POSX,
		STARTING_POSY);
}

void Game::gameLoop()
{
	std::cout << _timeToUpdate << std::endl;
	_display.registerSprite(&_player);

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
		const int currentTimeMS = SDL_GetTicks();
		int elapsedTime = currentTimeMS - lastUpdateTime;
		update(std::min(elapsedTime, MAX_FRAME_TIME));
		lastUpdateTime = currentTimeMS;
		_display.draw(MAX_FRAME_TIME);
	}
}

void Game::update(int elapsedTime)
{
	this->_timeElapsed += elapsedTime;
	if (this->_timeElapsed > this->_timeToUpdate) {
		_player.update(_x++, _y++);
		_timeElapsed = 0;
	}
}
