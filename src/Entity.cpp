#include "Entity.hpp"
#include "GraphicHandler.hpp"



const bool Entity::getDeletable(){
    return deletable;
}

void Entity::take_damage(int other_damage) {
    if(invincibility.getElapsedTime().asSeconds()> 2) {
        life -= other_damage;
        invincibility.restart();
    }
}
