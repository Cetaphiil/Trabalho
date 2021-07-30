//
// Created by Lucas Orlikoski on 14/07/2021.
//
#include "Player.h"
#include <iostream>

using namespace sf;
void Player::loader(){
    if(!texture.loadFromFile("images/samurai1.png")){
        exit (1);
    }
    texture.loadFromFile("images/samurai1.png");
    sprite.setTexture(texture);
}
void Player::show(RenderWindow *window){
    window->draw(sprite);
}
void Player::update(RenderWindow *window){

    float g = 0.3f;
    a = -1.5f*v;

    Vector2f MousePosition = {(float)Mouse::getPosition(*window).x,(float)Mouse::getPosition(*window).y};
    Vector2f PlayerPosition = sprite.getPosition();

    if(Mouse::isButtonPressed(Mouse::Left)){
        a += MousePosition - PlayerPosition;
    }
    else if(Mouse::isButtonPressed(Mouse::Right)){
            a += 1.f * (PlayerPosition - MousePosition);
    }
    if(Keyboard::isKeyPressed(Keyboard::D)){
        a += {120, 0};
    }
    if(Keyboard::isKeyPressed(Keyboard::A)){
        a += {-120 , 0};
    }
    float dt = t.restart().asSeconds();
    Vector2f dv = dt*a;
    Vector2f posDesejada = (v + dv) * dt + s;
    if(posDesejada.x < 0){
        posDesejada.x = 0;
    }
    if(posDesejada.x + sprite.getTexture()->getSize().x > window->getSize().x){
        posDesejada.x = window->getSize().x - sprite.getTexture()->getSize().x;
    }
    if(posDesejada.y < 0){
        posDesejada.y = 0;
    }
    if(posDesejada.y + sprite.getTexture()->getSize().y > window->getSize().y){
        posDesejada.y = window->getSize().y - sprite.getTexture()->getSize().y;
    }
    s = posDesejada;
    v = v + dv;
    if(Mouse::isButtonPressed(Mouse::Middle)){
        s = {0.f, 500.f};
        v = {0.f, 0.f};
    }

    sprite.setPosition(s);
    printf("%f\n", (v.x * v.x)+(v.y * v.y));
}