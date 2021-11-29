//
// Created by lucas on 27/11/2021.
//

#include "Lifebar.hpp"


Lifebar::Lifebar(sf::Vector2f position) {
    outside.setSize({110.f, 25.f});
    outside.setFillColor({0, 0, 0, 200});
    inner.setSize({100.f, 20.f});
    inner.setFillColor({250, 0, 0, 150});
    setPosition({position.x, position.y-30});
}

void Lifebar::setPosition(sf::Vector2f position) {
    outside.setPosition(position);
    inner.setPosition({position.x + 5.f, position.y+2.5f});
}
void Lifebar::update(int life, int MAX_LIFE, sf::Vector2f position) {
    if(life < 0)
        life = 0;
    if(life > MAX_LIFE)
        life = MAX_LIFE;

    std::cout << life << std::endl;
    inner.setSize({float(life), inner.getSize().y});
    setPosition({position.x, position.y-30});
}
void Lifebar::show(sf::RenderWindow *window) {
    window->draw(outside);
    window->draw(inner);
}