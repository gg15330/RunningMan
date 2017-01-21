#include "Player.h"


Player::Player()
{
}


Player::Player(Sprite const & sprite, bool passable = false) :
	Entity{ sprite, passable }
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
