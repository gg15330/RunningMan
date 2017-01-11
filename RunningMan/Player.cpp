#include "Player.h"


Player::Player(SDL_Renderer* renderer, const char* filePath, int sourceX, int sourceY, int width, int height, int posX, int posY) :
	Sprite(renderer, filePath, sourceX, sourceY, width, height, posX, posY)
{
}


Player::~Player()
{
}

void Player::updatePos(int x, int y)
{
	updateDestRect(x, y);
}

