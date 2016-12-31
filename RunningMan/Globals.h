#pragma once

#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals
{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const int PLAYER_SPRITE_WIDTH = 16;
	const int PLAYER_SPRITE_HEIGHT = 16;
	const int PIXEL_SCALE = 2;
	char* const PLAYER_SPRITE_FILEPATH = "resources/MyChar.png";

	typedef enum Character
	{
		PLAYER, NONE
	} Character;
}

#endif // !GLOBALS_H