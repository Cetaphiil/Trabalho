//
// Created by lucas on 25/11/2021.
//
#include <Spike.hpp>

void Spike::load() {
    texture.loadFromFile("../assets/sprites/spike/spike.png");
    sprite.setTexture(texture);
}
Spike::Spike(int kind) : Obstacle(){
    setKind(kind);
    setPosition({200.f, 100.f});
}
