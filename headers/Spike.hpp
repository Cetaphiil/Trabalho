//
// Created by lucas on 25/11/2021.
//
#pragma once

#include "Obstacle.hpp"

class Spike : public Obstacle{
public:
    Spike(int kind);
    ~Spike(){}
    void load();

};