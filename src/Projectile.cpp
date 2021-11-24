//
// Created by Lucas Orlikoski on 09/08/2021.
//

#include <Projectile.hpp>

Projectile::Projectile(Player *player, Enemy *enemy) : Entity() {
    exists = true;
    p_player = player;
    p_enemy = enemy;
    damage = 5;
    speed = {100.f, 0};
    sprite.setPosition(0.f, 0.f);
    hitbox.setSize({40.0f, 40.0f});
    hitbox.setOrigin({(hitbox.getSize().x /2), (hitbox.getSize().y/2)});
    loader();
}
Projectile::~Projectile() {
    exists = false;
}
void Projectile::loader() {
    texture.loadFromFile("../assets/sprites/Spell/Spells Effect.png");
    sprite.scale({0.15f, 0.15f});
    sprite.setTexture(texture);
    sprite.setPosition(p_enemy->getPosition());
}
void Projectile::show(RenderWindow *window) {
    //sprite.setPosition(posit);
    window->draw(sprite);
}
void Projectile::update() {
    playerPosit = p_player->getPosition();
    enemyPosit = p_enemy->getPosition();

    //printf("%f || %f \n", p_enemy->getPosition().x, p_enemy->getPosition().y);

    if(playerPosit.x < enemyPosit.x){
        posDesejada = {enemyPosit.x - 20, enemyPosit.y+10};
    }
    else{
        posDesejada = {enemyPosit.x + 20, enemyPosit.y+10};
    }
    posit = {0.0f, 0.0f};
}