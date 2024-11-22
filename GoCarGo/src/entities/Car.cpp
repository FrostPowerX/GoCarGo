#include "Car.h"

#include "utilities/MyTime.h"



namespace game
{
	const float Car::maxFuel = 100.f;
	const float Car::fuelConsumption = 1.f;

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
		RemoveFuel(fuelPenalty);
	}

	void Car::AddFuel(float toAdd)
	{
		fuel = (fuel + toAdd > maxFuel? fuel : fuel + toAdd);
	}

	void Car::RemoveFuel(float toRemove)
	{
		fuel = (fuel - toRemove < 0 ? 0 : fuel - toRemove);
	}

	void Car::Input(int joystick)
	{
		const float fuelPenalty = 0.5f;
		float inputDir;

		if (Joystick::isConnected(joystick))
		{
			inputDir = Joystick::getAxisPosition(joystick, Joystick::PovX);
			if (inputDir < FLT_EPSILON && inputDir > -FLT_EPSILON)
				ChangeLane();

			inputDir = Joystick::getAxisPosition(joystick, Joystick::PovY);
			if (inputDir > FLT_EPSILON)
			{
				// AccelBackground()
				RemoveFuel(fuelPenalty * MyTime::Instance().GetdeltaTime());
			}
			else if (inputDir < -FLT_EPSILON)
			{
				// DeacccelBackground()
			}


		}
		else
		{
			if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D))
				ChangeLane();
			else if (Keyboard::isKeyPressed(Keyboard::W))
			{
				// AccelBackground()
				RemoveFuel(fuelPenalty * MyTime::Instance().GetdeltaTime());
			}
			else if (Keyboard::isKeyPressed(Keyboard::S))
			{
				// DeacccelBackground()
			}
		}
	}

	void Car::Update()
	{
		RemoveFuel(fuelConsumption * MyTime::Instance().GetdeltaTime());
	}

}