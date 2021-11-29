#pragma once
#include "stdafix.hpp"
#include "Enemy.hpp"

class GraphicHandler;

class WraithInf: public Enemy{
    public:
        WraithInf(Vector2f posit, int kind);
        ~WraithInf(){};

        void loader();
        void show(RenderWindow *window);
        void update(float dt);
        Vector2f getPosition();

};