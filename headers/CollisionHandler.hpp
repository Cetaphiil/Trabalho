#pragma once

#include "EntityList.hpp"

using namespace sf;

class Collider{

    EntityList* list;

public:
    Collider(){this->list = nullptr;}
    ~Collider(){}

    void CheckCollision(EntityList *other);
};