#include "Player.h"


constexpr float WALK_SPEED = 0.1f;


Player::Player()
{
}


Player::Player(Sprite const & sprite, bool passable = false) :
	Entity		{ sprite, passable },
	_grounded	{ false }
{
}


Player::~Player()
{
}


void Player::move(Direction direction)
{
	switch (direction)
	{
	case LEFT:	_dx = -WALK_SPEED; break;
	case RIGHT:	_dx = WALK_SPEED; break;
	default:	break;
	}
}

void Player::update(int timeElapsed)
{
	if (!_grounded && _dy <= globals::GRAVITY_CAP) {
		_dy += globals::GRAVITY * timeElapsed;
	}
	_x += _dx * timeElapsed;
	_y += _dy * timeElapsed;
}

void Player::stop()
{
	_dx = 0.0f;
}

bool Player::grounded() const noexcept
{
	return _grounded;
}

void Player::setGrounded(bool grounded)
{
	_grounded = grounded;
}
