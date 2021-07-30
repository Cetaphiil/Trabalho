//
// Created by Lucas Orlikoski on 16/07/2021.
//
#include "background.h"


void Background::loader() {
    if(!texture.loadFromFile("images/background1.png")){
        exit (1);
    }
    texture.loadFromFile("images/background1.png");
    sprite.setTexture(texture);
}
void Background::show(sf::RenderWindow *window){
    sprite.setPosition(sf::Vector2f(0, 0));
    window->draw(sprite);
}