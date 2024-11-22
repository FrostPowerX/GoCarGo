#include "MainMenu.h"

#include "entities/Car.h"

void game::MainMenu::Init()
{
	Car* cacho = new Car("Cars", 5, 0, 2.f, 2.f, 100.f);

	allEntities.push_back(cacho);
}

//void game::MainMenu::Input()
//{
//
//}

//void game::MainMenu::Update()
//{
//
//}

//void game::MainMenu::Draw(RenderWindow& window)
//{
//
//}

void game::MainMenu::DeInit()
{

}
