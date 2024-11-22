#pragma once

#include "base/Singleton.h"

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "scenes/MainMenu.h"
#include "scenes/GamePlay.h"

using namespace std;
using namespace sf;

namespace game
{
	class GameLoop : public Singleton<GameLoop>
	{
	private:

		friend Singleton<GameLoop>; // Rompe todo el encapsulamiento xd

		int width;
		int height;

		string title;

		RenderWindow window;

		Scene* currentScene;

		vector<Scene*> scenes;

		Event event;

		bool onLoop;

		void Init();

		void Input();
		void Update();
		void Draw();

		void DeInit();

		void AddScene(Scene* scene);

	public:

		GameLoop();
		~GameLoop();

		void Play();

		void ChangeScene(int scene);

		Event GetEvent();
	};
}

