#pragma once

#include <SFML/Graphics.hpp>

class Entity
{

	Sprite sprite;

public:

	virtual ~Entity();

	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

