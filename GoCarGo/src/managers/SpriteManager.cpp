#include "SpriteManager.h"

namespace game 
{
		void SpriteManager::AddSprite(std::string name, std::string path)
		{
			SpriteBox* newSpriteBox = new SpriteBox();
			newSpriteBox->name = name;
			newSpriteBox->texture.loadFromFile(name);

			spriteBoxes.push_back(newSpriteBox);
		}

		SpriteBox* SpriteManager::GetSprite(std::string name)
		{
			if (spriteBoxes.size() <= 0)
				return nullptr;

			for (int i = 0; i < static_cast<int>(spriteBoxes.size()); i++)
			{
				if (name == spriteBoxes[i]->name)
					return spriteBoxes[i];
			}

			return nullptr;
		}

		SpriteManager::~SpriteManager()
		{
			for (int i = 0; i < spriteBoxes.size(); i++)
			{
				delete spriteBoxes[i];
			}
		}

		void SpriteManager::LoadSprites()
		{
			
		}

}
