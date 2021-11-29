#pragma once

#include "stdafix.hpp"
#include "Entity.hpp"

class Graphics;

using namespace sf;

class Background: public Entity {
public:
    Background();
    ~Background();

    void loader(int whatlvl);
    void show(sf::RenderWindow *window);
    void update(sf::Vector2f pos);
    Vector2f getPosition(){ std::cout << "backGround can't return a possition" << std::endl; exit(2); }
};

