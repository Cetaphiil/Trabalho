#include <Enemy.hpp>
#include "GraphicHandler.hpp"

Enemy::Enemy(): Character(){
    srand(time(NULL));
};

static inline const char *enemy_spriteName_idle[] = {
    "../assets/sprites/Enemy/Wraith/Idle/Wraith_idle_00.png",
    "../assets/sprites/Enemy/Wraith/Idle/Wraith_idle_01.png",
    "../assets/sprites/Enemy/Wraith/Idle/Wraith_idle_02.png",
    "../assets/sprites/Enemy/Wraith/Idle/Wraith_idle_03.png",
    "../assets/sprites/Enemy/Wraith/Idle/Wraith_idle_04.png",
    "../assets/sprites/Enemy/Wraith/Idle/Wraith_idle_05.png",
    "../assets/sprites/Enemy/Wraith/Idle/Wraith_idle_06.png",
    "../assets/sprites/Enemy/Wraith/Idle/Wraith_idle_07.png",
    "../assets/sprites/Enemy/Wraith/Idle/Wraith_idle_08.png",
    "../assets/sprites/Enemy/Wraith/Idle/Wraith_idle_09.png",
    "../assets/sprites/Enemy/Wraith/Idle/Wraith_idle_10.png",
    "../assets/sprites/Enemy/Wraith/Idle/Wraith_idle_11.png"
};

static inline const char *enemy_spriteName_walking[]={
    "../assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_00.png",
    "../assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_01.png",
    "../assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_02.png",
    "../assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_03.png",
    "../assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_04.png",
    "../assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_05.png",
    "../assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_06.png",
    "../assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_07.png",
    "../assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_08.png",
    "../assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_09.png",
    "../assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_10.png",
    "../assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_11.png"
};

static inline const char *enemy_spriteName_Dying[]={
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_00.png",
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_01.png",
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_02.png",
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_03.png",
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_04.png",
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_05.png",
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_06.png",
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_07.png",
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_08.png",
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_09.png",
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_10.png",
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_11.png",
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_12.png",
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_13.png",
    "../assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_14.png"
};

static inline const char *enemy_spriteName_Spell[]={
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_00.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_01.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_02.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_03.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_04.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_05.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_06.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_07.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_08.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_09.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_10.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_11.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_12.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_13.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_14.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_15.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_16.png",
    "../assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_17.png"
};

void Enemy::sprite_loader(){
    sprite_list = (List **) malloc(4 * sizeof(List *));

    for (int i = 0; i < 4; i++){
        sprite_list[i] = nullptr;
    }

    pGraphics->load_Textures(enemy_spriteName_idle, &sprite_list[0]);
    pGraphics->load_Textures(enemy_spriteName_walking, &sprite_list[1]);
    pGraphics->load_Textures(enemy_spriteName_Dying, &sprite_list[2]);
    pGraphics->load_Textures(enemy_spriteName_Spell, &sprite_list[3]);
};

void Enemy::initEnemies(Vector2i resolucao){
    spawn = true;
    Vector2i halfRes = resolucao/2;
    posit = Vector2f((float) (rand() % (static_cast<int>(resolucao.x)/4)+halfRes.x), (float) (rand() % static_cast<int>(resolucao.y)/2));
};

void Enemy::update(RenderWindow *window, float dt){
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
    //Não Passar da borda
     if (posDesejada.x < 0) {
         posDesejada.x = 0;
         speed.x = 0;
     }
     if (posDesejada.x + sprite.getTexture()->getSize().x/4 > window->getSize().x+50) {
         posDesejada.x = window->getSize().x - (sprite.getTexture()->getSize().x/2);
         speed.x = 0;
     }
     if (posDesejada.y < 0) {
         posDesejada.y = 0;
         speed.y = 0;
     }
     if (posDesejada.y + sprite.getTexture()->getSize().y/4 > window->getSize().y) {
         posDesejada.y = window->getSize().y - sprite.getTexture()->getSize().y*0.6;
         speed.y = 0;
     }
    posit = posDesejada;
    speed = speed + deltaSpeed;
    if(Mouse::isButtonPressed(Mouse::Middle)){
        posit = {0.f, 0.f};
        speed = {0.f, 0.f};
    }
};

void Enemy::show(RenderWindow *window){
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
//    printf("%f, %f\n", posit.x, posit.y);
    sprite.setPosition(posit);
    window->draw(sprite);
}

Vector2f Enemy::getPosition() {
    return posit;
}

void Enemy::collide(Entity *other) {
    switch (other->getKind()){
        case 1:
            if(invincibility.getElapsedTime().asSeconds() > 2) {
                if(other->attacking) {
                    this->life -= other->damage;
                    std::cout << "Enemy life is now: " << this->life << std::endl;
                    invincibility.restart();
                }
            }
    }
}
