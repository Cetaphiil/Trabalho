#include <Game.hpp>
void Engine::initVariab(){
    this->backgroundTexture.loadFromFile("../assets/background/Fundo.png");
    this->backgroundSprite.setTexture(backgroundTexture);
    this->player = new Player();
    this->enemy = new Enemy();
    this->lvl1 = new Map("../assets/Maps/Tiles.txt");
    this->player->loader();
    this->enemy->sprite_loader();
    this->lvl1->initMap("../assets/Maps/Fase1/lvl.txt");

}

Engine::Engine(){
    this->initVariab();
}

Engine::~Engine(){
    delete this->enemy;
    delete this->player;
    delete this->lvl1;
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
}

void Engine::renderCharacters(RenderWindow *window){

    //Player
    player->show(window);
    //Enemy
    enemy->showEnemies(window);

}

void Engine::render(RenderWindow *window){
    window->clear();
    window->draw(this->backgroundSprite);
    lvl1->loadTileMap(window);
    renderCharacters(window);
    window->display();
}
