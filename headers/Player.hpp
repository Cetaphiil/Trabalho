#pragma once

#include <Character.hpp>
#include "CollisionHandler.hpp"
#include "stdafix.hpp"

using namespace sf;

class Player : public Character{
private:
    View view1;
    float player_speed = 8000;
    float player_jump;
    float desaceleracao = 20;

    bool jump = false;
    bool attack = false;

    Clock atk_timmer;


    void load_idle();
    void load_jump();
    void load_walk();
    void load_dead();
    void load_attack();

public:
    Player();
    ~Player();
    void loader();
    sf::Vector2f getPosition();
    void show();
    void update(float dt);

    void collide(Entity* other);


    Player* getPlayer(){return this;};
    void setSize();

    View getView1();
};