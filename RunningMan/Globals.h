#pragma once

#ifndef GLOBALS_H
#define GLOBALS_H


/// <summary>
/// Struct for coordinates
/// </summary>
struct Vector2 {
	float x, y;
	
	Vector2()
	{
	}
	
	Vector2(float x, float y) :
		x(x), y(y)
	{
	}

	Vector2 operator+(const Vector2& v)
	{
		return *this += v;
	}

	Vector2 operator+=(const Vector2& v)
	{
		return { (x + v.x), (y + v.y) };
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
	const int PIXEL_SCALE							= 2;

	//Physics
	const Vector2 GRAVITY							{ 0.0f, 1.0f };
	const float GRAVITY_CAP							= 10.0f;

	//Player
	const char* const PLAYER_SPRITE_FILEPATH		= "resources/MyChar.png";
	const Vector2 PLAYER_SOURCE_POS					{ 0.0f, 0.0f };
	const Vector2 PLAYER_STARTING_POS				{ 250.0f, 150.0f };
	const int PLAYER_SPRITE_WIDTH					= 16;
	const int PLAYER_SPRITE_HEIGHT					= 16;

	//Platform
	const char* const PLATFORM_SPRITE_FILEPATH		= "resources/Platform.png";
	const Vector2 PLATFORM_SOURCE_POS				{ 480.0f, 0.0f };
	const Vector2 PLATFORM_STARTING_POS				{ 100.0f, 100.0f };
	const int PLATFORM_SPRITE_WIDTH					= 95;
	const int PLATFORM_SPRITE_HEIGHT				= 63;
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