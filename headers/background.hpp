#ifndef BACKGROUND_H_P_P_
#define BACKGROUND_H_P_P_

#include <Entity.hpp>
#include "lib.hpp"

class Background : public Entity{
public:
    void loader();
    void show(sf::RenderWindow *window);
};

#endif
