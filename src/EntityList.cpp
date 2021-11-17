//
// Created by lucas on 17/11/2021.
//
#include <EntityList.hpp>

EntityList::EntityList() {

}
EntityList::~EntityList() {

}

void EntityList::add(Entity *pNew) {
    list.add(pNew);
}

void EntityList::remove(Entity *pDel) {
    list.remove(pDel);
}
