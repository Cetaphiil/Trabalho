#include "Entity.hpp"
#include "GraphicHandler.hpp"


void Entity::setGraphics(){
    pGraphics = Graphics::getGraphics();
}

bool Entity::getDeletable(){
    return deletable;
}