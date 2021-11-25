#pragma once

#include "stdafix.hpp"

class Graphics;

using namespace sf;

class Entity{
    private:
        int kind;

    protected:

        int life;
        Graphics* pGraphics;
        Texture texture;
        Sprite sprite;
        RectangleShape hitbox;
        Vector2f posit, speed, acceleration;


    public:
        Entity(){};
        virtual ~Entity(){};

        Clock invincibility;
        bool attacking;
        int damage;

        virtual void update(RenderWindow* window, float dt) {}
        virtual void show(RenderWindow* window) {}
        virtual void collide(Entity* other){}

        void setKind(int aux){kind = aux;}
        int getKind(){return kind;}

        virtual Vector2f getPosition() = 0;
        void setPosition(Vector2f pos){posit = pos; sprite.setPosition(pos);}

        int getLife() const{return life;}
        Vector2f getSize(){return hitbox.getSize();}

        void setGraphics();
};