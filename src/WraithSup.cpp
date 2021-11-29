#include "WraithSup.hpp"
#include "GraphicHandler.hpp"

static inline const char *enemy_spriteName_idle[] = {
    "../assets/sprites/Enemy/WraithSup/Idle/Wraith_02_idle_000.png",
    "../assets/sprites/Enemy/WraithSup/Idle/Wraith_02_idle_001.png",
    "../assets/sprites/Enemy/WraithSup/Idle/Wraith_02_idle_002.png",
    "../assets/sprites/Enemy/WraithSup/Idle/Wraith_02_idle_003.png",
    "../assets/sprites/Enemy/WraithSup/Idle/Wraith_02_idle_004.png",
    "../assets/sprites/Enemy/WraithSup/Idle/Wraith_02_idle_005.png",
    "../assets/sprites/Enemy/WraithSup/Idle/Wraith_02_idle_006.png",
    "../assets/sprites/Enemy/WraithSup/Idle/Wraith_02_idle_007.png",
    "../assets/sprites/Enemy/WraithSup/Idle/Wraith_02_idle_008.png",
    "../assets/sprites/Enemy/WraithSup/Idle/Wraith_02_idle_009.png",
    "../assets/sprites/Enemy/WraithSup/Idle/Wraith_02_idle_010.png",
    "../assets/sprites/Enemy/WraithSup/Idle/Wraith_02_idle_011.png"
};

static inline const char *enemy_spriteName_walking[]={
    "../assets/sprites/Enemy/WraithSup/Walking/Wraith_02_Moving Forward_000.png",
    "../assets/sprites/Enemy/WraithSup/Walking/Wraith_02_Moving Forward_001.png",
    "../assets/sprites/Enemy/WraithSup/Walking/Wraith_02_Moving Forward_002.png",
    "../assets/sprites/Enemy/WraithSup/Walking/Wraith_02_Moving Forward_003.png",
    "../assets/sprites/Enemy/WraithSup/Walking/Wraith_02_Moving Forward_004.png",
    "../assets/sprites/Enemy/WraithSup/Walking/Wraith_02_Moving Forward_005.png",
    "../assets/sprites/Enemy/WraithSup/Walking/Wraith_02_Moving Forward_006.png",
    "../assets/sprites/Enemy/WraithSup/Walking/Wraith_02_Moving Forward_007.png",
    "../assets/sprites/Enemy/WraithSup/Walking/Wraith_02_Moving Forward_008.png",
    "../assets/sprites/Enemy/WraithSup/Walking/Wraith_02_Moving Forward_009.png",
    "../assets/sprites/Enemy/WraithSup/Walking/Wraith_02_Moving Forward_010.png"
    "../assets/sprites/Enemy/WraithSup/Walking/Wraith_02_Moving Forward_011.png",
};

static inline const char *enemy_spriteName_Dying[]={
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_000.png",
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_001.png",
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_002.png",
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_003.png",
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_004.png",
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_005.png",
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_006.png",
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_007.png",
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_008.png",
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_009.png",
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_010.png",
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_011.png",
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_012.png",
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_013.png",
   "../assets/sprites/Enemy/WraithSup/Dying/Wraith_02_Dying_014.png"
};

WraithSup::WraithSup(Vector2f posit, int kind): Enemy(){
    setKind(kind);
    setPosition(posit);
    setShowing();
    damage = 20;
    loader();
}

void WraithSup::loader(){
    sprite_list = (List **) malloc(3 * sizeof(List *));

    for (int i = 0; i < 3; i++){
        sprite_list[i] = nullptr;
    }

    pGraphics->load_Textures(enemy_spriteName_idle, &sprite_list[0]);
    pGraphics->load_Textures(enemy_spriteName_walking, &sprite_list[1]);
    pGraphics->load_Textures(enemy_spriteName_Dying, &sprite_list[2]);
}

void WraithSup::update(float dt){
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

void WraithSup::show(RenderWindow *window){
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

Vector2f WraithSup::getPosition() {
    return posit;
}
