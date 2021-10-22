#ifndef ENEMY_H_P_P_
#define ENEMY_H_P_P_

#include "Player.hpp"

using namespace sf;

class Enemy : protected Character{
    protected:
        float deltaTime;
        Vector2f speed, aceleration;
        Clock timer;
        Transform target;

    public:
        bool spawn = false;

        void sprite_loader();

        Enemy();

        Vector2f getPosition();

        void initEnemies(Vector2i resolucao);

        void showEnemies(RenderWindow *window);
        void updateEnemy(RenderWindow *window, Player player);

};

#endif