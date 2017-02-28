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

	void operator+(const Vector2& v)
	{
		*this += v;
	}

	void operator+=(const Vector2& v)
	{
		x += v.x; 
		y += v.y;
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
	const float GRAVITY								= 0.01f;
	const float GRAVITY_CAP							= 0.1f;
	const float WALKING_ACCELERATION				= 0.0018f;
	const float MAX_SPEED							= 0.4f;
	const float SLOWDOWN_FACTOR						= 0.98f;

	//Player
	const char* const PLAYER_SPRITE_FILEPATH		= "resources/MyChar.png";
	const Vector2 PLAYER_SOURCE_POS					{ 0.0f, 0.0f };
	const Vector2 PLAYER_STARTING_POS				{ 0.0f, 150.0f };
	const float PLAYER_SPRITE_WIDTH					= 16.0f;
	const float PLAYER_SPRITE_HEIGHT					= 16.0f;

	//Platform
	const char* const PLATFORM_SPRITE_FILEPATH		= "resources/Platform.png";
	const Vector2 PLATFORM_SOURCE_POS				{ 480.0f, 0.0f };
	const float PLATFORM_SPRITE_WIDTH					= 95.0f;
	const float PLATFORM_SPRITE_HEIGHT				= 63.0f;
	const Vector2 PLATFORM_STARTING_POS				{ 0.0f, 400.0f };
}

/// <summary>
/// Enum representing movement direction
/// </summary>
enum Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	NONE
};

#endif // !GLOBALS_H