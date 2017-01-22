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


void Player::move()
{
	_sprite.getDestRect()->x += _velocity.x;
	_sprite.getDestRect()->y += _velocity.y;
}

bool Player::getJumping() const noexcept
{
	return _jumping;
}

void Player::setJumping(bool jumping)
{
	_jumping = jumping;
}
