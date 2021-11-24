#pragma  once

#include "stdafix.hpp"
#include "Entity.hpp"

using namespace sf;

class Character: public Entity{
    protected:

        Vector2f gravity{0.0f, 7000.f};
        List **sprite_list;
        Clock timer;

    public:
        Character();
        ~Character();

        virtual void update(RenderWindow* window, float dt){}
        virtual void show(RenderWindow* window){}
        virtual Vector2f getPosition(){ return possit; }

        virtual void collide(Entity* other){}

};