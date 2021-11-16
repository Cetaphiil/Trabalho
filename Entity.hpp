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
//        Collider collision = Collider(hitbox);

        int speed;
        int life = 10;
        int damage = 5;
        List **sprite_list;

    public:
        Entity(){}
        virtual ~Entity(){}
};



#endif