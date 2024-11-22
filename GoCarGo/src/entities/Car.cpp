#include "Car.h"



namespace game
{
	const float Car::maxFuel = 100.f;

	Car::Car(const Texture& texture, int width, int height, float fuel)
	{
		sprite = Sprite(texture, {0,0,width,height});
		activePower = Power::None;
		distance = 0;
		this->fuel = fuel;

	}

	void Car::Input(){}

	void Car::ChangeLane()
	{
		isLeftLane = !isLeftLane;
	}

	bool Car::CheckCollision(Entity *other)
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
		fuel = (fuel - fuelPenalty < 0 ? 0 : fuel - fuelPenalty);
	}

	void Car::AddFuel(float toAdd)
	{
		fuel = (fuel + toAdd > maxFuel? fuel : fuel + toAdd);
	}




}