//
// Created by Lucas Orlikoski on 14/07/2021.
//

#ifndef GAME_BACKGROUND_H
#define GAME_BACKGROUND_H

#include <Entity.hpp>
#include "lib.hpp"

class Background : public Entity{
public:
    void loader();
    void show(sf::RenderWindow *window);
};

#endif //GAME_BACKGROUND_H
