#pragma once
#include "stdafix.hpp"
#include "GraphicHandler.hpp"
#include "Obstacle.hpp"
class Wall: public Obstacle
{
public:
    Wall(Vector2f posit, int kind);
    ~Wall();

    void loader();

    void collide(Entity* other);
};