//
// Created by Lucas Orlikoski on 16/07/2021.
//

#ifndef GAME_OBJETO_H
#define GAME_OBJETO_H

#include "lib.hpp"


class Entity{
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    int life;
    int damage;
    float speed;
    sf::Vector2f g {0.0f, 7000};

public:
    Entity(){}
    virtual ~Entity(){}
};

#endif