#pragma once

#include "Car.h"

namespace game
{
    class Player :
        public Car
    {
    private:

        String name;

    public:

        Player(String name, const std::string textureName, int frames, int frameIndex,
            float widthScale, float heightScale, float speed, float fuel);

        void Input() override;
        void Update() override;
        void Draw(RenderWindow& window) override;

    };
}

