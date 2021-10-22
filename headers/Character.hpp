#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Entity.hpp"


#include <SFML/Graphics.hpp>

using namespace sf;

class Character: public Entity{
    protected:
        Vector2f posit, speed, aceleration;
        Vector2f gravity {0.0f, 7000.f};
        int life = 10, damage = 5;
        FloatRect hitbox;
        List **sprite_list;
        Clock timer;
    public:

};


#endif
