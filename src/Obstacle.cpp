//
// Created by lucas on 25/11/2021.
//
#include <Obstacle.hpp>

void Obstacle::show(RenderWindow *window) {
    window->draw(sprite);
}

Vector2f Obstacle::spawnPosition(int max_value) {
    Vector2f spawnPosit;
    spawnPosit.y = 128.f;
    spawnPosit.x = (rand()%max_value);
    return spawnPosit;
}