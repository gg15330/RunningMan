#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "Globals.h"
#include "Sprite.h"

#include <SDL.h>


/// <summary>
/// Abstract class representing a game entity
/// </summary>
class Entity
{
public:
	Entity();
	Entity(SDL_Renderer* renderer,
		const char* const filePath,
		const float sourceX,
		const float sourceY,
		const float width,
		const float height,
		const float posX,
		const float posY);
	~Entity();

	/// <summary>
	/// Updates the position of the spritesheet's source rectangle
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void updateSourceRect(int x, int y);

	/// <summary>
	/// Updates the position of the spritesheet's destination rectangle
	/// </summary>
	/// <param name="position"></param>
	void updateDestRect(Vector2 position);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="entity1"></param>
	/// <param name="entity2"></param>
	/// <returns></returns>
	bool collisionDetected(Entity* entity);

	/// <summary>
	/// Returns the sprite's current source SDL_Rect
	/// </summary>
	/// <returns>A pointer to the sprite's current source SDL_Rect</returns>
	SDL_Rect* getSourceRect() noexcept;

	/// <summary>
	/// Returns the sprite's current destination SDL_Rect
	/// </summary>
	/// <returns>A pointer to the sprite's current destination SDL_Rect</returns>
	const SDL_Rect* getDestRect() const noexcept;

	/// <summary>
	/// Get the spritesheet
	/// </summary>
	/// <returns></returns>
	SDL_Texture* getTexture() noexcept;

	/// <summary>
	/// Returns this <see cref="Entity"/>'s <see cref="Sprite"/> object
	/// </summary>
	/// <returns></returns>
	Sprite* sprite() noexcept;

	/// <summary>
	/// Setter for this <see cref="Entity"/>'s Sprite
	/// </summary>
	/// <param name="sprite"></param>
	void setSprite(Sprite const & sprite);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	float x() const noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	float y() const noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	float w() const noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	float h() const noexcept;
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="x"></param>
	void setX(float x);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="y"></param>
	void setY(float y);

protected:
	Sprite _sprite;
	bool _passable;
	float _x, _y, _w, _h, _dx, _dy, _ax, _ay;
	SDL_Texture* _texture;
	SDL_Rect _sourceRect;
	SDL_Rect _destRect;

	/// <summary>
	/// Loads a texture into the renderer
	/// </summary>
	/// <param name="filePath">the file path of the image to create a texture from</param>
	/// <param name="renderer">The SDL_Renderer to load the image to</param>
	void loadTexture(const char* filePath, SDL_Renderer* renderer);

	/// <summary>
	/// Helper function to round floats to int
	/// </summary>
	/// <param name="f"></param>
	/// <returns></returns>
	int roundToInt(const float f);
};

#endif // !ENTITY_H
