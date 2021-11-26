#include "Entity.hpp"
#include "GraphicHandler.hpp"

Entity::Entity(){

}

Entity::~Entity(){
    
}

void Entity::setGraphics(){
    pGraphics = Graphics::getGraphics();
}

const bool Entity::getDeletable(){
    return deletable;
}