#pragma once

#include "stdafix.hpp"

class Graphics;

using namespace sf;

class Entity{
    private:

        int kind;

    protected:
        Graphics* pGraphics;
        Texture texture;
        Sprite sprite;
        RectangleShape hitbox;
        Vector2f posit, speed, acceleration;
        int life;

    public:
        Clock invincibility;
        bool deletable;
        bool attacking;
        int damage;

    public:
        Entity();
        virtual ~Entity();

        virtual void loader(){};
        virtual void update(RenderWindow* window, float dt) {}
        virtual void show(RenderWindow* window) {}
        virtual void collide(Entity* other){}

        void setKind(int aux){kind = aux;}
        const int getKind(){return kind;}
        const bool getDeletable();

        virtual Vector2f getPosition() = 0;
        void setPosition(Vector2f pos){posit = pos; sprite.setPosition(pos);}
        
        int getLife() const{ return life; }
        Vector2f getSize(){return hitbox.getSize();}

        void setGraphics();
};