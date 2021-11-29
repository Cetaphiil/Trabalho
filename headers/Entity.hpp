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
        Vector2f posit, speed = {0, 0};
        int life;

    public:
        Clock invincibility;
        bool shouldShow;
        bool deletable;
        bool attacking;
        bool jump;
        int damage;

    public:
        Entity(){}
        virtual ~Entity(){}

        virtual void loader(){};
        virtual void update(float dt) {}
        virtual void show(RenderWindow* window) {}

        void setKind(int aux){kind = aux;}
        const int getKind(){return kind;}
        const bool getDeletable();

        virtual Vector2f getPosition() = 0;
        void setPosition(Vector2f pos){posit = pos; sprite.setPosition(pos);}

        void setShowing(const bool val = true) { shouldShow = val; }
        bool getShowing() { return shouldShow; }
        
        int getLife() const{ return life; }
        Vector2f getSize(){return hitbox.getSize();}

        Vector2f getSpeed(){return speed;}
        void setSpeed(Vector2f new_speed){speed = new_speed;}

        void setHitbox(RectangleShape hit){hitbox = hit;}

        void take_damage(int damage);
};