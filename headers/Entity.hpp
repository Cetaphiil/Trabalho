#ifndef ENTITY_H_P_P_
#define ENTITY_H_P_P_

#include "lib.hpp"
#include "GraphicHandler.hpp"

using namespace sf;

class Entity{
    int kind;
protected:
    Graphics graphics;
    Texture texture;
    Sprite sprite;
    RectangleShape hitbox;

    int life;
    int damage;

    Vector2f posit, speed,acceleration;

public:

    Entity(){}
    virtual ~Entity(){}

    virtual void update(RenderWindow* window, float dt) {}
    virtual void show(RenderWindow* window) {}

    virtual void collide(Entity* other){}

    void setKind(int aux){kind = aux;}
    int getKind(){return kind;}

    virtual Vector2f getPosition() = 0;

    Vector2f getSize(){return hitbox.getSize();}

    //Vector2f getPosition() {return posit;}
    void setPosition(Vector2f pos){posit = pos; sprite.setPosition(pos);}
};



#endif