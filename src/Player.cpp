//
// Created by Lucas Orlikoski on 14/07/2021.
//
#include <Player.hpp>
#include <iostream>

char *idle_file_names[]= {
        "../assets/sprites/Player/Idle/Idle__000.png",
        "../assets/sprites/Player/Idle/Idle__001.png",
        "../assets/sprites/Player/Idle/Idle__002.png",
        "../assets/sprites/Player/Idle/Idle__003.png",
        "../assets/sprites/Player/Idle/Idle__004.png",
        "../assets/sprites/Player/Idle/Idle__005.png",
        "../assets/sprites/Player/Idle/Idle__006.png",
        "../assets/sprites/Player/Idle/Idle__007.png",
        "../assets/sprites/Player/Idle/Idle__008.png",
        "../assets/sprites/Player/Idle/Idle__009.png"
};
char *jump_file_names[]= {
        "../assets/sprites/Player/Jump/Jump__000.png",
        "../assets/sprites/Player/Jump/Jump__001.png",
        "../assets/sprites/Player/Jump/Jump__002.png",
        "../assets/sprites/Player/Jump/Jump__003.png",
        "../assets/sprites/Player/Jump/Jump__004.png",
        "../assets/sprites/Player/Jump/Jump__005.png",
        "../assets/sprites/Player/Jump/Jump__006.png",
        "../assets/sprites/Player/Jump/Jump__007.png",
        "../assets/sprites/Player/Jump/Jump__008.png",
        "../assets/sprites/Player/Jump/Jump__009.png"
};
char *walk_file_names[]= {
        "../assets/sprites/Player/Run/Run__000.png",
        "../assets/sprites/Player/Run/Run__001.png",
        "../assets/sprites/Player/Run/Run__002.png",
        "../assets/sprites/Player/Run/Run__003.png",
        "../assets/sprites/Player/Run/Run__004.png",
        "../assets/sprites/Player/Run/Run__005.png",
        "../assets/sprites/Player/Run/Run__006.png",
        "../assets/sprites/Player/Run/Run__007.png",
        "../assets/sprites/Player/Run/Run__008.png",
        "../assets/sprites/Player/Run/Run__009.png"
};
char *dead_file_names[]= {
        "../assets/sprites/Player/dead/Dead__000.png",
        "../assets/sprites/Player/dead/Dead__001.png",
        "../assets/sprites/Player/dead/Dead__002.png",
        "../assets/sprites/Player/dead/Dead__003.png",
        "../assets/sprites/Player/dead/Dead__004.png",
        "../assets/sprites/Player/dead/Dead__005.png",
        "../assets/sprites/Player/dead/Dead__006.png",
        "../assets/sprites/Player/dead/Dead__007.png",
        "../assets/sprites/Player/dead/Dead__008.png",
        "../assets/sprites/Player/dead/Dead__009.png"
};
char *attack_file_names[]= {
        "../assets/sprites/Player/attack/Attack__000.png",
        "../assets/sprites/Player/attack/Attack__001.png",
        "../assets/sprites/Player/attack/Attack__002.png",
        "../assets/sprites/Player/attack/Attack__003.png",
        "../assets/sprites/Player/attack/Attack__004.png",
        "../assets/sprites/Player/attack/Attack__005.png",
        "../assets/sprites/Player/attack/Attack__006.png",
        "../assets/sprites/Player/attack/Attack__007.png",
        "../assets/sprites/Player/attack/Attack__008.png",
        "../assets/sprites/Player/attack/Attack__009.png"
};


