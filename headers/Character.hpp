#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Entity.hpp"
#include "lib.hpp"

using namespace sf;

class Character: public Entity{
protected:

    Vector2f gravity {0.0f, 7000.f};
    List **sprite_list;
    Clock timer;

public:
    Character() : Entity(){}
    ~Character(){}

    virtual void update(RenderWindow* window, float dt){}
    virtual void show(RenderWindow* window){}
    virtual Vector2f getPosition(){return posit;}

    virtual void collide(Entity* other){}
};


#endif
