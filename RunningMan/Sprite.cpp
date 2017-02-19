#include "Sprite.h"


Sprite::Sprite()
{
}

Sprite::Sprite(SDL_Renderer* renderer, const char* const filePath, const float sourceX, const float sourceY, const int width, const int height, const float posX, const float posY)
{
	//std::cout << "Creating Sprite: " << this << std::endl;
	//_sourceRect = SDL_Rect 
	//{ 
	//	roundToInt(sourceX), 
	//	roundToInt(sourceY), 
	//	width, 
	//	height 
	//};
	//_destRect = SDL_Rect
	//{ 
	//	roundToInt(posX), 
	//	roundToInt(posY), 
	//	width, 
	//	height 
	//};
	//loadTexture(filePath, renderer);
}


Sprite::~Sprite()
{
}
