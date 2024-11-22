#include "Entity.h"

#include "managers/SpriteManager.h"

namespace game
{
	Entity::Entity(const std::string textureName, int frames, int frameIndex)
	{
		sprite.setTexture(SpriteManager::Instance().GetSprite(textureName)->texture);

		sf::IntRect newRect;
		newRect = sprite.getTextureRect();

		newRect.width /= frames;
		newRect.left = (frameIndex * newRect.width);

		sprite.setTextureRect(newRect);

	}

	Entity::~Entity() = default;

	void Entity::Draw(RenderWindow& window)
	{
		window.draw(sprite);
	}

	Vector2f Entity::GetPosition()
	{
		return { sprite.getGlobalBounds().left, sprite.getGlobalBounds().top };
	}

	Vector2f Entity::GetSize()
	{
		return { sprite.getGlobalBounds().width, sprite.getGlobalBounds().height };
	}

	FloatRect Entity::GetRect()
	{
		return sprite.getGlobalBounds();
	}
	void Entity::SetRotation(float angle)
	{
		sprite.setRotation(angle);
	}
}