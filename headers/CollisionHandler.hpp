//
// Created by lucas on 26/10/2021.
//

#ifndef GAME_NEW_COLLISIONHANDLER_HPP
#define GAME_NEW_COLLISIONHANDLER_HPP

#include "EntityList.hpp"

using namespace sf;

class Collider {

    EntityList *list;

public:
    Collider() { this->list = nullptr; }

    ~Collider() {}

    void CheckCollision(EntityList *other);

};
#endif //GAME_NEW_COLLISIONHANDLER_HPP
