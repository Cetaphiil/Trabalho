//
// Created by Lucas Orlikoski on 19/07/2021.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <Character.hpp>
#include "lib.hpp"

using namespace sf;

class Player : protected Character{
private:
    float player_speed = 8000;
    float player_jump = 35*gravity.y - 30000;
    float desaceleracao = 20;

    bool jump = false;
    bool attack = false;

    Clock atk_timmer;


    void load_idle();
    void load_jump();
    void load_walk();
    void load_dead();
    void load_attack();

public:
    Player();
    void loader();
    sf::Vector2f getPosition();
    void show(sf::RenderWindow *window);
    void update(sf::RenderWindow *window, float dt);
};

#endif