//
// Created by lucas on 07/11/2021.
//

#include <CollisionHandler.hpp>

using namespace sf;

void Collider::CheckCollision(EntityList *other) {
    this->list = other;
    Entity *ent1, *ent2;

    for (int i = 0; i < list->getLength(); i++) {
        for (int j = i + 1; j < list->getLength(); j++) {

            // pega a entidade
            ent1 = list->list[i];
            ent2 = list->list[j];

            float dy, dx, intersectX, intersectY;
            // Diferença entre os centros
            dx = ent2->getPosition().x - ent1->getPosition().x;
            dy = ent2->getPosition().y - ent1->getPosition().y;
            // Condiçao para colisao
            intersectX = abs(dx) - (ent1->getSize().x / 2 + ent2->getSize().x / 2);
            intersectY = abs(dy) - (ent1->getSize().y / 2 + ent2->getSize().y / 2);
            if (intersectX < 0.0f && intersectY < 0.0f) { //Condition to collide...
                ent2->collide(ent1);
                ent1->collide(ent2);
            }
        }
    }
}


