#pragma once

#include "stdafix.hpp"
#include "Obstacle.hpp"

class Platform: public Obstacle{
    public:
        Platform(int kind, Vector2f pos);
        ~Platform() {};

        void load(int kind);
};