#pragma once
#include "base/Entity.h"

namespace game
{
	enum class Power{None};

	class Car : public Entity
	{
	private:
		float feul;
		float distance;
		Power activePower;
		bool isLeftLane = true;

		void Input() override;

		void ChangeLane();

		bool CheckCollision(Entity *other);

		void GetHit();

		void AddFeul();

	public:

		Car(const Texture& texture, int width, int height, float feul);

		void Input(int joystick = 0);
		void Update() override;
		void Draw() override;

		Vector2f GetPosition() override;
		Vector2f GetSize() override;
		Rect<float>& GetRect() override;

		GETTER_SETTER(Power, activePower);

	};
}