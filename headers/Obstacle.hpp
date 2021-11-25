//
// Created by lucas on 25/11/2021.
//
#pragma once

#include "Entity.hpp"

class Obstacle : public Entity{
public:
    Obstacle(){}
    ~Obstacle(){}

    void show(RenderWindow* window) override;

    Vector2f getPosition() override{return posit;}
};

