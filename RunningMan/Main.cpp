#include "Game.h"


int main(int argc, char** argv)
{
	Game game;
	game.init();
	game.gameLoop();
	return EXIT_SUCCESS;
}