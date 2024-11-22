#pragma once

#include <SFML/Graphics.hpp>

#define GETTER_SETTER(type, field) inline type Get##field() { return (field);}; \
				inline void Set##field(type Var) { (field) = Var;};

using namespace sf;

class Entity
{
protected:

	Sprite sprite;

public:

	virtual ~Entity();

	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

};

