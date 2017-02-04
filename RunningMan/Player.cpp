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
	_position += _velocity;
}

Vector2 Player::position() const noexcept
{
	return _position;
}

Vector2 Player::velocity() const noexcept
{
	return _velocity;
}

void Player::updateVel(const Vector2& acceleration)
{
	_velocity += acceleration;
}

bool Player::jumping() const noexcept
{
	return _jumping;
}

void Player::setJumping(bool jumping)
{
	_jumping = jumping;
}
