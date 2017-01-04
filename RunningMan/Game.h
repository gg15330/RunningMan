#pragma once

#ifndef GAME_H
#define GAME_H

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
	Sprite _player;
	std::map<Character, Sprite*> _sprites;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="elapsedTime"></param>
	void update(int elapsedTime);
};

#endif // !GAME_H
