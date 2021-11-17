#include <Game.hpp>
void Engine::initVariab(){
    backgroundTexture.loadFromFile("../assets/background/Fundo.png");
    backgroundSprite.setTexture(backgroundTexture);
    player = new Player();
    enemy = new Enemy();
    lvl1 = new Map("../assets/Maps/Tiles.txt");
    player->loader();
    enemy->sprite_loader();
    lvl1->initMap("../assets/Maps/Fase1/lvl.txt");

}

Engine::Engine(){
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

    pollEvents(window);

    //Player
    deltatime += timer.restart().asSeconds();
    float passo = 1.f/60.f;
    while(deltatime > passo){
       this->player->update(window, passo);
       deltatime -= passo;
    }
    //Enemy
    if(!enemy->spawn){
        enemy->initEnemies(resolucao);
    }
    else{
        this->enemy->updateEnemy(window, *player);
    }
    //Shot
//    enemy_shot(enemy->cooldown);
//    if(projectile != NULL)
//        projectile->update();
}

void Engine::renderCharacters(RenderWindow *window){

    //Player
    player->show(window);
    //Enemy
    enemy->showEnemies(window);
    //Projectile
//    if(projectile != NULL)
//        projectile->show(window);

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
