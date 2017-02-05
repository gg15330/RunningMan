#include "Input.h"

#include <iostream>


Input::Input()
{
}


Input::~Input()
{
}


void Input::clearKeyArrays() 
{
	_pressedKeys.clear();
	_releasedKeys.clear();
}

void Input::processEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			std::cout << "KEYDOWN: " << event.key.keysym.scancode << "\n";
			_pressedKeys[event.key.keysym.scancode] = true;
			_heldKeys[event.key.keysym.scancode] = true;
			break;
		case SDL_KEYUP:
			_heldKeys[event.key.keysym.scancode] = false;
			_releasedKeys[event.key.keysym.scancode] = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			std::cout << "MOUSEDOWN\n";
			break;
		case SDL_QUIT:
			std::cout << "QUIT\n";
			break;
		default:
			break;
		}
	}
}

bool Input::pressed(SDL_Scancode key)
{
	return _pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key)
{
	return false;
}

bool Input::held(SDL_Scancode key)
{
	return _heldKeys[key];
}
