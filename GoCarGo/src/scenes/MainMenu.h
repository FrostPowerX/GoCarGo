#pragma once

#include "base/Scene.h"

namespace game
{
    class MainMenu :
        public Scene
    {
    private:



    public:

        MainMenu();
        ~MainMenu();

        void Init() override;

        void Input() override;
        void Update() override;
        void Draw() override;

        void DeInit() override;

    };
}

