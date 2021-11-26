#pragma once

#include "stdafix.hpp"
#include "GraphicHandler.hpp"
#include "Obstacle.hpp"

class Spike : public Obstacle{
public:
    Spike(int kind);
    ~Spike(){}
    void load();

};