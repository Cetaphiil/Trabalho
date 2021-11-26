#pragma once

#include "TileMap.hpp"
#include "stdafix.hpp"

class Engine;

class LvlContructor{
    private:
        Engine* pGame;
        Vector2i** map;
    public:
        LvlContructor(Engine* pG);


        void levelBuild();   


};