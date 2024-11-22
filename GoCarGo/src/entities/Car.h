#pragma once
#include "base/Entity.h"

namespace game
{
	class Car : public Entity
	{
	protected:
		static const float maxFuel;
		static const float fuelConsumption;

		float speed;
		float fuel;
		float distance;

		float dirX;
		float dirY;

		bool isLeftLane = true;


		void ChangeLane();

		bool CheckCollision(Entity *other);
		void GetHit();

		void AddFuel(float toAdd);
		void RemoveFuel(float toRemove);

	public:

		Car(const std::string textureName, int frames, int frameIndex, 
			float widthScale, float heightScale, float speed, float fuel);

		virtual void Input() override;
		virtual void Update() override;
		virtual void Draw(RenderWindow& window) override;
	};
}