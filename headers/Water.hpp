#pragma once

#include "stdafix.hpp"
#include "Obstacle.hpp"

class Water : public Obstacle{
    public:
        Water(int kind, Vector2f pos);
        ~Water(){};

        void load();
};