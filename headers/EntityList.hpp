#pragma once

#include "Entity.hpp"
#include "Lista.hpp"

class EntityList {
public:
    EntityList();
    ~EntityList();

    Lista<Entity> list;

    void add(Entity* pNew);
    void remove(Entity* pDel);
    void freeAll(){list.clear();}
    int getLength() {return list.length(); }

    void update(RenderWindow* window, float dt);
    void show(RenderWindow *window);
    void loader();
};