//
// Created by Lucas Orlikoski on 09/08/2021.
//

#include <Projectile.hpp>
Projectile::Projectile(Player player, Enemy enemy) {
    this->player = player;
    this->enemy = enemy;
    damage = 5;
    speed = 100.f;
    loader(enemy);
}
Projectile::~Projectile() {
    delete this;
}
void Projectile::loader(Enemy enemy) {
    texture.loadFromFile("../assets/sprites/Spell/Spells Effect.png");
    sprite.setTexture(texture);
    sprite.setPosition(enemy.getPosition());
}
void Projectile::show(RenderWindow *window) {
    window->draw(sprite);
}
void Projectile::update(Player player, Enemy enemy) {
    sf::Vector2f playerPosit = player.getPosition();
    sf::Vector2f enemyPosit = enemy.getPosition();

    if(playerPosit.x < enemyPosit.x){
        speed = 15000;
        posDesejada = {enemyPosit.x - 500, enemyPosit.y+30};
    }
    if (playerPosit.x > enemyPosit.x){
        speed = 15000;
        posDesejada = {enemyPosit.x + 500, enemyPosit.y+30};
    }
}