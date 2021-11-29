#pragma once

#include "stdafix.hpp"

class Lifebar{
private:
    sf::RectangleShape outside;
    sf::RectangleShape inner;
public:
    Lifebar(sf::Vector2f position);
    virtual ~Lifebar(){}

    void setPosition(sf::Vector2f position);
    void update(int life, int MAX_LIFE, sf::Vector2f position);
    void show(sf::RenderWindow *window);
};
