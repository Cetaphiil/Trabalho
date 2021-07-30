//
// Created by Lucas Orlikoski on 19/07/2021.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "Objeto.h"

class Player:public Object{
public:
    sf::Vector2f s, v, a;
    sf::Clock t;
    void loader();
    void show(sf::RenderWindow *window);
    void update(sf::RenderWindow *window);
};

#endif //GAME_PLAYER_H
