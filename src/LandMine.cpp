//
// Created by lucas on 25/11/2021.
//
#include <LandMine.hpp>
#include <Game.hpp>

LandMine::LandMine(int kind, sf::Vector2f pos) : Obstacle(){
    setKind(kind);
    setPosition(pos);
    loader();
    damage = 50;
    hitbox.setSize({40.f, 20.f});
    hitbox.setOrigin({20.f, 10.f});
}

LandMine::~LandMine(){

}

void LandMine::loader() {
    texture.loadFromFile("../assets/Sprites/Land Mine/landmine.png");
    sprite.setTexture(texture);
}

void LandMine::collide(Entity *other) {
    if(other->getKind() == 1){
        deletable = true;
    }
}
