#pragma once

#include "TileMap.hpp"
#include "stdafix.hpp"

class Engine;

class LvlConstructor{
    private:
        Engine* pGame;
        const Vector2i** map;
    public:
        LvlConstructor(Engine* pG, const Vector2i** map);
        ~LvlConstructor();

        void setMap(const Vector2i** map);
        void levelBuild();   


};