#include <Enemy.hpp>

Enemy::Enemy(){
};

void Enemy::initEnemies(Vector2f resolucao){
    this->enemyTexture.loadFromFile("assets/sprites/Furia_01.png");
    this->enemySprite.setTexture(enemyTexture);
    this->enemySprite.setScale(0.5, 0.5);
    srand(time(NULL));
    this->enemySprite.setPosition(0.f, 0.f);
    //this->enemySprite.setPosition(rand() % static_cast<int>(resolucao.x - enemySprite.getSize().x), rand() % static_cast<int>(resolucao.y - enemySprite.getSize().y));
};

void Enemy::updateEnemy(){
    //this->enemySprite.setPosition(newPosit);
};

Sprite Enemy::getEnemies(){
    return enemySprite;
};

