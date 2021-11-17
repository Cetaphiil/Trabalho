//
// Created by lucas on 17/11/2021.
//

#ifndef GAME_NEW_ENTITYLIST_HPP
#define GAME_NEW_ENTITYLIST_HPP

#include "Character.hpp"
#include "Projectile.hpp"
#include "TileMap.hpp"
#include "Lista.hpp"

class EntityList {
    Lista<Entity> list;

public:
    EntityList();
    ~EntityList();

    void add(Entity* pNew);
    void remove(Entity* pDel);
    void freeAll(){list.clear();}
    int getLength() {return list.length(); }

};

#endif //GAME_NEW_ENTITYLIST_HPP
