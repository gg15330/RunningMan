#pragma once

#ifndef GAME_H
#define GAME_H

#include "Graphics.h"
#include "Input.h"

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
	Graphics _graphics;
	Input _input;
};

#endif // !GAME_H
