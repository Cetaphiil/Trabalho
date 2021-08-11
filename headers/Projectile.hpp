//
// Created by Lucas Orlikoski on 09/08/2021.
//

#ifndef GAME_NEW_PROJECTILE_HPP
#define GAME_NEW_PROJECTILE_HPP

#include "lib.hpp"

class Projectile : protected Entity{
private:
    sf::Clock timer;
public:
    Projectile();
    virtual ~Projectile();
    void loader();
    void update();
    void show();
};

#endif //GAME_NEW_PROJECTILE_HPP
