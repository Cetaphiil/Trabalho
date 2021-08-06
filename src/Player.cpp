//
// Created by Lucas Orlikoski on 14/07/2021.
//
#include "Player.h"
#include <iostream>
#include <time.h>


char *idle_file_names[] = {
        "images/Idle__000.png",
        "images/Idle__001.png",
        "images/Idle__002.png",
        "images/Idle__003.png",
        "images/Idle__004.png",
        "images/Idle__005.png",
        "images/Idle__006.png",
        "images/Idle__007.png",
        "images/Idle__008.png",
        "images/Idle__009.png"
};
char *jump_file_names[] = {
        "images/Jump__000.png",
        "images/Jump__001.png",
        "images/Jump__002.png",
        "images/Jump__003.png",
        "images/Jump__004.png",
        "images/Jump__005.png",
        "images/Jump__006.png",
        "images/Jump__007.png",
        "images/Jump__008.png",
        "images/Jump__009.png"
};
char *walk_file_names[] = {
        "images/Run__000.png",
        "images/Run__001.png",
        "images/Run__002.png",
        "images/Run__003.png",
        "images/Run__004.png",
        "images/Run__005.png",
        "images/Run__006.png",
        "images/Run__007.png",
        "images/Run__008.png",
        "images/Run__009.png"
};
char *dead_file_names[] = {
        "images/Dead__000.png",
        "images/Dead__001.png",
        "images/Dead__002.png",
        "images/Dead__003.png",
        "images/Dead__004.png",
        "images/Dead__005.png",
        "images/Dead__006.png",
        "images/Dead__007.png",
        "images/Dead__008.png",
        "images/Dead__009.png"
};
char *attack_file_names[] = {
        "images/Attack__000.png",
        "images/Attack__001.png",
        "images/Attack__002.png",
        "images/Attack__003.png",
        "images/Attack__004.png",
        "images/Attack__005.png",
        "images/Attack__006.png",
        "images/Attack__007.png",
        "images/Attack__008.png",
        "images/Attack__009.png"
};

List *Player::add_sprite(List *list) {
    List *n = (List *) malloc(sizeof(List));
    n->next = NULL;
    if (list == NULL)
        return n;
    List *aux = list;
    while (aux->next != NULL)
        aux = aux->next;
    aux->next = n;
    return list;
}

void Player::load_idle() {
    List *aux = NULL;
    aux = add_sprite(aux);
    sprite_list[0] = aux;
    aux->texture = new sf::Texture;
    aux->texture->loadFromFile("images/Idle__000.png");
    for (int i = 1; i < 10; i++) {
        add_sprite(sprite_list[0]);
        aux = aux->next;
        aux->texture = new sf::Texture;
        aux->texture->loadFromFile(idle_file_names[i]);
    }
    aux->next = sprite_list[0];
}

void Player::load_jump() {
    List *aux = NULL;
    aux = add_sprite(aux);
    sprite_list[1] = aux;
    aux->texture = new sf::Texture;
    aux->texture->loadFromFile("images/Jump__000.png");
    for (int i = 1; i < 10; i++) {
        add_sprite(sprite_list[1]);
        aux = aux->next;
        aux->texture = new sf::Texture;
        aux->texture->loadFromFile(jump_file_names[i]);
    }
    aux->next = sprite_list[1];
}

void Player::load_walk() {
    List *aux = NULL;
    aux = add_sprite(aux);
    sprite_list[2] = aux;
    aux->texture = new sf::Texture;
    aux->texture->loadFromFile(walk_file_names[0]);
    for (int i = 1; i < 10; i++) {
        add_sprite(sprite_list[2]);
        aux = aux->next;
        aux->texture = new sf::Texture;
        aux->texture->loadFromFile(walk_file_names[i]);
    }
    aux->next = sprite_list[2];
}

void Player::load_dead() {
    List *aux = NULL;
    aux = add_sprite(aux);
    sprite_list[3] = aux;
    aux->texture = new sf::Texture;
    aux->texture->loadFromFile(dead_file_names[0]);
    for (int i = 1; i < 10; i++) {
        add_sprite(sprite_list[3]);
        aux = aux->next;
        aux->texture = new sf::Texture;
        aux->texture->loadFromFile(dead_file_names[i]);
    }
    aux->next = sprite_list[3];
}

