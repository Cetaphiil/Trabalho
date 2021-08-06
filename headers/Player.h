//
// Created by Lucas Orlikoski on 19/07/2021.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "lib.hpp"



class Player: public Entidade{
public:
    sf::Vector2f s, v, a;
    sf::Clock t;

    void showPlayer(sf::RenderWindow *window);
    void updatePlayer(sf::RenderWindow *window);
};

#endif //GAME_PLAYER_H
