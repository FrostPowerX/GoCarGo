#include "MainMenu.h"

#include "entities/Car.h"

void game::MainMenu::Init()
{
	Car* cacho = new Car("Cars", 5, 0, 2.f, 2.f, 500.f, 100.f);

	allEntities.push_back(cacho);
}

void game::MainMenu::Input()
{
	Scene::Input();

}

void game::MainMenu::Update()
{
	Scene::Update();

}

void game::MainMenu::Draw(RenderWindow& window)
{
	Scene::Draw(window);

}

void game::MainMenu::DeInit()
{

}
