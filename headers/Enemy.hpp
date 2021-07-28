#ifndef ENEMY_H_P_P_
#define ENEMY_H_P_P_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


using namespace sf;

class Enemy{
    protected:
        //int life = 10, damage = 5, speed = 5;
        RectangleShape enemySprite;
    public:
        Vector2f enemyPosit;
        Enemy();

        void initEnemies();
        void updatePosit(Vector2f newPosit);
        RectangleShape getEnemies();

};

#endif