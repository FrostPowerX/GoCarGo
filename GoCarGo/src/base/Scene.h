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

		virtual void Input() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;

		virtual void DeInit() = 0;

	};
}

