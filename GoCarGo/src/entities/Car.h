#pragma once
#include "base/Entity.h"

namespace game
{
	enum class Power{None};

	class Car : public Entity
	{
	private:
		static const float maxFuel;
		static const float fuelConsumption;


		float speed;
		float fuel;
		float distance;

		Power activePower;

		Vector2f direction;

		bool isLeftLane = true;


		void ChangeLane();

		bool CheckCollision(Entity *other);
		void GetHit();

		void AddFuel(float toAdd);
		void RemoveFuel(float toRemove);

	public:

		Car(const std::string textureName, int frames, int frameIndex, float widthScale, float heightScale, float fuel);

		//void Input(int joystick = 0);
		void Input() override;
		void Update() override;

		GETTER_SETTER(Power, activePower);

	};
}