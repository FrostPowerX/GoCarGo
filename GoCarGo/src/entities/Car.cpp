#include "Car.h"

#include "utilities/MyTime.h"

#include <iostream>

namespace game
{
	const float Car::maxFuel = 100.f;
	const float Car::fuelConsumption = 1.f;

	Car::Car(const std::string textureName, int frames, int frameIndex, float widthScale, float heightScale, float speed, float fuel) :
		Entity(textureName, frames, frameIndex)
	{
		sprite.setScale({ widthScale, heightScale });

		distance = 0;
		this->fuel = fuel;

		dirX = 0;
		dirY = 0;

		this->speed = speed;
	}

	void Car::Input()
	{
		
	}

	void Car::Update()
	{
		sprite.move(Vector2f{dirX, dirY} * MyTime::Instance().GetdeltaTime() * speed);
		RemoveFuel(fuelConsumption * MyTime::Instance().GetdeltaTime());
	}

	void Car::Draw(RenderWindow& window)
	{
		Entity::Draw(window);
	}

	void Car::ChangeLane()
	{
		isLeftLane = !isLeftLane;
	}

	bool Car::CheckCollision(Entity* other)
	{
		if (other)
		{
			return other->GetRect().intersects(sprite.getGlobalBounds());
		}
		return false;
	}

	void Car::GetHit()
	{
		const float fuelPenalty = 20.f;
		RemoveFuel(fuelPenalty);
	}

	void Car::AddFuel(float toAdd)
	{
		fuel = (fuel + toAdd > maxFuel ? fuel : fuel + toAdd);
	}

	void Car::RemoveFuel(float toRemove)
	{
		fuel = (fuel - toRemove < 0 ? 0 : fuel - toRemove);
	}

}