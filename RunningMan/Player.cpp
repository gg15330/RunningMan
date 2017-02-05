#include "Player.h"


constexpr float WALK_SPEED = 2.0f;


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


void Player::move(Direction direction)
{
	switch (direction)
	{
	case LEFT:	_velocity.x = -WALK_SPEED; break;
	case RIGHT:	_velocity.x = WALK_SPEED; break;
	case UP:	break;
	case DOWN:	break;
	default:	break;
	}
}

void Player::update(int timeElapsed)
{
	sprite()->updateDestRect(_velocity);
}

void Player::accelerate(const Vector2& acceleration)
{
	if (acceleration.x < 0)
	{
		_velocity.x = std::max((_velocity.x + acceleration.x), -(WALK_SPEED));
	}
	else if (acceleration.x > 0)
	{
		_velocity.x = std::min((_velocity.x + acceleration.x), WALK_SPEED);
	}
}

void Player::stop()
{
	_velocity.x = 0;
}

bool Player::jumping() const noexcept
{
	return _jumping;
}

Vector2 Player::position() const noexcept
{
	return _position;
}

Vector2 Player::velocity() const noexcept
{
	return _velocity;
}

void Player::setJumping(bool jumping)
{
	_jumping = jumping;
}
