#include "Player.h"


Player::Player() : 
	Entity()
{
}

Player::Player(Sprite & const sprite) :
	Entity(sprite)
{
}


Player::~Player()
{
}


void Player::move(Direction direction)
{
	switch (direction)
	{
	case LEFT:		_sprite.getDestRect()->x--; break;
	case RIGHT:		_sprite.getDestRect()->x++; break;
	case UP:		_sprite.getDestRect()->y--; break;
	case DOWN:		_sprite.getDestRect()->y++; break;
	default:		break;
	}
	//std::string s = getDestRect();
	//std::cout << "coords: " << s;
}
