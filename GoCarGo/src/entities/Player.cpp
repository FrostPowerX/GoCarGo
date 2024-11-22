#include "Player.h"

#include "utilities/MyTime.h"

game::Player::Player(String name, const std::string textureName, int frames, int frameIndex, float widthScale, float heightScale, float speed, float fuel) :
	Car(textureName, frames, frameIndex, widthScale, heightScale, speed, fuel)
{
	this->name = name;
}

void game::Player::Input()
{
	Car::Input();

	const float deadZone = 10.f;
	const float fuelPenalty = 0.5f;
	float inputDir;

	dirX = 0;
	dirY = 0;

	if (Joystick::isConnected(0))
	{
		inputDir = Joystick::getAxisPosition(0, Joystick::PovX);
		if (inputDir > deadZone)
		{
			dirX = 1;
		}
		else if (inputDir < -deadZone)
		{
			dirX = -1;
		}
		inputDir = Joystick::getAxisPosition(0, Joystick::PovY);
		if (inputDir > deadZone)
		{
			// AccelBackground()
			dirY = -1;
			RemoveFuel(fuelPenalty * MyTime::Instance().GetdeltaTime());
		}
		else if (inputDir < -deadZone)
		{
			dirY = 1;
			// DeacccelBackground()
		}
	}
	else
	{
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			dirX = -1;
			//ChangeLane();
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			dirX = 1;
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
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

void game::Player::Update(Entity* other)
{
	if (CheckCollision(other))
	{
		GetHit();
	}

	if (fuel <= 0) 
	{
		isAlive = false;
	}

	Car::Update();

	Joystick::update();
}

void game::Player::Draw(RenderWindow& window)
{
	if(isAlive)
	{
		Car::Draw(window);
	}
}
