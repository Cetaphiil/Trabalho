#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "lib.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Entity.hpp"

class Projectile : public Entity{
private:
    sf::Vector2f posit;
    sf::Vector2f posDesejada;
    Player *p_player;
    Enemy *p_enemy;
    sf::Vector2f playerPosit;
    sf::Vector2f enemyPosit;
public:
    bool exists;
    sf::Clock timer;
    Projectile(Player *player, Enemy *enemy);
    ~Projectile();
    void loader();
    void update();
    void show(RenderWindow* window);
};

#endif
