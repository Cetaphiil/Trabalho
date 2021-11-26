#include "Entity.hpp"
#include "GraphicHandler.hpp"

Entity::Entity(){

}

void Entity::setGraphics(){
    pGraphics = Graphics::getGraphics();
}