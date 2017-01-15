#include "Player.h"


Player::Player()
{
}

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

void Player::move(Direction direction)
{
	switch (direction)
	{
	case LEFT:		updateDestRect(--_x, _y); break;
	case RIGHT:		updateDestRect(++_x, _y); break;
	case UP:		updateDestRect(_x, --_y); break;
	case DOWN:		updateDestRect(_x, ++_y); break;
	default:		break;
	}
}

