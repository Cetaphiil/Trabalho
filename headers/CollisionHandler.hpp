#pragma once

#include "EntityList.hpp"
#include "Entity.hpp"


using namespace sf;

class Collider{

    EntityList* list;

public:
    Collider(EntityList* lE){this->list = lE;}
    ~Collider(){}

    void CheckCollision();

    void CollidePlayer(Entity* ent1, Entity* ent2, float dx, float dy, float intersectX, float intersectY);
    void CollideEnemy(Entity* ent1, Entity* ent2, float dx, float dy, float intersectX, float intersectY);
    void CollidePlatform(Entity* ent1, Entity* ent2, float dx, float dy, float intersectX, float intersectY){};

    void ChangePositionX(Entity* ent1, Entity* ent2, float intersectX);

    void ChangePositionY(Entity *ent1, Entity *ent2, float intersectY);
};