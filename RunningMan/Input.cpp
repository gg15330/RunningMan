#include "Input.h"

#include <iostream>

Input::Input()
{
}


Input::~Input()
{
}


void Input::clearKeyArrays() {
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

void Input::processEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			std::cout << "KEYDOWN\n";
			this->_pressedKeys[event.key.keysym.scancode] = true;
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

bool Input::wasKeyPressed(SDL_Scancode key)
{
	return this->_pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key)
{
	return false;
}

bool Input::isKeyHeld(SDL_Scancode key)
{
	return false;
}
