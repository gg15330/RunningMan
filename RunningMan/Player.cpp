#include "Player.h"


constexpr float MAX_HORIZONTAL_SPEED = 2.0f;


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
	case LEFT:		updateVel(Vector2{ -1.0f, 0.0f }); break;
	case RIGHT:		updateVel(Vector2{ 1.0f, 0.0f }); break;
	case UP:		updateVel(Vector2{ 0.0f, -1.0f }); break;
	case DOWN:		updateVel(Vector2{ 0.0f, 1.0f }); break;
	default:		break;
	}
	//updatePos();
}

void Player::updatePos()
{
	getSprite()->getDestRect()->x += _velocity.x;
	getSprite()->getDestRect()->y += _velocity.y;
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
	if (acceleration.x < 0)
	{
		_velocity.x = std::max((_velocity.x + acceleration.x), -(MAX_HORIZONTAL_SPEED));
	}
	else if (acceleration.x > 0)
	{
		_velocity.x = std::min((_velocity.x + acceleration.x), MAX_HORIZONTAL_SPEED);
	}
	_velocity.y += acceleration.y;
}

bool Player::jumping() const noexcept
{
	return _jumping;
}

void Player::setJumping(bool jumping)
{
	_jumping = jumping;
}
