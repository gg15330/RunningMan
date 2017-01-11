#pragma once

#ifndef GAME_H
#define GAME_H

#include "Display.h"
#include "Input.h"
#include "Player.h"

#include <iostream>
#include <algorithm>

#define NOMINMAX


/// <summary>
/// 
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

	/// <summary>
	/// 
	/// </summary>
	/// <param name="elapsedTime"></param>
	void update(int elapsedTime);
};

#endif // !GAME_H
