#ifndef ENTITY_H_P_P_
#define ENTITY_H_P_P_

#include "lib.hpp"
#include "GraphicHandler.hpp"
#include "CollisionHandler.hpp"

using namespace sf;

class Entity{
    protected:
        Graphics graphics;
        Texture texture;
        Sprite sprite;
        RectangleShape *hitbox;

        int speed;
        int life;
        int damage;
        List **sprite_list;

    public:
        Entity(){}
        virtual ~Entity(){}
};



#endif