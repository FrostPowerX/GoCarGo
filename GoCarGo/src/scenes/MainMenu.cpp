#include "MainMenu.h"

#include "entities/Car.h"

#include "GameLoop.h"

void game::MainMenu::Init()
{

}

void game::MainMenu::Input()
{
	Scene::Input();

	if (Keyboard::isKeyPressed(Keyboard::Space))
		GameLoop::Instance().ChangeScene(1);
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
	Scene::DeInit();
}
