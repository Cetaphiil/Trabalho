#include <Enemy.hpp>

Enemy::Enemy(){
};

char *enemy_spriteName[]={
    "assets/sprites/Enemy/Wraith/Idle/Wraith_idle_00.png",
    "assets/sprites/Enemy/Wraith/Idle/Wraith_idle_01.png",
    "assets/sprites/Enemy/Wraith/Idle/Wraith_idle_02.png",
    "assets/sprites/Enemy/Wraith/Idle/Wraith_idle_03.png",
    "assets/sprites/Enemy/Wraith/Idle/Wraith_idle_04.png",
    "assets/sprites/Enemy/Wraith/Idle/Wraith_idle_05.png",
    "assets/sprites/Enemy/Wraith/Idle/Wraith_idle_06.png",
    "assets/sprites/Enemy/Wraith/Idle/Wraith_idle_07.png",
    "assets/sprites/Enemy/Wraith/Idle/Wraith_idle_08.png",
    "assets/sprites/Enemy/Wraith/Idle/Wraith_idle_09.png",
    "assets/sprites/Enemy/Wraith/Idle/Wraith_idle_10.png",
    "assets/sprites/Enemy/Wraith/Idle/Wraith_idle_11.png"
};

char *enemy_spriteName[]={
    "assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_00.png",
    "assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_01.png",
    "assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_02.png",
    "assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_03.png",
    "assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_04.png",
    "assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_05.png",
    "assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_06.png",
    "assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_07.png",
    "assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_08.png",
    "assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_09.png",
    "assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_10.png",
    "assets/sprites/Enemy/Wraith/Walking/Wraith_Walking_11.png"
};

char *enemy_spriteName[]={
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_00.png",
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_01.png",
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_02.png",
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_03.png",
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_04.png",
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_05.png",
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_06.png",
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_07.png",
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_08.png",
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_09.png",
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_10.png",
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_11.png",
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_12.png",
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_13.png",
    "assets/sprites/Enemy/Wraith/Dying/Wraith_Dying_14.png"
};

char *enemy_spriteName[]={
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_00.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_01.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_02.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_03.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_04.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_05.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_06.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_07.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_08.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_09.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_10.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_11.png"
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_12.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_13.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_14.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_15.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_16.png",
    "assets/sprites/Enemy/Wraith/Spell/Wraith_Spell_17.png"
};

void Enemy::initEnemie(){
    for(int i; i<4; i++){
        grafo.loader();
    }
    //enemySprite.setPosition(rand() % static_cast<int>(resolucao.x - (enemyTexture.getSize().x/3)), rand() % static_cast<int>(resolucao.y - (enemyTexture.getSize().y/3)));
};

void Enemy::updateEnemy(RenderWindow *window, Player player){
    float gravity = 0.3f;
    aceleration = -1.f * speed;
    float deltaTime = keyPressTime.restart().asSeconds();
    bool idle = true;
    static Clock time;

    Vector2f distanciaMax = {100.0f , 100.0f};
    Vector2f playerPosit = player.sprite.getPosition();
    
   

    static List *texture_idle = enemy_sprite_list[0];
    static List *texture_walk = enemy_sprite_list[1];
    static List *texture_dead = enemy_sprite_list[2];
    static List *texture_spell = enemy_sprite_list[3];
    //Perseguir
    if((enemyPosit.x + playerPosit.x) > distanciaMax.x || (enemyPosit.y + playerPosit.y) > distanciaMax.y){
        aceleration -= 1.f * (enemyPosit - playerPosit);
    }
    //Mudança de estado
    if (abs(speed.x) < 1.f && abs(speed.y) < 1.f) {
        enemySprite.setTexture(*(texture_idle->texture));
        if (time.getElapsedTime().asSeconds() > 0.17f) {
            texture_idle = texture_idle->next;
            time.restart();
        }
    }
    if(abs(speed.x) > 1.f){
        enemySprite.setTexture(*(texture_walk->texture));
        if(time.getElapsedTime().asSeconds() > 0.17f){
            texture_walk = texture_walk->next;
            time.restart();
        }
    }

    Vector2f deltaSpeed = deltaTime * aceleration;
    Vector2f posDesejada = (speed + deltaSpeed) * deltaTime + enemyPosit;
    //Não Passar da borda
    // if (posDesejada.x < 0) {
    //     posDesejada.x = 0;
    //     speed.x = 0;
    // }
    // if (posDesejada.x + enemySprite.getTexture()->getSize().x > window->getSize().x) {
    //     posDesejada.x = window->getSize().x - (enemySprite.getTexture()->getSize().x/2);
    //     speed.x = 0;
    // }
    // if (posDesejada.y < 0) {
    //     posDesejada.y = 0;
    //     speed.y = 0;
    // }
    // if (posDesejada.y + enemySprite.getTexture()->getSize().y > window->getSize().y) {
    //     posDesejada.y = window->getSize().y - enemySprite.getTexture()->getSize().y*0.5;
    //     speed.y = 0;
    // }
    enemyPosit = posDesejada;
    speed = speed + deltaSpeed;
    if(Mouse::isButtonPressed(Mouse::Middle)){
        enemyPosit = {0.f, 500.f};
        speed = {0.f, 0.f};
    }
 
    enemySprite.setPosition(enemyPosit);
};

void Enemy::showEnemies(RenderWindow *window){
    enemySprite.setScale(0.25, 0.25);
    window->draw(enemySprite);
}

// Sprite Enemy::getEnemies(){
//     return enemySprite;
// };

