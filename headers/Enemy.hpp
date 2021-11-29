#pragma once

#include "Player.hpp"

class Collider;

using namespace sf;

class Enemy : public Character{
    protected:
        float deltaTime;
        Vector2f aceleration;
        Clock timer;
        Player* player;
    public:
        Enemy();
        ~Enemy(){};

        virtual void loader(){};

        virtual Vector2f getPosition(){ return posit; };

        virtual void show(RenderWindow *window){};
        virtual void update(float dt){};
        virtual void setPlayer(Player* player){this->player = player;}
};