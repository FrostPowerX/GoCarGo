#pragma once

class Entity
{
public:

	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

