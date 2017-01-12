#include "Game.h"


constexpr int FPS{ 50 };
constexpr int MAX_FRAME_TIME{ 5 * 1000 / FPS };
constexpr int STARTING_POSX{ (globals::SCREEN_WIDTH - globals::PLAYER_SPRITE_WIDTH) / 2 };
constexpr int STARTING_POSY{ globals::SCREEN_HEIGHT - globals::PLAYER_SPRITE_HEIGHT };
const Vector2 STARTING_POS{ STARTING_POSX, STARTING_POSY };


Game::Game() :
	_timeToUpdate{ 10 },
	_timeElapsed{ 0 }
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
	_display.registerSprite(&_player);

	int x = 0;
	int y = 0;
	int lastUpdateTime = SDL_GetTicks();
	while (true)
	{
		_input.clearKeyArrays();
		_input.processEvents();
		/*if (_input.isKeyHeld(SDL_SCANCODE_DOWN))
		{
			_player.updatePos(x++, y++);
		}*/
		/*else*/ if (_input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) 
		{
			_display.quit();
			return;
		}
		//else if (_input.wasKeyPressed(SDL_SCANCODE_DOWN))
		//{
		//	player.updatePos(x++, y++);
		//}
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
	std::cout << _timeElapsed << "\n";
	if (this->_timeElapsed > this->_timeToUpdate) {
		_player.update(elapsedTime);
		_timeElapsed = 0;
	}
}
