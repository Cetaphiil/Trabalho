#pragma once

#include "stdafix.hpp"
#include "GraphicHandler.hpp"
#include "Obstacle.hpp"

class Spike : public Obstacle{
public:
    Spike(Vector2f posit, int kind);
    ~Spike();

    void load();

    void collide(Entity *other){};
};