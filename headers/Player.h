//
// Created by Lucas Orlikoski on 19/07/2021.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <Objeto.h>
#include <Windows.h>

struct List{
    sf::Texture *texture;
    List *next;
};

class Player:public Entity{
public:
    sf::Vector2f s, v, a;
    sf::Clock t;

    List **sprite_list;


    void loader();

    List* add_sprite(List* list);

    void load_idle();
    void load_jump();
    void load_walk();
    void load_dead();
    void load_attack();

    void showPlayer(sf::RenderWindow *window);
    void updatePlayer(sf::RenderWindow *window);
};

#endif //GAME_PLAYER_H
