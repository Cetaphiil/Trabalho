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
    bool dying = false;

    Clock atk_timer;
    Clock die_timer;

//    void load_idle();
//    void load_jump();
//    void load_walk();
//    void load_dead();
//    void load_attack();

    void die();

public:
    Player();
    ~Player() {}

    void loader();
    void show(RenderWindow* window) override;
    void update(RenderWindow* window, float dt) override;
    void collide(Entity* other) override;

    sf::Vector2f getPosition() override;
    Player* getPlayer(){return this;}
    void setSize();

    View getView1(){return view1;}
};