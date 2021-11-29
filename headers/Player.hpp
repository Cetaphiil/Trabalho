#pragma once

#include <Character.hpp>
#include "CollisionHandler.hpp"
#include "stdafix.hpp"
#include "Lifebar.hpp"

using namespace sf;

class Player : public Character{
private:
    float player_speed = 0.015;
    float player_jump = 150;
    bool attack = false;

    Clock atk_timmer;

    Lifebar *lifebar;

    void die();

public:
    Player();
    ~Player();
    void loader();
    
    void show(RenderWindow *window) override;
    void update(float dt) override;

    Vector2f getPosition() override;

    void restart();
};