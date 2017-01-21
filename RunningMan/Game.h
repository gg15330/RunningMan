#pragma once

#ifndef GAME_H
#define GAME_H

#include "Display.h"
#include "Input.h"
#include "Player.h"
#include "Terrain.h"

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
	Terrain _platform;

	/// <summary>
	/// Updates all game objects
	/// </summary>
	/// <param name="elapsedTime">The amount of time since the last update (ms)</param>
	void update(int elapsedTime);

	/// <summary>
	/// Detects a collision between two <see cref="SDL_Rect"/> objects
	/// </summary>
	/// <param name="ent1"></param>
	/// <param name="ent2"></param>
	/// <returns>True if a collision is found, false if not</returns>
	bool collision(const SDL_Rect* rect1, const SDL_Rect* rect2);
};

#endif // !GAME_H
