#include <Game.hpp>

void Engine::initVariab(){
    backgroundTexture.loadFromFile("../assets/background/Fundo.png");
    backgroundSprite.setTexture(backgroundTexture);
    newPlayer();
    newEnemy();
    lvl1 = new Map("../assets/Maps/Tiles.txt");
    player->loader();
    enemy->sprite_loader();
    lvl1->initMap("../assets/Maps/Fase1/lvl.txt");
}
Engine::Engine() : collider() {
    initVariab();
}

Engine::~Engine(){
    delete enemy;
    delete player;
    delete lvl1;
    delete projectile;
}

void Engine::pollEvents(RenderWindow *window){
    while(window->pollEvent(event)){
        switch (event.type)
        {
            case Event::Closed:
                window->close();
                break;
            default:
                break;
        }
    }
}

void Engine::update(RenderWindow *window){

    if((enemy->getLife() <= 0) && (enemy != NULL)) {
        list.remove(static_cast<Entity*>(enemy));
        delete enemy;
        newEnemy();
    }

    enemy->setPlayer(player);

    pollEvents(window);

    deltatime += timer.restart().asSeconds();
    float passo = 1.f/60.f;
    while(deltatime > passo){
       list.update(window, deltatime);
       deltatime -= passo;
    }
    collider.CheckCollision(&list);

}

void Engine::renderCharacters(RenderWindow *window){
    list.show(window);
}

void Engine::render(RenderWindow *window){
    window->clear();
    window->draw(this->backgroundSprite);
    lvl1->loadTileMap(window);
    renderCharacters(window);
    window->display();
}

void Engine::enemy_shot(Clock cooldown) {
    printf("%d\n", abs(int(enemy->getPosition().x - player->getPosition().x)));
    if(abs(int(enemy->getPosition().x - player->getPosition().x)) < 60){
        enemy->allow_shot = true;
    }
    if(enemy->shoud_shot && projectile != NULL) {
        projectile = new Projectile(player, enemy);
        enemy->shoud_shot = false;
    }
    if(projectile->timer.getElapsedTime().asSeconds() > 2){
        cooldown.restart();
        delete projectile;
    }
}

void Engine::newPlayer() {
    Player* aux = new Player();
    player = aux;
    player->setPosition({0.f, 0.f});
    player->setSize();
    list.add(static_cast<Entity*>(aux));
}
void Engine::newEnemy(){
    Enemy* aux = new Enemy();
    enemy = aux;
    enemy->setPosition({0.f, 0.f});
    list.add(static_cast<Entity*>(aux));
}