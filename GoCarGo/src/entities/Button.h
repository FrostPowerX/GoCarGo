#pragma once
#include <SFML/Graphics.hpp>
#define GETTER_SETTER(type, field) inline type Get##field() { return (field);}; \
									inline void Set##field(type Var) { (field) = Var;};

namespace game
{
	class Button
	{
	private:

		sf::RectangleShape body;
		bool isOnTop;
		bool wasOnTop;


	public:

		Button(const sf::RectangleShape& body);
		~Button();

		bool HasBeenClick(const sf::Mouse& mouse);

		GETTER_SETTER(bool, isOnTop)
		GETTER_SETTER(bool, wasOnTop)
	};
}
