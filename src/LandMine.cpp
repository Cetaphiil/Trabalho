//
// Created by lucas on 25/11/2021.
//
#include <LandMine.hpp>
#include <Game.hpp>

LandMine::LandMine(Vector2f pos, int kind) : Obstacle(){
    setKind(kind);
    setPosition(pos);
    loader();
    setShowing();
    damage = 50;
    hitbox.setSize({15.f, 8.f});
    hitbox.setOrigin({7.5f, 4.f});
}

LandMine::~LandMine(){

}

void LandMine::loader() {
    texture.loadFromFile(LANDMINE);
    sprite.setTexture(texture);
    sprite.setScale(0.3, 0.3);
}

void LandMine::collide(Entity *other) {
    if(other->getKind() == 1){
        deletable = true;
    }
}

