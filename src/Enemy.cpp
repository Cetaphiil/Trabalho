#include <Enemy.hpp>
#include <Player.hpp>

Enemy::Enemy(){
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

Vector2f Enemy::getPosition(){
    return (sprite.getPosition());
}

List *Enemy::enemy_sprite_list_add(List *list_enemy){
    List *n = (List *) malloc(sizeof(List));
    n->next = NULL;
    if (list_enemy == NULL)
        return n;
    List *aux = list_enemy;
    while (aux->next != NULL)
        aux = aux->next;
    aux->next = n;
    return list_enemy;
};

void Enemy::load_enemy_idle() {
    List *aux = NULL;
    aux = enemy_sprite_list_add(aux);
    enemy_sprite_list[0] = aux;
    aux->texture = new sf::Texture;
    aux->texture->loadFromFile(enemy_spriteName_idle[0]);
    for (int i = 1; i < 10; i++) {
        enemy_sprite_list_add(enemy_sprite_list[0]);
        aux = aux->next;
        aux->texture = new sf::Texture;
        aux->texture->loadFromFile(enemy_spriteName_idle[i]);
    }
    aux->next = enemy_sprite_list[0];
};
void Enemy::load_enemy_walk() {
    List *aux = NULL;
    aux = enemy_sprite_list_add(aux);
    enemy_sprite_list[1] = aux;
    aux->texture = new sf::Texture;
    aux->texture->loadFromFile(enemy_spriteName_walking[0]);
    for (int i = 1; i < 10; i++) {
        enemy_sprite_list_add(enemy_sprite_list[1]);
        aux = aux->next;
        aux->texture = new sf::Texture;
        aux->texture->loadFromFile(enemy_spriteName_walking[i]);
    }
    aux->next = enemy_sprite_list[1];
};

void Enemy::load_enemy_dead() {
    List *aux = NULL;
    aux = enemy_sprite_list_add(aux);
    enemy_sprite_list[2] = aux;
    aux->texture = new sf::Texture;
    aux->texture->loadFromFile(enemy_spriteName_Dying[0]);
    for (int i = 1; i < 10; i++) {
        enemy_sprite_list_add(enemy_sprite_list[2]);
        aux = aux->next;
        aux->texture = new sf::Texture;
        aux->texture->loadFromFile(enemy_spriteName_Dying[i]);
    }
    aux->next = enemy_sprite_list[2];
};

void Enemy::load_enemy_Spell() {
    List *aux = NULL;
    aux = enemy_sprite_list_add(aux);
    enemy_sprite_list[3] = aux;
    aux->texture = new sf::Texture;
    aux->texture->loadFromFile(enemy_spriteName_Spell[0]);
    for (int i = 1; i < 10; i++) {
        enemy_sprite_list_add(enemy_sprite_list[3]);
        aux = aux->next;
        aux->texture = new sf::Texture;
        aux->texture->loadFromFile(enemy_spriteName_Spell[i]);
    }
    aux->next = enemy_sprite_list[3];
};
void Enemy::enemy_sprite_loader(){
    enemy_sprite_list = (List **) malloc(4 * sizeof(List *));

    for (int i = 0; i < 4; i++){
        enemy_sprite_list[i] = NULL;
    }

    load_enemy_idle();
    load_enemy_walk();
    load_enemy_dead();
    load_enemy_Spell();
};

void Enemy::initEnemies(Vector2i resolucao){
    spawn = true;
    Vector2i halfRes = resolucao/2;
    enemyPosit = Vector2f(rand() % (static_cast<int>(resolucao.x)/2)+halfRes.x, (rand() % static_cast<int>(resolucao.y)));
};

void Enemy::updateEnemy(RenderWindow *window, Player player){
    float gravity = 0.3f;
    aceleration = -1.f * speed;
    float deltaTime = keyPressTime.restart().asSeconds();

    Vector2f distanciaMax = {100.0f , 100.0f};
    Vector2f playerPosit = player.getPosition();

    //Perseguir
    Vector2f space = {enemyPosit-playerPosit};
    if( (space.x * space.x) < (distanciaMax.x * distanciaMax.x) || (space.y * space.y) < (distanciaMax.y * distanciaMax.y)){
        aceleration -= 1.f * (enemyPosit - playerPosit);
    }

    Vector2f deltaSpeed = deltaTime * aceleration;
    Vector2f posDesejada = (speed + deltaSpeed) * deltaTime + enemyPosit;
    //Não Passar da borda
//     if (posDesejada.x < 0) {
//         posDesejada.x = 0;
//         speed.x = 0;
//     }
//     if (posDesejada.x + enemySprite.getTexture()->getSize().x > window->getSize().x) {
//         posDesejada.x = window->getSize().x - (enemySprite.getTexture()->getSize().x/2);
//         speed.x = 0;
//     }
//     if (posDesejada.y < 0) {
//         posDesejada.y = 0;
//         speed.y = 0;
//     }
//     if (posDesejada.y + enemySprite.getTexture()->getSize().y > window->getSize().y) {
//         posDesejada.y = window->getSize().y - enemySprite.getTexture()->getSize().y*0.5;
//         speed.y = 0;
//     }
    enemyPosit = posDesejada;
    speed = speed + deltaSpeed;
    if(Mouse::isButtonPressed(Mouse::Middle)){
        enemyPosit = {0.f, 0.f};
        speed = {0.f, 0.f};
    }
};

void Enemy::showEnemies(RenderWindow *window){
    bool idle = true;
    static Clock time;
    static List *texture_idle = enemy_sprite_list[0];
    static List *texture_walk = enemy_sprite_list[1];
    static List *texture_dead = enemy_sprite_list[2];
    static List *texture_spell = enemy_sprite_list[3];


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

    enemySprite.setScale(0.40, 0.40);
    printf("%f, %f\n", enemyPosit.x, enemyPosit.y);
    enemySprite.setPosition(enemyPosit);
    window->draw(enemySprite);
}
