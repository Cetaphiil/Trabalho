#include "CollisionHandler.hpp"

void Collider::CheckCollision(EntityList *other) {
    this->list = other;
    Entity *entity1, *entity2;

    for (int i = 0; i < list->getLength(); i++) {
        for (int j = i + 1; j < list->getLength(); j++) {

            entity1 = list->list[i];
            entity2 = list->list[j];

            float dy, dx, intersectX, intersectY;
            
            dx = entity2->getPosition().x - entity1->getPosition().x;
            dy = entity2->getPosition().y - entity1->getPosition().y;
            
            intersectX = abs(dx) - (entity1->getSize().x / 2 + entity2->getSize().x / 2);
            intersectY = abs(dy) - (entity1->getSize().y / 2 + entity2->getSize().y / 2);
            if (intersectX < 0.0f && intersectY < 0.0f) {
                entity2->collide(entity1);
                entity1->collide(entity2);
            }
        }
    }
}