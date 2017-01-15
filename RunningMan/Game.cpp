#include "Game.h"

#include "Timer.h"

#include <sstream>


constexpr int FPS{ 50 };
constexpr int MAX_FRAME_TIME{ 1000 / FPS };
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
	Sprite sprite = Sprite(_display.getRenderer(), 
		globals::PLAYER_SPRITE_FILEPATH, 
		0, 
		0, 
		globals::PLAYER_SPRITE_WIDTH,
		globals::PLAYER_SPRITE_HEIGHT,
		STARTING_POSX,
		STARTING_POSY);

	_player = Player(sprite);
}

void Game::gameLoop()
{
	std::cout << _timeToUpdate << std::endl;
	_display.registerSprite(_player.getSprite());

	std::stringstream timeText;
	int lastUpdateTime = SDL_GetTicks();

	while (true)
	{
		//In memory text stream 
		//Set text to be rendered 
		timeText.str("");
		timeText << "Seconds: " << (SDL_GetTicks() / 1000.0f);
		//Render text 
		std::cout << timeText.str() << std::endl;

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
	if (this->_timeElapsed < this->_timeToUpdate)	{ return; }
	if (_input.isKeyHeld(SDL_SCANCODE_RIGHT))		{ _player.move(RIGHT); }
	if (_input.isKeyHeld(SDL_SCANCODE_LEFT))		{ _player.move(LEFT); }
	if (_input.isKeyHeld(SDL_SCANCODE_UP))			{ _player.move(UP); }
	if (_input.isKeyHeld(SDL_SCANCODE_DOWN))		{ _player.move(DOWN); }
	_timeElapsed = 0;
}
