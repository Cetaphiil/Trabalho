#include <Enemy.hpp>

Enemy::Enemy(){
    this->initEnemies();
};

Enemy::initEnemies(){
    this->enemySprite.setSize(Vector2f(100.f, 100.f));
    this->enemySprite.setFillColor(Color::Red);
    this->enemySprite.setOutlineColor(Color::Green);
    srand(time(NULL));
    this->enemyPossit.x = rand()%600;
    this->enemyPossit.y = rand()%800;
    this->enemy.setPosition(enemyPossit.x, enemyPossit.y);
};

Enemy::updatePosit(Vector2f newPosit){
    this->enemy.Setposit(newPosit);
};

RectangleShape getEnemies(){
    return enemy;
};

