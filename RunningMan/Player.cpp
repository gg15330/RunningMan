#include "Player.h"


Player::Player()
{
}


Player::Player(SDL_Renderer* renderer, const char* const filePath, const float sourceX, const float sourceY, const float width, const float height, const float posX, const float posY) :
	Entity(renderer, filePath, sourceX, sourceY, width, height, posX, posY),
	_grounded(false),
	_jumping(false)
{
}


Player::~Player()
{
}


void Player::move(Direction direction)
{
	switch (direction)
	{
	case LEFT:	_ax = -globals::WALKING_ACCELERATION; break;
	case RIGHT:	_ax = globals::WALKING_ACCELERATION; break;
	default:	break;
	}
}

void Player::update(int timeElapsed)
{
	//horizontal movement
	_x += (_dx * timeElapsed);
	_dx += (_ax * timeElapsed);
	if (_ax < 0.0f)
	{
		_dx = std::max(_dx, -globals::MAX_HORIZONTAL_SPEED);
	}
	else if (_ax > 0.0f)
	{
		_dx = std::min(_dx, globals::MAX_HORIZONTAL_SPEED);
	}
	else
	{
		_dx *= globals::SLOWDOWN_FACTOR;
	}

	//vertical movement
	_y += _dy * timeElapsed;
	_dy = std::min(_dy + (globals::GRAVITY * timeElapsed), globals::MAX_VERTICAL_SPEED);
}

void Player::stop()
{
	_ax = 0.0f;
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
	bool temp = false;
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
		_y = other->y() - getDestRect()->h - 1;
		_dy = 0;
		std::cout << "Grounded: " << _grounded << "Jumping: " << _jumping << std::endl;
		_grounded = true;
		break;
	case LEFT:
		_x = (other->x() + other->w()) + 1;
		break;
	case RIGHT:
		_x = other->x() - getDestRect()->w - 1;
		break;
	case NONE:
		break;
	default:
		break;
	}
}

void Player::startJump()
{
	if (_grounded && !_jumping)
	{
		std::cout << "Starting jump" << std::endl;
		_dy = -globals::JUMP_SPEED;
		_grounded = false;
		_jumping = true;
	}
}

void Player::stopJump()
{
	if (_dy < -(0.25f))
	{
		_dy = -(0.25f);
	}
	_jumping = false;
}

Direction Player::collisionSide(Entity* entity)
{
	float wy, hx;
	const SDL_Rect* playerRect = getDestRect();
	if (collisionDetected(entity))
	{
		wy = (0.5f * (playerRect->w + entity->w())) * ((playerRect->y + (0.5f * playerRect->h)) - (entity->y() + (0.5f * entity->h())));
		hx = (0.5f * (playerRect->h + entity->h())) * ((playerRect->x + (0.5f * playerRect->w)) - (entity->x() + (0.5f * entity->w())));
		return (wy > hx) ? ((wy > -hx) ? UP : LEFT) : ((wy > -hx) ? RIGHT : DOWN);
	}
	return NONE;
}
