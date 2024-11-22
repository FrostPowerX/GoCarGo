#include "Car.h"
#include <SFML/Window/Joystick.hpp>



namespace game
{
	Car::Car(const Texture& texture, int width, int height, float feul)
	{
		sprite = Sprite(texture, {0,0,width,height});
		activePower = Power::None;
		distance = 0;
		this->feul = feul;

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


}