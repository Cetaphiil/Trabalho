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

void EntityList::update(RenderWindow *window, float dt) {
    for(int i = 0; i < list.length(); i++){
        list[i]->update(window, dt);
    }
}
void EntityList::show(RenderWindow *window){
    for(int i = 0; i < list.length(); i++){
        list[i]->show(window);
    }
}
