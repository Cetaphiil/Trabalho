#pragma once
#include "stdafix.hpp"
#include "Enemy.hpp"

class GraphicHandler;

class WraithSup: public Enemy{
    public:
        WraithSup(Vector2f posit, int kind);
        ~WraithSup(){};

        void loader();
        void show(RenderWindow *window);
        void update(float dt);
        Vector2f getPosition();

};