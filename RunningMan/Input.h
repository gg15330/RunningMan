#pragma once

#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

#include <map>


/// <summary>
/// Processes and keeps track of player input
/// </summary>
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
	void processEvents();

	/// <summary>
	/// Checks if a particular key was pressed
	/// </summary>
	/// <param name="key">The SDL_Scancode of the key to check</param>
	/// <returns>True if pressed, False if not</returns>
	bool pressed(SDL_Scancode key);
	
	/// <summary>
	/// Checks if a particular key was released
	/// </summary>
	/// <param name="key">The SDL_Scancode of the key to check</param>
	/// <returns>True if released, False if not</returns>
	bool released(SDL_Scancode key);

	/// <summary>
	/// Checks if a particular key is currently being held
	/// </summary>
	/// <param name="key">The SDL_Scancode of the key to check</param>
	/// <returns>True if held, False if not</returns>
	bool held(SDL_Scancode key);

private:
	std::map<SDL_Scancode, bool> _heldKeys;
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;
};

#endif // !INPUT_H
