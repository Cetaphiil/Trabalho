#include "CollisionHandler.hpp"

void Collider::CheckCollision() {
    Entity *ent1, *ent2;

    for (int i = 0; i < list->getLength(); i++) {
        for (int j = i + 1; j < list->getLength(); j++) {

            ent1 = list->list[i];
            ent2 = list->list[j];

            float dy, dx, intersectX, intersectY;

            dx = ent2->getPosition().x - ent1->getPosition().x;
            dy = ent2->getPosition().y - ent1->getPosition().y;

            intersectX = abs(dx) - (ent1->getSize().x / 2 + ent2->getSize().x / 2);
            intersectY = abs(dy) - (ent1->getSize().y / 2 + ent2->getSize().y / 2);
            if (intersectX < 0.0f && intersectY < 0.0f) {
                if(ent1->getKind() ==0){
                    CollidePlayer(ent1, ent2, dx, dy, intersectX, intersectY);
                }
                else if(ent1->getKind() == 5){
                    CollidePlatform(ent1, ent2, dx, dy, intersectX, intersectY);
                }
                else if(ent1->getKind() == 1){
                    CollideEnemy(ent1, ent2, dx, dy, intersectX, intersectY);
                }
            }
        }
    }
}

void Collider::CollidePlayer(Entity *ent1, Entity *ent2, float dx, float dy, float intersectX, float intersectY) {
    switch (ent2->getKind()) {
        case 1: //enemy
            ent1->take_damage(ent2->damage);
        case 3: //landmine
            ent1->take_damage(ent2->damage);
            list->remove(ent2);
        case 4: //spike
            ent1->take_damage(ent2->damage);
        case 5: //platform
            if (intersectX > intersectY) {
                ChangePositionX(ent1, ent2, intersectX);
                ent1->setSpeed(sf::Vector2f(0, ent1->getSpeed().y));
            } else {
                if (dy > 0.0f) {
                    ChangePositionY(ent1, ent2, intersectY);
                    ent1->jump = true;
                } else {
                    ChangePositionY(ent1, ent2, intersectY);
                }
            }
    }


}

void Collider::CollideEnemy(Entity *ent1, Entity *ent2, float dx, float dy, float intersectX, float intersectY) {
    switch(ent2->getKind()){
        case 0:
            ent1->take_damage(ent2->damage);
        case 5:
            if (intersectX > intersectY) {
                ChangePositionX(ent1, ent2, intersectX);
                ent1->setSpeed(sf::Vector2f(0, ent1->getSpeed().y));
            } else {
                if (dy > 0.0f) {
                    ChangePositionY(ent1, ent2, intersectY);
                    ent1->jump = true;
                } else {
                    ChangePositionY(ent1, ent2, intersectY);
                }
            }
    }
}

void Collider::ChangePositionX(Entity *ent1, Entity *ent2, float intersectX) {
    sf::Vector2f aux;
    aux.x = intersectX * ent1->getSpeed().x / ((abs(ent1->getSpeed().x) + abs(ent2->getSpeed().x) + 0.00001));
    aux.y = 0.0f;
    ent1->setPosition(ent1->getPosition()+aux);

    ent1->setSpeed(sf::Vector2f(0.0f, ent1->getSpeed().y));
}
void Collider::ChangePositionY(Entity *ent1, Entity *ent2, float intersectY) {
    sf::Vector2f aux;
    aux.x = 0.0f;
    aux.y = intersectY * ent1->getSpeed().y / ((abs(ent1->getSpeed().y) + abs(ent2->getSpeed().y) + 0.00001));
    ent1->setPosition({ent1->getPosition().x + aux.x, ent1->getPosition().y + aux.y });
    ent1->setSpeed(sf::Vector2f(ent1->getSpeed().x, 0.0f));
}

