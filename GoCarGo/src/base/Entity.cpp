#include "Entity.h"

void Entity::Draw()
{
	// RenderWindow::draw(sprite);
}

Vector2f Entity::GetPosition()
{
	return {sprite.getGlobalBounds().left, sprite.getGlobalBounds().top};
}

Vector2f Entity::GetSize()
{
	return {sprite.getGlobalBounds().width, sprite.getGlobalBounds().height};
}

FloatRect Entity::GetRect()
{
	return sprite.getGlobalBounds();
}