#include <Game.hpp>
void Engine::initVariab(){
    this->window = nullptr;
    resolucao = {1280.0f, 720.0f};
    this->backgroundTexture.loadFromFile("../assets/background/Fundo.png");
    this->backgroundSprite.setTexture(backgroundTexture);
    this->player.loader();
    this->enemy.enemy_sprite_loader();
    this->enemy.initEnemies(resolucao);
}

void Engine::initWindow(){
    this->window = new RenderWindow(VideoMode(resolucao.x, resolucao.y), "Teste", Style::Titlebar | Style::Close);
}

Engine::Engine(){
    this->initVariab();
    this->initWindow();
    this->mainMenu.initMenu(resolucao);
}

Engine::~Engine(){
    delete this->window;
}

const bool Engine::windowOpen() const{
    return this->window->isOpen();
}

void Engine::pollEvents(){
    while(this->window->pollEvent(this->event)){
        switch (this->event.type)
        {
        case Event::Closed:
            this->window->close();
            break;
        default:
            break;
        }
    }
}

void Engine::update(){

    this->pollEvents();
    //Player
    dt += relogio.restart().asSeconds();
    float passo = 1.f/60.f;
    while(dt > passo){
        this->player.update(window, passo);
        dt -= passo;
    }
    //Enemy
    this->enemy.updateEnemy(window, player);
    //this->mainMenu.updateMenu(this->window);
}

void Engine::renderCharacters(){
   //Player
    player.show(window);
    //Enemy
    enemy.showEnemies(window);

}

void Engine::render(){
    this->window->clear();
    //mainMenu.renderMenu(this->window);
    this->window->draw(this->backgroundSprite);
    this->renderCharacters();
    this->window->display();
}
