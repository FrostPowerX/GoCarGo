#include "Button.h"

Button::Button(const sf::RectangleShape& body)
{
	this->body = body;
}

Button::~Button() = default;

bool Button::HasBeenClick(const sf::Mouse& mouse)
{
	sf::Vector2i mousePos;

	if (mouse.isButtonPressed(sf::Mouse::Button::Left))
	{
		mousePos = mouse.getPosition();

		//check if its over button
		if (body.getPosition().x <= mousePos.x && body.getPosition().x + body.getSize().x >= mousePos.x &&
			body.getPosition().y <= mousePos.y && body.getPosition().y + body.getSize().y >= mousePos.y)
		{
			return true;
		}
	}

	return false;
}