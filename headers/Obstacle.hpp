//
// Created by lucas on 25/11/2021.
//
#pragma once

#include "Entity.hpp"

class Obstacle : public Entity{
public:
    Obstacle() : Entity(){}
    ~Obstacle(){}

    virtual void loader(){};

    void show(RenderWindow* window);

    sf::Vector2f getPosition();
    sf::Vector2f spawnPosition(sf::Vector2f pos);
};

