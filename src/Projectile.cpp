//
// Created by Lucas Orlikoski on 09/08/2021.
//

#include <Projectile.hpp>

Projectile::Projectile() {
    damage = 5;
    speed = 100.f;
    loader();
}
Projectile::~Projectile() noexcept {
    delete sprite;
}
void Projectile::loader() {
    texture.loadFromFile("../assets/sprites/Spell/Spells Effect.png");
    sprite.setTexture(texture);
    sprite.setPosition(enemy.getPosition());
}
void Projectile::show(window) {
    window->draw(sprite);
}
void Projectile::update() {
    sf::Vector2f playerPosit = player.getPosition();
    sf::Vector2f enemyPosit = enemy.getPosition();
    if(timer.getElapsedTime().asSeconds() > 3)
        ~Projectile();
    if(playerPosit.x < enemyPosit.x){
        speed = 15000;
        posDesejada = {enemyPosit.x - 500, enemyPosit.y+30};
    }
    if (playerPosit.x > enemyPosit.x){
        speed = 15000;
        posDesejada = {enemyPosit.x + 500, enemyPosit.y+30};
    }

}