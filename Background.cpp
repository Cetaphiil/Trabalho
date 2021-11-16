//
// Created by Lucas Orlikoski on 16/07/2021.
//
#include <background.hpp>


void Background::loader() {
    if(!texture.loadFromFile("../assets/background/Fundo.png")){
        exit (1);
    }
    texture.loadFromFile("../assets/background/Fundo.png");
    sprite.setTexture(texture);
}
void Background::show(sf::RenderWindow *window){
    sprite.setPosition(sf::Vector2f(0, 0));
    window->draw(sprite);
}