#pragma  once

#include "stdafix.hpp"
#include "Entity.hpp"

using namespace sf;

class Character: public Entity{
    protected:

        float gravity = 0.05;
        List **sprite_list;
        Clock timer;

    public:
        Character();
        ~Character();

        virtual void update(float dt){};
        virtual void show(RenderWindow* window){};
        virtual Vector2f getPosition(){ return posit; };

};