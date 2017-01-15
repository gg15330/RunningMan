#include "Player.h"


Player::Player() : 
	Entity()
{
}

Player::Player(Sprite & const sprite, int x, int y) :
	Entity(sprite, x, y)
{
}

Player::Player(SDL_Renderer* renderer, const char* filePath, int sourceX, int sourceY, int width, int height, int posX, int posY) :
	Entity(renderer, filePath, 0, 0, globals::PLAYER_SPRITE_WIDTH, globals::PLAYER_SPRITE_HEIGHT, 0, 0)
{
}


Player::~Player()
{
}


void Player::move(Direction direction)
{
	switch (direction)
	{
	case LEFT:		_sprite.updateDestRect(--_x, _y); break;
	case RIGHT:		_sprite.updateDestRect(++_x, _y); break;
	case UP:		_sprite.updateDestRect(_x, --_y); break;
	case DOWN:		_sprite.updateDestRect(_x, ++_y); break;
	default:		break;
	}
}
