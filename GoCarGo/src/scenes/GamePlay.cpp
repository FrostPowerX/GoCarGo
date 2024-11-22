#include "GamePlay.h"

#include "GameLoop.h"

game::GamePlay::GamePlay()
{
	player = nullptr;
}

void game::GamePlay::Init()
{
	player = new Player("Carsito", "Cars", 5, 0, 1, 1, 100, 100);

	allEntities.push_back(player);
}

void game::GamePlay::Input()
{
	Scene::Input();

	if (Keyboard::isKeyPressed(Keyboard::M))
		GameLoop::Instance().ChangeScene(0);
}

void game::GamePlay::Update()
{
	Scene::Update();
}

void game::GamePlay::Draw(RenderWindow& window)
{
	Scene::Draw(window);
}

void game::GamePlay::DeInit()
{
	Scene::DeInit();
}
