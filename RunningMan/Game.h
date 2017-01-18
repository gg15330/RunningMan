#pragma once

#ifndef GAME_H
#define GAME_H

#include "Display.h"
#include "Input.h"
#include "Player.h"

#include <algorithm>

#define NOMINMAX


/// <summary>
/// Controls game logic
/// </summary>
class Game
{
public:
	Game();
	~Game();

	/// <summary>
	/// Initialises game objects
	/// </summary>
	void init();

	/// <summary>
	/// Main game loop
	/// </summary>
	void gameLoop();
private:
	Display _display;
	Input _input;
	Player _player;
	int _timeElapsed, _timeToUpdate;

	/// <summary>
	/// Updates all game objects
	/// </summary>
	/// <param name="elapsedTime">The amount of time since the last update (ms)</param>
	void update(int elapsedTime);
};

#endif // !GAME_H
