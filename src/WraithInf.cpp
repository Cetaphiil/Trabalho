#include "WraithInf.hpp"
#include "GraphicHandler.hpp"

static inline const char *enemy_spriteName_idle[] = {
    "../assets/sprites/Enemy/WraithInf/Idle/Wraith_idle_00.png",
    "../assets/sprites/Enemy/WraithInf/Idle/Wraith_idle_01.png",
    "../assets/sprites/Enemy/WraithInf/Idle/Wraith_idle_02.png",
    "../assets/sprites/Enemy/WraithInf/Idle/Wraith_idle_03.png",
    "../assets/sprites/Enemy/WraithInf/Idle/Wraith_idle_04.png",
    "../assets/sprites/Enemy/WraithInf/Idle/Wraith_idle_05.png",
    "../assets/sprites/Enemy/WraithInf/Idle/Wraith_idle_06.png",
    "../assets/sprites/Enemy/WraithInf/Idle/Wraith_idle_07.png",
    "../assets/sprites/Enemy/WraithInf/Idle/Wraith_idle_08.png",
    "../assets/sprites/Enemy/WraithInf/Idle/Wraith_idle_09.png",
    "../assets/sprites/Enemy/WraithInf/Idle/Wraith_idle_10.png",
    "../assets/sprites/Enemy/WraithInf/Idle/Wraith_idle_11.png"
};

static inline const char *enemy_spriteName_walking[]={
    "../assets/sprites/Enemy/WraithInf/Walking/Wraith_Walking_00.png",
    "../assets/sprites/Enemy/WraithInf/Walking/Wraith_Walking_01.png",
    "../assets/sprites/Enemy/WraithInf/Walking/Wraith_Walking_02.png",
    "../assets/sprites/Enemy/WraithInf/Walking/Wraith_Walking_03.png",
    "../assets/sprites/Enemy/WraithInf/Walking/Wraith_Walking_04.png",
    "../assets/sprites/Enemy/WraithInf/Walking/Wraith_Walking_05.png",
    "../assets/sprites/Enemy/WraithInf/Walking/Wraith_Walking_06.png",
    "../assets/sprites/Enemy/WraithInf/Walking/Wraith_Walking_07.png",
    "../assets/sprites/Enemy/WraithInf/Walking/Wraith_Walking_08.png",
    "../assets/sprites/Enemy/WraithInf/Walking/Wraith_Walking_09.png",
    "../assets/sprites/Enemy/WraithInf/Walking/Wraith_Walking_10.png",
    "../assets/sprites/Enemy/WraithInf/Walking/Wraith_Walking_11.png"
};

static inline const char *enemy_spriteName_Dying[]={
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_00.png",
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_01.png",
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_02.png",
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_03.png",
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_04.png",
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_05.png",
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_06.png",
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_07.png",
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_08.png",
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_09.png",
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_10.png",
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_11.png",
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_12.png",
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_13.png",
    "../assets/sprites/Enemy/WraithInf/Dying/Wraith_Dying_14.png"
};

WraithInf::WraithInf(Vector2f posit, int kind): Enemy(){
    setKind(kind);
    setPosition(posit);
    setShowing();
    damage = 15;
    loader();
}

void WraithInf::loader(){
    sprite_list = (List **) malloc(3 * sizeof(List *));

    for (int i = 0; i < 3; i++){
        sprite_list[i] = nullptr;
    }

    pGraphics->load_Textures(enemy_spriteName_idle, &sprite_list[0]);
    pGraphics->load_Textures(enemy_spriteName_walking, &sprite_list[1]);
    pGraphics->load_Textures(enemy_spriteName_Dying, &sprite_list[2]);
}

void WraithInf::update(float dt){
    aceleration = -1.f * speed;
    deltaTime = timer.restart().asSeconds();

    Vector2f distanciaMax = {350.0f , 350.0f};
    Vector2f playerPosit = player->getPosition();

    //Perseguir
    Vector2f space = {posit-playerPosit};
    if( (space.x * space.x)+(space.y * space.y) < (distanciaMax.x * distanciaMax.x) + (distanciaMax.y * distanciaMax.y)){
        aceleration -= 1.f * (posit - playerPosit);
    }

    //Atirar: Solicitar à fase para ela criar um projétil e lançar.


    Vector2f deltaSpeed = deltaTime * aceleration;
    Vector2f posDesejada = (speed + deltaSpeed) * deltaTime + posit;
    
    posit = posDesejada;
    speed = speed + deltaSpeed;
    if(Mouse::isButtonPressed(Mouse::Middle)){
        posit = {0.f, 0.f};
        speed = {0.f, 0.f};
    }
};

void WraithInf::show(RenderWindow *window){
    //Mudança de estado
    if (abs(speed.x) < 1.f && abs(speed.y) < 1.f) {
        sprite.setTexture(*(sprite_list[0]->texture));
        if (timer.getElapsedTime().asSeconds() > 0.17f) {
            sprite_list[0] = sprite_list[0]->next;
            timer.restart();
        }
    }
    if(abs(speed.x) > 0.9f){
        sprite.setTexture(*(sprite_list[1]->texture));
        if(timer.getElapsedTime().asSeconds() > 0.17f){
            sprite_list[1] = sprite_list[1]->next;
            timer.restart();
        }
    }
    else if (abs(speed.x) <= 0.9f && abs(speed.y) <= 0.9f) {
        sprite.setTexture(*(sprite_list[0]->texture));
        if (timer.getElapsedTime().asSeconds() > 0.17f) {
            sprite_list[0] = sprite_list[0]->next;
            timer.restart();
        }
    }
    if(speed.x < 0){
        sprite.setOrigin((sprite.getPosition()/4.f + sf::Vector2f {sprite.getLocalBounds().width, 0.f})*0.4f);
        sprite.setScale(-0.4,0.4);

    }
    else{
        sprite.setScale(0.4, 0.4);
    }
    sprite.setPosition(posit);
    window->draw(sprite);
}

Vector2f WraithInf::getPosition() {
    return posit;
}
