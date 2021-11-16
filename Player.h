//
// Created by Lucas Orlikoski on 19/07/2021.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "Objeto.h"
#include <Windows.h>

struct List{
    sf::Texture *texture;
    List *next;
};

class Player:public Entity{
public:
    sf::Vector2f s, v, a;
    sf::Clock t;
    sf::FloatRect hitbox{0.f, 0.f, 114.f, 144.f};

    List **sprite_list;


    void loader();

    List* add_sprite(List* list);

    void load_idle();
    void load_jump();
    void load_walk();
    void load_dead();
    void load_attack();

    sf::Clock c;


    void show(sf::RenderWindow *window);
    void update(sf::RenderWindow *window);
};

#endif //GAME_PLAYER_H
