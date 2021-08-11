//
// Created by Lucas Orlikoski on 09/08/2021.
//

#ifndef GAME_NEW_PROJECTILE_HPP
#define GAME_NEW_PROJECTILE_HPP

#include "lib.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Entity.hpp"

class Projectile : public Entity{
private:
    sf::Clock timer;
    sf::Vector2f posDesejada;
public:
    Projectile();
    virtual ~Projectile();
    void loader();
    void update();
    void show(RenderWindow* window);
};

#endif //GAME_NEW_PROJECTILE_HPP
