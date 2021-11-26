#include <Player.hpp>
#include <iostream>
#include "GraphicHandler.hpp"

static inline const char *idle_file_names[]= {
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
static inline const char *jump_file_names[]= {
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
static inline const char *walk_file_names[]= {
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
static inline const char *dead_file_names[]={
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
static inline const char *attack_file_names[]= {
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

Player::Player(): Character(){
}

Player::~Player(){
}

void Player::setSize() {
    hitbox.setSize({144.0f, 144.0f});
    hitbox.setOrigin({(hitbox.getSize().x /2), (hitbox.getSize().y/2)});
    setKind(1);
}

sf::Vector2f Player::getPosition(){
    return (posit);
}

void Player::loader() {
    sprite_list = (List **) malloc(5 * sizeof(List *));

    for (int i = 0; i < 5; i++)
        sprite_list[i] = NULL;

    pGraphics->load_Textures(idle_file_names, &sprite_list[0]);
    pGraphics->load_Textures(jump_file_names, &sprite_list[1]);
    pGraphics->load_Textures(walk_file_names, &sprite_list[2]);
    pGraphics->load_Textures(dead_file_names, &sprite_list[3]);
    pGraphics->load_Textures(attack_file_names, &sprite_list[4]);
}
void Player::show(RenderWindow* window) {

    sf::Sprite sprite;

    static List *texture_idle = sprite_list[0];
    static List *texture_jump = sprite_list[1];
    static List *texture_walk = sprite_list[2];
    static List *texture_dead = sprite_list[3];
    static List *texture_attack = sprite_list[4];


    if(attack){
        sprite.setTexture(*(texture_attack->texture));
        sprite.scale(1.2f, 1.2f);
        if (timer.getElapsedTime().asMilliseconds() > 60.f) {
            texture_attack = texture_attack->next;
            if(atk_timmer.getElapsedTime().asMilliseconds() > 600.f){
                attack = false;
            }
            else
                timer.restart();
        }

    }
    else if(abs(speed.y)>0.9f){
        sprite.setTexture(*(texture_jump->texture));
        if(timer.getElapsedTime().asSeconds() > 0.17f){
            texture_jump = texture_jump->next;
            timer.restart();
        }
    }
    else if(abs(speed.x)>0.9f){
        sprite.setTexture(*(texture_walk->texture));
        if(timer.getElapsedTime().asSeconds() > 0.17f){
            texture_walk = texture_walk->next;
            timer.restart();
        }
    }
    else if (abs(speed.x) <= 0.9f && abs(speed.y) <= 0.9f) {
        sprite.setTexture(*(texture_idle->texture));
        if (timer.getElapsedTime().asSeconds() > 0.17f) {
            texture_idle = texture_idle->next;
            timer.restart();
        }
    }
    if(speed.x < 0){
        sprite.setOrigin(sprite.getPosition() + sf::Vector2f {sprite.getLocalBounds().width, 0.f});
        sprite.scale(-1,1);

    }
    sprite.setPosition(posit);
    pGraphics->setViewPosition(FloatRect{(sprite.getPosition().x + (sprite.getPosition().x/2)), (sprite.getPosition().y + (sprite.getPosition().x/2)), static_cast<float>(pGraphics->getWindow()->getSize().x), static_cast<float>(pGraphics->getWindow()->getSize().y)});
    pGraphics->getWindow()->draw(sprite);
}

void Player::update(RenderWindow *window, float dt) {
    acceleration = -desaceleracao * speed;

    if (Keyboard::isKeyPressed(Keyboard::D)) {
        if(Keyboard::isKeyPressed(Keyboard::LShift))
            acceleration += {1.5f * player_speed, 0};
        else
            acceleration += {player_speed, 0};
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        if(Keyboard::isKeyPressed(Keyboard::LShift))
            acceleration -= {1.5f * player_speed, 0};
        else
            acceleration -= {player_speed, 0};
    }
    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        if (jump) {
            acceleration -= {0, player_jump};
            jump = false;
        }
    }
    if(Mouse::isButtonPressed(Mouse::Left)){
        if(atk_timmer.getElapsedTime().asSeconds() > 2){
            attack = true;
            atk_timmer.restart();
        }
    }
    Vector2f dv = dt * (acceleration+ gravity);
    Vector2f posDesejada = (speed + dv) * dt + posit;

    if (posDesejada.x < 0) {
        posDesejada.x = 0;
        speed.x = 0;
        dv.x = 0;
    }
    if (posDesejada.x + hitbox.getSize().x > pGraphics->getWindow()->getSize().x) {
        posDesejada.x = pGraphics->getWindow()->getSize().x - hitbox.getSize().x;
        speed.x = 0;
        dv.x = 0;
    }
    if (posDesejada.y < 0) {
        posDesejada.y = 0;
        speed.y = 0;
        dv.y = 0;
    }
    if (posDesejada.y + hitbox.getSize().y > pGraphics->getWindow()->getSize().y) {
        posDesejada.y = pGraphics->getWindow()->getSize().y - hitbox.getSize().y;
        speed.y = 0;
        dv.y = 0;
        jump = true;
    }
    posit = posDesejada;
    speed = speed + dv;

    // if (Mouse::isButtonPressed(Mouse::Middle)) {
    //     posit = {0.f, 700.f};
    //     speed = {0.f, 0.f};
    // }

    // if(Keyboard::isKeyPressed(Keyboard::Numpad9)){
    //     gravity.y += 2.f;
    //     printf("Gravidade alterada para: %f\n", gravity.y);
    // }
    // if(Keyboard::isKeyPressed(Keyboard::Numpad7)){
    //     gravity.y -= 2.f;
    //     printf("Gravidade alterada para: %f\n", gravity.y);
    // }
    // if(Keyboard::isKeyPressed(Keyboard::Numpad6)){
    //     player_speed += 2.f;
    //     printf("Velocidade de player alterada para: %f\n", player_speed);
    // }
    // if(Keyboard::isKeyPressed(Keyboard::Numpad4)){
    //     player_speed -= 2.f;
    //     printf("Velocidade de player alterada para: %f\n", player_speed);
    // }
    // if(Keyboard::isKeyPressed(Keyboard::Numpad3)){
    //     player_jump += 20.f;
    //     printf("Altura do pulo de player alterada para: %f\n", player_jump);
    // }
    // if(Keyboard::isKeyPressed(Keyboard::Numpad1)){
    //     player_jump -= 20.f;
    //     printf("Altura do pulo de player alterada para: %f\n", player_jump);
    // }
    // if(Keyboard::isKeyPressed(Keyboard::Numpad8)){
    //     desaceleracao += 2.f;
    //     printf("Desaceleração alterada para: %f\n", desaceleracao);
    // }
    // if(Keyboard::isKeyPressed(Keyboard::Numpad2)){
    //     desaceleracao -= 2.f;
    //     printf("Desaceleração alterada para: %f\n", desaceleracao);
    // }
//    printf("%f %f\n", s.x, s.y);
}

void Player::collide(Entity *other) {
    switch (other->getKind()){
        case 2:
            if(invincibility.getElapsedTime().asSeconds() > 2) {
                this->life -= other->damage;
                std::cout << "Player life is now: " << this->life << std::endl;
                invincibility.restart();
            }
    }
}

View Player::getView1(){ return view1; };