#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "stdafix.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Entity.hpp"

class Projectile : public Entity{
private:
    sf::Vector2f posDesejada;
    Player player;
    Enemy enemy;
public:
    sf::Clock timer;
    Projectile(Player player, Enemy enemy);
    ~Projectile();
    void loader(Enemy enemy);
    void update(Player player, Enemy enemy);
    void show(RenderWindow* window);
};

#endif
