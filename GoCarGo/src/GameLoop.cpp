#include "GameLoop.h"

#include "utilities/MyTime.h"

#include "managers/SpriteManager.h"
#include "managers/SoundManager.h"

namespace game
{
	void GameLoop::Init()
	{
		SoundManager::Instance().LoadSounds();
		SpriteManager::Instance().LoadSprites();

		if (currentScene)
			currentScene->Init();
	}

	void GameLoop::Input()
	{
		currentScene->Input();
	}

	void GameLoop::Update()
	{
		currentScene->Update();
	}

	void GameLoop::Draw()
	{
		window.clear();

		currentScene->Draw(window);

		window.display();
	}

	void GameLoop::DeInit()
	{
		currentScene->DeInit();
	}

	void GameLoop::AddScene(Scene* scene)
	{
		scenes.push_back(scene);
	}

	void GameLoop::ChangeScene(int index)
	{
		if (index >= 0 && index < scenes.size())
		{
			if (currentScene)
				currentScene->DeInit();

			currentScene = scenes[index];

			currentScene->Init();
		}
	}

	GameLoop::GameLoop()
	{
		width = 800;
		height = 600;

		title = "GoCarGo";

		window.create(VideoMode(width, height), title);

		MainMenu* menu = new MainMenu();
		GamePlay* gamePlay = new GamePlay();

		currentScene = menu;

		scenes.push_back(menu);
		scenes.push_back(gamePlay);

		onLoop = true;
	}

	GameLoop::~GameLoop()
	{
		for (int i = 0; i < scenes.size(); i++)
		{
			scenes[i]->DeInit();

			delete scenes[i];
		}
	}

	void GameLoop::Play()
	{
		Init();

		while (onLoop && window.isOpen())
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				onLoop = false;

			if (currentScene)
			{
				MyTime::Instance().Start();

				Event event;
				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
						window.close();
				}

				Input();
				Update();
				Draw();

				MyTime::Instance().Stop();
			}
			else
				cout << "Error: Scene not setted or not exist.\n";
		}

		DeInit();
	}
}
