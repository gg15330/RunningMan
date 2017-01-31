#include "Player.h"


Player::Player()
{
}


Player::Player(Sprite const & sprite, bool passable = false) :
	Entity		{ sprite, passable },
	_jumping	{ false },
	_velocity	{ Vector2 {0, 0} }
{
}


Player::~Player()
{
}


void Player::updatePos()
{
	_sprite.getDestRect()->x += static_cast<int>(_velocity.x);
	_sprite.getDestRect()->y += static_cast<int>(_velocity.y);
}

Vector2 Player::velocity() const noexcept
{
	return _velocity;
}

void Player::updateVel(const Vector2 velocity)
{
	_velocity = velocity;
}

bool Player::jumping() const noexcept
{
	return _jumping;
}

void Player::setJumping(bool jumping)
{
	_jumping = jumping;
}
