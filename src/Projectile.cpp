//
// Created by Lucas Orlikoski on 09/08/2021.
//

#include <Projectile.hpp>
#include <Enemy.hpp>
#include <Player.hpp>
#include <lib.hpp>

Projectile::Projectile() {
    damage = 5;
    speed = 100.f;
    loader();
}
Projectile::~Projectile() noexcept {
    delete Projectile;
}
void Projectile::loader() {
    texture.loadFromFile("../assets/sprites/Spell/Spells Effect.png");
    sprite.setTexture(texture);
    sprite.setPosition(enemy.getPosition());
}
void Projectile::update() {
    if(timer.getElapsedTime().asSeconds() > 8)
        ~Projectile();
    Vector2f posDesejada = player.getPosition;




}