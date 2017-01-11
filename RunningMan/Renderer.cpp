#include "Renderer.h"


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::registerGraphic(Sprite &sprite)
{
	_sprites.push_front(&sprite);
}

void Renderer::unRegisterSprite(Sprite & sprite)
{
	_sprites.remove(&sprite);
}

void Renderer::clear()
{
	_sprites.clear();
}
