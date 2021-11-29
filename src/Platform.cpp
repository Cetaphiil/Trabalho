#include "Platform.hpp"

Platform::Platform(Vector2f pos, int whatlvl, int type, int kind): Obstacle(){
    setKind(kind);
    setPosition(pos);
    lvl = whatlvl;
    damage = 0;
    load(type);
    hitbox.setSize({128.0f, 128.0f});
    hitbox.setOrigin({(hitbox.getSize().x /2), (hitbox.getSize().y/2)});
}

void Platform::load(int type){
    if(lvl == 1){

        if(type == platTypeLvl1::SnowPlat){
            texture.loadFromFile(SNOW_PLATAFORM);
            sprite.setTexture(texture);
            setShowing();
        } else if(type == platTypeLvl1::FloatSnowPlat){
            texture.loadFromFile(FLOAT_SNOW_PLATAFORM);
            sprite.setTexture(texture);
            setShowing();
        }
    }
    if(lvl == 2){
        if(type == platTypeLvl2::GraveyardGrass){
            texture.loadFromFile(PLATFORM_GRAVEYARD_GRASS);
            sprite.setTexture(texture);
            setShowing();
        }else if(type == platTypeLvl2::FloatGraveyardGrass){
            texture.loadFromFile(PLATAFORM_GRAVEYARD_FLOAT);
            sprite.setTexture(texture);
            setShowing();
        }
    }
}