#include "Scene.h"

game::Scene::~Scene()
{
	for (int i = 0; i < allEntities.size(); i++)
	{
		delete allEntities[i];
	}
}
