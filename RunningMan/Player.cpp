#include "Player.h"


Player::Player(SDL_Renderer* renderer,
	const char* filePath,
	int sourceX,
	int sourceY,
	int width,
	int height,
	int posX,
	int posY) :
	_sprite(Sprite(renderer, filePath, sourceX, sourceY, width, height, posX, posY))
{
}


Player::~Player()
{
}

void Player::updatePos(int x, int y)
{
	_sprite.updateDestRect(x, y);
}

Sprite* Player::getSprite()
{
	return &_sprite;
}
