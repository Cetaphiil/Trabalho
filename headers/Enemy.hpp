#pragma once

#include "Player.hpp"

class Collider;

using namespace sf;

class Enemy : public Character{
    protected:
        float deltaTime;
        Vector2f speed, aceleration;
        Clock timer;
        Transform target;
        Player* player;
    public:
        Enemy();
        ~Enemy(){};

        Clock cooldown;
        
        bool allow_shot;
        bool shoud_shot;
        bool spawn = false;

        void loader();


        Vector2f getPosition();


        void show(RenderWindow *window);
        void update(RenderWindow *window, float dt);
        void setPlayer(Player* player){this->player = player;}
        void collide(Entity* other);
};