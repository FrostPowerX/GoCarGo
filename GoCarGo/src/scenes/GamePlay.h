#pragma once

#include "base/Scene.h"

#include "entities/Player.h"


namespace game
{
    class GamePlay :
        public Scene
    {
    private:

        Player* player;

        bool isPause;

    public:

        GamePlay();

        void Init() override;

        void Input() override;
        void Update() override;
        void Draw(RenderWindow& window) override;

        void DeInit() override;

    };
}

