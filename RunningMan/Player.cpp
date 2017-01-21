#include "Player.h"


Player::Player()
{
}


Player::Player(Sprite const & sprite, bool passable = false) :
	Entity		{ sprite, passable },
	_jumping	{ false }
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

bool Player::getJumping() const noexcept
{
	return _jumping;
}

void Player::setJumping(bool jumping)
{
	_jumping = jumping;
}
