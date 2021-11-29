#pragma once
#include "stdafix.hpp"
#include "Enemy.hpp"

class GraphicHandler;

class WraithQueen: public Enemy{
    public:
        WraithQueen(Vector2f posit, int kind);
        ~WraithQueen(){};

        void loader();
        void show(RenderWindow *window);
        void update(float dt);
        Vector2f getPosition();

};