#include "Obstacle.h"



game::Obstacle::Obstacle(Vector2f pos, const std::string textureName, int frames, int frameIndex, float widthScale, float heightScale,
    float speed, float fuel): Car(textureName, frames, frameIndex, widthScale, heightScale, speed, fuel)
{
    dirY = 1;
    dirX = 0;
    sprite.setPosition(pos);
}

void game::Obstacle::Update()
{
    if(sprite.getPosition().y >= 800)
    {
        sprite.setPosition({ static_cast<float>(rand() % 801 + 1), 0 });
    }

    Car::Update();
}

