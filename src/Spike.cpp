
#include "Spike.hpp"

Spike::Spike(Vector2f posit, int kind) : Obstacle(){
    setKind(kind);
    setPosition(posit);
    setShowing();
    load();
    damage = 15;
}

Spike::~Spike(){

}

void Spike::load() {
    texture.loadFromFile(SPIKE);
    sprite.setTexture(texture);
    sprite.setScale(0.6, 1.0);
}
