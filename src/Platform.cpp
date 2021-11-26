#include "Platform.hpp"

Platform::Platform(int kind, Vector2f pos): Obstacle(){
    setKind(kind);
    setPosition(pos);
}

void Platform::load(int kind){
    if(kind == platType::SnowPlat){
        texture.loadFromFile(SNOW_PLATAFORM);
        sprite.setTexture(texture);
    }
    else if(kind == platType::FloatSnowPlat){
        texture.loadFromFile(FLOAT_SNOW_PLATAFORM);
        sprite.setTexture(texture);
    }
    else if(kind == platType::GraveyardGrass){
        texture.loadFromFile(PLATFORM_GRAVEYARD_GRASS);
        sprite.setTexture(texture);
    }
    else if(kind == platType::FloatGraveyardGrass){
        texture.loadFromFile(PLATAFORM_GRAVEYARD_FLOAT);
        sprite.setTexture(texture);
    }
}