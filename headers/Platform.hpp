#pragma once

#include "stdafix.hpp"
#include "Obstacle.hpp"

class Platform: public Obstacle{
    private:
        int lvl;
    public:
        Platform(Vector2f pos, int whatlvl, int type, int kind);
        ~Platform() {};

        void load(int type);
};