#pragma once

#include "Globals.h"
#include "Graphics.h"
#include "Input.h"
#include "Sprite.h"

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

