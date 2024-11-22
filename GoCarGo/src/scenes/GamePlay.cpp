#include "GamePlay.h"

#include "GameLoop.h"

game::GamePlay::GamePlay()
{
	player = nullptr;
	isPause = false;
}

void game::GamePlay::Init()
{
	player = new Player("Carsito", "Cars", 5, 0, 1, 1, 100, 100);

	obstacle = new Obstacle({ static_cast<float>(rand() % 801 + 1), 600.f }, "Cars", 5, 0, 1, 1, 200, 1000); //TODO REMOVE MAGIC

	allEntities.push_back(player);

	allEntities.push_back(obstacle);

	isPause = false;
}

void game::GamePlay::Input()
{
	if (!isPause)
	{
		Scene::Input();
	}


	if (GameLoop::Instance().GetEvent().type == Event::KeyReleased)
		if (GameLoop::Instance().GetEvent().key.scancode == Keyboard::Scan::Scancode(Keyboard::P))
			isPause = !isPause;

	if (Keyboard::isKeyPressed(Keyboard::M))
		GameLoop::Instance().ChangeScene(0);
}

void game::GamePlay::Update()
{
	if (!isPause)
	{
		Scene::Update();
	}
}

void game::GamePlay::Draw(RenderWindow& window)
{
	Scene::Draw(window);

	if (isPause)
	{
		Text text;
		text.setString("Pause");

		Vector2f pos = static_cast<Vector2f>(window.getSize());

		pos *= 0.5f;

		text.setPosition(pos);
		text.setFillColor(Color::White);
		text.setPosition(300,300);
		window.draw(text);
	}
}

void game::GamePlay::DeInit()
{
	Scene::DeInit();
}