sf::Vector2f Player::getPosition(){
    return (s);
}


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
    aux->texture->loadFromFile(idle_file_names[0]);
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
    aux->texture->loadFromFile(jump_file_names[0]);
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


    if(attack){
        sprite.setTexture(*(texture_attack->texture));
        sprite.scale(1.2f, 1.2f);
        if (c.getElapsedTime().asMilliseconds() > 60.f) {
            texture_attack = texture_attack->next;
            if(atk_timmer.getElapsedTime().asMilliseconds() > 600.f){
                attack = false;
            }
            else
                c.restart();
        }

    }
    else if(abs(v.y)>0.9f){
        sprite.setTexture(*(texture_jump->texture));
        if(c.getElapsedTime().asSeconds() > 0.17f){
            texture_jump = texture_jump->next;
            c.restart();
        }
    }
    else if(abs(v.x)>0.9f){
        sprite.setTexture(*(texture_walk->texture));
        if(c.getElapsedTime().asSeconds() > 0.17f){
            texture_walk = texture_walk->next;
            c.restart();
        }
    }
    else if (abs(v.x) <= 0.9f && abs(v.y) <= 0.9f) {
        sprite.setTexture(*(texture_idle->texture));
        if (c.getElapsedTime().asSeconds() > 0.17f) {
            texture_idle = texture_idle->next;
            c.restart();
        }
    }
    if(v.x < 0){
        sprite.setOrigin(sprite.getPosition() + sf::Vector2f {sprite.getLocalBounds().width, 0.f});
        sprite.scale(-1,1);

    }
    sprite.setPosition(s);

    window->draw(sprite);
}

void Player::update(RenderWindow *window, float dt) {
    a = -desaceleracao * v;

    if (Keyboard::isKeyPressed(Keyboard::D)) {
        if(Keyboard::isKeyPressed(Keyboard::LShift))
            a += {1.5f * player_speed, 0};
        else
            a += {player_speed, 0};
        idle = false;
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        if(Keyboard::isKeyPressed(Keyboard::LShift))
            a -= {1.5f * player_speed, 0};
        else
            a -= {player_speed, 0};
        idle = false;
    }
    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        if (jump) {
            a -= {0, player_jump};
            jump = false;
        }
    }
    if(Mouse::isButtonPressed(Mouse::Left)){
        if(atk_timmer.getElapsedTime().asSeconds() > 2){
            attack = true;
            atk_timmer.restart();
        }
    }
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
        jump = true;
    }
    s = posDesejada;
    v = v + dv;
//    if(s.y >= (window->getSize().y - 170.f))
//        jump = true;

    if (Mouse::isButtonPressed(Mouse::Middle)) {
        s = {0.f, 700.f};
        v = {0.f, 0.f};
    }

    if(Keyboard::isKeyPressed(Keyboard::Numpad9)){
        g.y += 2.f;
        printf("Gravidade alterada para: %f\n", g.y);
    }
    if(Keyboard::isKeyPressed(Keyboard::Numpad7)){
        g.y -= 2.f;
        printf("Gravidade alterada para: %f\n", g.y);
    }
    if(Keyboard::isKeyPressed(Keyboard::Numpad6)){
        player_speed += 2.f;
        printf("Velocidade de player alterada para: %f\n", player_speed);
    }
    if(Keyboard::isKeyPressed(Keyboard::Numpad4)){
        player_speed -= 2.f;
        printf("Velocidade de player alterada para: %f\n", player_speed);
    }
    if(Keyboard::isKeyPressed(Keyboard::Numpad3)){
        player_jump += 20.f;
        printf("Altura do pulo de player alterada para: %f\n", player_jump);
    }
    if(Keyboard::isKeyPressed(Keyboard::Numpad1)){
        player_jump -= 20.f;
        printf("Altura do pulo de player alterada para: %f\n", player_jump);
    }
    if(Keyboard::isKeyPressed(Keyboard::Numpad8)){
        desaceleracao += 2.f;
        printf("Desaceleração alterada para: %f\n", desaceleracao);
    }
    if(Keyboard::isKeyPressed(Keyboard::Numpad2)){
        desaceleracao -= 2.f;
        printf("Desaceleração alterada para: %f\n", desaceleracao);
    }
//    printf("%f %f\n", s.x, s.y);
}