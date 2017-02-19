#pragma once

#ifndef GAME_H
#define GAME_H

#define NOMINMAX

#include "Display.h"
#include "Input.h"
#include "Level.h"
#include "Player.h"

#include <algorithm>


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
	Level _level;
	Player _player;
	Entity _platform;

	/// <summary>
	/// Updates all game objects
	/// </summary>
	/// <param name="elapsedTime">The amount of time since the last update (ms)</param>
	void update(int elapsedTime);
};

#endif // !GAME_H
