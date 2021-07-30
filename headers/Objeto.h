//
// Created by Lucas Orlikoski on 16/07/2021.
//

#ifndef GAME_OBJETO_H
#define GAME_OBJETO_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <string>


class Object{
public:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif //GAME_OBJETO_H
