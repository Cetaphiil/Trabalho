//
// Created by lucas on 25/11/2021.
//
#include <Spike.hpp>

void Spike::loader() {
    texture.loadFromFile("../assets/Sprites/Spikes/spike.png");
    sprite.setTexture(texture);
}
Spike::Spike(int kind) : Obstacle(){
    setKind(kind);
    setPosition({spawnPosition(1080)});
    loader();
    damage = 15;
    hitbox.setSize({30.f, 30.f});
    hitbox.setOrigin({15.f, 15.f});
}

