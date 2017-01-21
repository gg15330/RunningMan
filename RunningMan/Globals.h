#pragma once

#ifndef GLOBALS_H
#define GLOBALS_H


/// <summary>
/// Struct for coordinates
/// </summary>
struct Vector2 {
	int x, y;
	Vector2()
	{
	}
	Vector2(int x, int y) :
		x(x), y(y)
	{
	}
};

/// <summary>
/// Global constant variables
/// </summary>
namespace globals
{
	//Screen
	const int SCREEN_WIDTH							= 640;
	const int SCREEN_HEIGHT							= 480;

	//Player
	char* const PLAYER_SPRITE_FILEPATH				= "resources/MyChar.png";
	const Vector2 PLAYER_SOURCE_POS					{ 0, 0 };
	const Vector2 PLAYER_STARTING_POS				{ 0, 0 };
	const int PLAYER_SPRITE_WIDTH					= 16;
	const int PLAYER_SPRITE_HEIGHT					= 16;

	//Platform
	char const* const PLATFORM_SPRITE_FILEPATH		= "resources/Platform.png";
	const Vector2 PLATFORM_SOURCE_POS				{ 480, 0 };
	const Vector2 PLATFORM_STARTING_POS				{ 100, 100 };
	const int PLATFORM_SPRITE_WIDTH					= 95;
	const int PLATFORM_SPRITE_HEIGHT				= 63;
	

	const int PIXEL_SCALE							= 2;
}

/// <summary>
/// Enum representing movement direction
/// </summary>
enum Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

#endif // !GLOBALS_H