#pragma once

#ifndef RENDERER_H

#include <list>

class Sprite;

class Renderer
{
public:
	Renderer();
	~Renderer();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="graphic"></param>
	void registerGraphic(Sprite &sprite);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="sprite"></param>
	void unRegisterSprite(Sprite &sprite);

	/// <summary>
	/// 
	/// </summary>
	void clear();

private:
	std::list<Sprite*> _sprites;
};

#endif // !RENDERER_H
