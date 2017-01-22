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


void Player::updatePos()
{
	_sprite.getDestRect()->x += _velocity.x;
	_sprite.getDestRect()->y += _velocity.y;
}

bool Player::jumping() const noexcept
{
	return _jumping;
}

void Player::setJumping(bool jumping)
{
	_jumping = jumping;
}
