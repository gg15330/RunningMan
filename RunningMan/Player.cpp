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
	if (_grounded)
	{
		_dy = 0.0f;
	}
	else if (_dy <= globals::GRAVITY_CAP) 
	{
		_dy += globals::GRAVITY * timeElapsed;
	}
	_prevX = _x;
	_prevY = _y;
	_x += _dx * timeElapsed;
	_y += _dy * timeElapsed;
}

void Player::stop()
{
	_dx = 0.0f;
}

bool Player::grounded() noexcept
{
	return _grounded;
}

void Player::setGrounded(bool grounded)
{
	_grounded = grounded;
}

void Player::handleTileCollisions(std::vector<Entity*> others) 
{
	for each (Entity* other in others)
	switch (collisionSide(other))
	{
	case UP:
		_dy = 0;
		_y = other->y() + 1;
		if (_grounded)
		{
			_dx = 0;
		}
		break;
	case DOWN:
		_y = other->y() - sprite()->getDestRect()->h - 1;
		_dy = 0;
		_grounded = true;
		break;
	case LEFT:
		_x = (other->x() + other->w())+ 1;
		break;
	case RIGHT:
		_x = other->x() - sprite()->getDestRect()->w - 1;
		break;
	}
}

Direction Player::collisionSide(Entity* entity) const
{
	float wy, hx;
	const SDL_Rect* playerRect = _sprite.getDestRect();
	if (SDL_HasIntersection(playerRect, entity->sprite()->getDestRect()))
	{
		wy = (0.5f * (playerRect->w + entity->w())) * ((playerRect->y + (0.5f * playerRect->h)) - (entity->y() + (0.5f * entity->h())));
		hx = (0.5f * (playerRect->h + entity->h())) * ((playerRect->x + (0.5f * playerRect->w)) - (entity->x() + (0.5f * entity->w())));
		return (wy > hx) ? ((wy > -hx) ? UP : LEFT) : ((wy > -hx) ? RIGHT : DOWN);
	}
	return NONE;
}
