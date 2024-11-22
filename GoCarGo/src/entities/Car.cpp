#include "Car.h"

#include "utilities/MyTime.h"

#include <iostream>

namespace game
{
	const float Car::maxFuel = 100.f;
	const float Car::fuelConsumption = 1.f;

	Car::Car(const std::string textureName, int frames, int frameIndex, float widthScale, float heightScale, float fuel) :
		Entity(textureName, frames, frameIndex)
	{
		sprite.setScale({ widthScale, heightScale });

		activePower = Power::None;
		distance = 0;
		this->fuel = fuel;

		dirX = 0;
		dirY = 0;

		speed = 500;
	}

	void Car::Input()
	{
		const float fuelPenalty = 0.5f;
		float inputDir;

		std::cout << "Input Car\n";

		dirX = 0;
		dirY = 0;

		if (Joystick::isConnected(0))
		{
			inputDir = Joystick::getAxisPosition(0, Joystick::PovX);
			if (inputDir > FLT_EPSILON)
			{
				dirX = 1;
				//ChangeLane();
			}
			else if (inputDir < -FLT_EPSILON)
			{
				dirX  = 1;
			}
			inputDir = Joystick::getAxisPosition(0, Joystick::PovY);
			if (inputDir > FLT_EPSILON)
			{
				// AccelBackground()
				dirY = -1;
				RemoveFuel(fuelPenalty * MyTime::Instance().GetdeltaTime());
			}
			else if (inputDir < -FLT_EPSILON)
			{
				dirY = 1;
				// DeacccelBackground()
			}


		}
		else
		{
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				dirX = 1;
				//ChangeLane();
			}
			else if (Keyboard::isKeyPressed(Keyboard::D))
			{
				dirX = 1;
			}

			else if (Keyboard::isKeyPressed(Keyboard::W))
			{
				// AccelBackground()
				dirY = -1;
				RemoveFuel(fuelPenalty * MyTime::Instance().GetdeltaTime());
			}
			else if (Keyboard::isKeyPressed(Keyboard::S))
			{
				dirY = 1;
				// DeacccelBackground()
			}
		}
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

	//void Car::Input(int joystick)
	//{
	//	const float fuelPenalty = 0.5f;
	//	float inputDir;

	//	if (Joystick::isConnected(joystick))
	//	{
	//		inputDir = Joystick::getAxisPosition(joystick, Joystick::PovX);
	//		if (inputDir < FLT_EPSILON)
	//		{
	//			direction = { -1,0 };
	//			//ChangeLane();
	//		}
	//		else if (inputDir > -FLT_EPSILON)
	//		{
	//			direction = { 1,0 };
	//		}

	//		inputDir = Joystick::getAxisPosition(joystick, Joystick::PovY);
	//		if (inputDir > FLT_EPSILON)
	//		{
	//			// AccelBackground()
	//			direction = { 0,-1 };
	//			RemoveFuel(fuelPenalty * MyTime::Instance().GetdeltaTime());
	//		}
	//		else if (inputDir < -FLT_EPSILON)
	//		{
	//			direction = { 0,1 };
	//			// DeacccelBackground()
	//		}


	//	}
	//	else
	//	{
	//		if (Keyboard::isKeyPressed(Keyboard::A))
	//		{
	//			direction = { -1,0 };
	//			//ChangeLane();
	//		}
	//		else if (Keyboard::isKeyPressed(Keyboard::D))
	//		{
	//			direction = { 1,0 };
	//		}

	//		else if (Keyboard::isKeyPressed(Keyboard::W))
	//		{
	//			// AccelBackground()
	//			direction = { 0,-1 };
	//			RemoveFuel(fuelPenalty * MyTime::Instance().GetdeltaTime());
	//		}
	//		else if (Keyboard::isKeyPressed(Keyboard::S))
	//		{
	//			direction = { 0,1 };
	//			// DeacccelBackground()
	//		}
	//	}
	//}

	void Car::Update()
	{
		Joystick::update();

		sprite.move(Vector2f{dirX, dirY} * MyTime::Instance().GetdeltaTime() * speed);
		RemoveFuel(fuelConsumption * MyTime::Instance().GetdeltaTime());
	}

}