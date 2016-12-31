#include "Game.h"
#include <SDL.h>
#include <iostream>

int main(int argc, char** argv)
{
	Game game;
	game.init();
	game.gameLoop();
	return EXIT_SUCCESS;
}