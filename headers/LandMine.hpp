//
// Created by lucas on 25/11/2021.
//
#pragma once

#include "Obstacle.hpp"

class LandMine : public Obstacle{
public:
    LandMine(Vector2f pos, int kind);
    ~LandMine();

    void loader();

    void collide(Entity* other);
};