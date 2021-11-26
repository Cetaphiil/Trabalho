//
// Created by lucas on 25/11/2021.
//
#pragma once

#include "Entity.hpp"

class Obstacle : public Entity{
public:
    Obstacle(){deletable = false;}
    ~Obstacle(){}

    virtual void loader(){}
    virtual void collide(Entity* other) override{}

    void show(RenderWindow* window) override;

    Vector2f getPosition() override{return posit;}
    Vector2f spawnPosition(int max_value);
};

