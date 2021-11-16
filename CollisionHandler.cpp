//
// Created by lucas on 07/11/2021.
//

#include <CollisionHandler.hpp>

using namespace sf;

Collider::Collider(RectangleShape *body) {
    this->body = body;
}

bool Collider::CheckCollision(Collider &other) {

    Vector2f otherPosition = other.getPosition();
    Vector2f otherHalfSize = other.getHalfSize();
    Vector2f thisPosition = getPosition();
    Vector2f thisHalfSize = getHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersectionX = abs(deltaX) - (otherHalfSize.x - thisHalfSize.x);
    float intersectionY = abs(deltaY) - (otherHalfSize.y - thisHalfSize.y);

    if(intersectionX < 0.0f || intersectionY < 0.0f)
        return true;

    return false;
}
