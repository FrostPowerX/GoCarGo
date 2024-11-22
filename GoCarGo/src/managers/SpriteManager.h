#pragma once

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "base/Singleton.h"

namespace game
{
	struct SpriteBox
	{
		sf::Texture texture;
		std::string name;
	};

	class SpriteManager : public Singleton<SpriteManager>
	{
	private:

		const int textureWidth = 32;
		const int textureHeight = 32;

		std::vector<SpriteBox*> spriteBoxes;

		void LoadSprites();

		void AddSprite(std::string name, std::string path);

	public:

		SpriteBox* GetSprite(std::string name);
		
		~SpriteManager();

	};
}
