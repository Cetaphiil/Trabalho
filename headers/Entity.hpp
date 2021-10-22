#ifndef ENTITY_H_P_P_
#define ENTITY_H_P_P_

#include "lib.hpp"
#include "GraphicHandler.hpp"

using namespace sf;

class Entity{
    protected:
        Graphics graphics;
        Texture texture;
        Sprite sprite;
        int speed;
        int life = 10;
        int damage = 5;
        List **sprite_list;

    public:
        Entity(){}
        virtual ~Entity(){}
};

#endif