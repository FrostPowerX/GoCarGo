#pragma once

#include <vector>

#include "Entity.h"

using namespace std;

namespace game
{
	class Scene
	{
	protected:

		vector<Entity*> allEntities;

	public:

		virtual ~Scene();

		virtual void Init() = 0;

		virtual void Input();
		virtual void Update();
		virtual void Draw(RenderWindow& window);

		virtual void DeInit() = 0;

	};
}

