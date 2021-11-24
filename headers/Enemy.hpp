#ifndef ENEMY_H_P_P_
#define ENEMY_H_P_P_

#include "Player.hpp"

using namespace sf;

class Enemy : public Character{
    protected:
        float deltaTime;
        Vector2f speed, aceleration;
        Clock timer;
        Transform target;
        Player* player;

    public:
        Clock cooldown;
        bool allow_shot;
        bool shoud_shot;

        bool spawn = false;

        void sprite_loader();

        Enemy();

        Vector2f getPosition();

        void initEnemies(Vector2i resolucao);

        void show(RenderWindow *window);
        void update(RenderWindow *window, float dt);

        void setPlayer(Player* player){this->player = player;}

        void collide(Entity* other);

};

#endif