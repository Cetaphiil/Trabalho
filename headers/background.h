//
// Created by Lucas Orlikoski on 14/07/2021.
//

#ifndef GAME_BACKGROUND_H
#define GAME_BACKGROUND_H

#include "Objeto.h"

class Background:public Object{
public:
    void loader();
    void show(sf::RenderWindow *window);
};

#endif //GAME_BACKGROUND_H
