#pragma once

class Scene
{
public:

	virtual ~Scene() = 0;

	virtual void Init() = 0;

	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual void DeInit() = 0;

};