void Player::load_attack() {
    List *aux = NULL;
    aux = add_sprite(aux);
    sprite_list[4] = aux;
    aux->texture = new sf::Texture;
    aux->texture->loadFromFile(attack_file_names[0]);
    for (int i = 1; i < 10; i++) {
        add_sprite(sprite_list[4]);
        aux = aux->next;
        aux->texture = new sf::Texture;
        aux->texture->loadFromFile(attack_file_names[i]);
    }
    aux->next = sprite_list[4];
}

void Player::loader() {
    sprite_list = (List **) malloc(5 * sizeof(List *));

    for (int i = 0; i < 5; i++)
        sprite_list[i] = NULL;

    //std::set < std::string, std::list <sf::Sprite> >

    load_idle();
    load_jump();
    load_walk();
    load_dead();
    load_attack();


}

using namespace sf;

void Player::show(RenderWindow *window) {

    sf::Sprite sprite;

    static List *texture_idle = sprite_list[0];
    static List *texture_jump = sprite_list[1];
    static List *texture_walk = sprite_list[2];
    static List *texture_dead = sprite_list[3];
    static List *texture_attack = sprite_list[4];

    if (abs(v.x) == 0.0f && abs(v.y) == 0.0f) {
        sprite.setTexture(*(texture_idle->texture));
        if (c.getElapsedTime().asSeconds() > 0.17f) {
            texture_idle = texture_idle->next;
            c.restart();
        }
    }
    else if(abs(v.y)>0.0f){
        sprite.setTexture(*(texture_jump->texture));
        if(c.getElapsedTime().asSeconds() > 0.17f){
            texture_jump = texture_jump->next;
            c.restart();
        }
    }
    else if(abs(v.x)>0.0f){
        sprite.setTexture(*(texture_walk->texture));
        if(c.getElapsedTime().asSeconds() > 0.17f){
            texture_walk = texture_walk->next;
            c.restart();
        }
    }
    if(v.x<0.0f){
        sprite.setOrigin(sprite.getPosition() + sf::Vector2f {sprite.getLocalBounds().width, 0.f});
        sprite.scale(-1,1);

    }
    sprite.setPosition(s);



    window->draw(sprite);
}

void Player::update(RenderWindow *window) {
    bool jump = false;
    bool idle = true;


    Vector2f g = {0.0f, 3000};
    a = -250.5f * v;


    //Vector2f MousePosition = {(float)Mouse::getPosition(*window).x,(float)Mouse::getPosition(*window).y};
    //Vector2f PlayerPosition = sprite.getPosition();

    if (s.y >= 566) {
        jump = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::D)) {
        a += {50000, 0};
        idle = false;
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        a -= {50000, 0};
        idle = false;
    }
    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        if (jump) {
            a -= {0, 50000};
            idle = false;
        }
    }
    float dt = t.restart().asSeconds();
    Vector2f dv = dt * (a + g);
    Vector2f posDesejada = (v + dv) * dt + s;

    if (posDesejada.x < 0) {
        posDesejada.x = 0;
        v.x = 0;
        dv.x = 0;
    }
    if (posDesejada.x + hitbox.width > window->getSize().x) {
        posDesejada.x = window->getSize().x - hitbox.width;
        v.x = 0;
        dv.x = 0;
    }
    if (posDesejada.y < 0) {
        posDesejada.y = 0;
        v.y = 0;
        dv.y = 0;
    }
    if (posDesejada.y + hitbox.height > window->getSize().y) {
        posDesejada.y = window->getSize().y - hitbox.height;
        v.y = 0;
        dv.y = 0;
    }
    s = posDesejada;
    v = v + dv;

    if (Mouse::isButtonPressed(Mouse::Middle)) {
        s = {0.f, 500.f};
        v = {0.f, 0.f};
    }
    printf("%f %f\n", s.x, s.y);
}