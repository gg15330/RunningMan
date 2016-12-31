#pragma once

#include <SDL.h>
#include <map>

class Input
{
public:
	Input();
	~Input();

	/// <summary>
	/// Clears the pressed keys and released keys arrays
	/// </summary>
	void clearKeyArrays();

	/// <summary>
	/// Process all pending SDL Events
	/// </summary>
	/// <param name="event">The SDL Event to be processed</param>
	void processEvents();

	bool wasKeyPressed(SDL_Scancode key);
	bool wasKeyReleased(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key);
private:
	std::map<SDL_Scancode, bool> _heldKeys;
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;
};

