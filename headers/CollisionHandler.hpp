//
// Created by lucas on 26/10/2021.
//

#ifndef GAME_NEW_COLLISIONHANDLER_HPP
#define GAME_NEW_COLLISIONHANDLER_HPP
#include "lib.hpp"

using namespace sf;

class Collider{

    RectangleShape *body;

public:
    Collider(RectangleShape *body);
    ~Collider();

    bool CheckCollision(Collider &other);

    Vector2f getPosition() {return body->getPosition();}
    Vector2f getHalfSize() {return body->getSize()/2.0f;}

};

#endif //GAME_NEW_COLLISIONHANDLER_HPP
