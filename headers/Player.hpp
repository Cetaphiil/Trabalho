//
// Created by Lucas Orlikoski on 19/07/2021.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <Entity.hpp>
#include "lib.hpp"

struct List{
    sf::Texture *texture;
    List *next;
};

class Player : protected Entity{
public:
    sf::Vector2f s, v, a;
    sf::Clock t;
    sf::FloatRect hitbox{0.f, 0.f, 114.f, 144.f};

    float player_speed = 8000;
    float player_jump = 35*g.y + 600;
    float desaceleracao = 20;

    bool jump = false;
    bool idle = true;
    bool attack = false;

    sf::Clock atk_timmer;

    List **sprite_list;


    void loader();

    static List* add_sprite(List* list);

    void load_idle();
    void load_jump();
    void load_walk();
    void load_dead();
    void load_attack();

    sf::Clock c;

    sf::Vector2f getPosition();
    void show(sf::RenderWindow *window);
    void update(sf::RenderWindow *window, float dt);
};

#endif