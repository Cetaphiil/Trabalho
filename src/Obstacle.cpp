//
// Created by lucas on 25/11/2021.
//
#include <Obstacle.hpp>

void Obstacle::show(RenderWindow *window) {
    window->draw(sprite);
}
sf::Vector2f Obstacle::getPosition(){
    return posit;
}

sf::Vector2f Obstacle::spawnPosition(Vector2f pos) {
    Vector2f spawnPosit;
    spawnPosit.y = 128.f;
    spawnPosit.x = (pos.x);
    return spawnPosit;
}