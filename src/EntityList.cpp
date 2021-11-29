#include <EntityList.hpp>

EntityList::EntityList() {

};

EntityList::~EntityList() {

};

void EntityList::add(Entity *pNew) {
    list.add(pNew);
};

void EntityList::remove(Entity *pDel) {
    pDel->setShowing(false);
    list.remove(pDel);
};

void EntityList::update(float dt) {
    for(int i = 0; i < list.length(); i++){
        list[i]->update(dt);
    }
};
void EntityList::show(RenderWindow *window){
    for(int i = 0; i < list.length(); i++){
        if(list[i]->getShowing())
            list[i]->show(window);
    }
};

void EntityList::loader(){
    for(int i = 0; i < list.length(); i++){
        list[i]->loader();
    }
};

Entity* EntityList::operator[](int x) {
    Entity* aux = list[x];
    return aux;
}