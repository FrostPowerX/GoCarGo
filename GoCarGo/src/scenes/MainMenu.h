#pragma once

#include "base/Scene.h"

namespace game
{
    class MainMenu :
        public Scene
    {
    private:



    public:

        void Init() override;

        //void Input() override;
        //void Update() override;
        //void Draw(RenderWindow& window) override;

        void DeInit() override;

    };
}

