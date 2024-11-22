#include "Scene.h"

game::Scene::~Scene()
{
	for (auto entity : allEntities)
	{
		delete entity;
	}
}

void game::Scene::Input()
{
	for (auto entity : allEntities)
	{
		entity->Input();
	}
}

void game::Scene::Update()
{
	for (auto entity : allEntities)
	{
		entity->Update();
	}
}

void game::Scene::Draw(RenderWindow& window)
{
	for (auto entity : allEntities)
	{
		entity->Draw(window);
	}
}

void game::Scene::DeInit()
{
	for (auto entity : allEntities)
	{
		delete entity;
	}

	allEntities.clear();
}
