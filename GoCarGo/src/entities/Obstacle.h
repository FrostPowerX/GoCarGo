#pragma once
#include <string>

#include "Car.h"

namespace game
{
    class Obstacle : public Car
    {
    public:
        Obstacle(Vector2f pos, const std::string textureName, int frames, int frameIndex,
                float widthScale, float heightScale, float speed, float fuel);
        void Update() override;
    };
}