#include "Water.hpp"

Water::Water(int kind, Vector2f pos){
    setKind(kind);
    setPosition(pos);
}

void Water::load(){
    texture.loadFromFile(WATER);
    sprite.setTexture(texture);
}