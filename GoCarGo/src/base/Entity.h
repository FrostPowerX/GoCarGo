#pragma once

#include <SFML/Graphics.hpp>

#define GETTER_SETTER(type, field) inline type Get##field() { return (field);}; \
				inline void Set##field(type Var) { (field) = Var;};

#include <string>

using namespace sf;

namespace game
{
	class Entity
	{
	protected:

		Sprite sprite;

	public:

		Entity(const std::string textureName, int frames, int frameIndex);
		virtual ~Entity();

		virtual void Input() = 0;
		virtual void Update() = 0;
		virtual void Draw(RenderWindow& window);

		virtual Vector2f GetPosition();
		virtual Vector2f GetSize();
		virtual FloatRect GetRect();

		virtual void SetRotation(float angle);
		virtual void SetFrame(int frameIndex);
	};
}

