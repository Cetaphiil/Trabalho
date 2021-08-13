#include <Game.hpp>
void Engine::initVariab(){
    this->window = nullptr;
    this->backgroundTexture.loadFromFile("../assets/background/Fundo.png");
    this->backgroundSprite.setTexture(backgroundTexture);
    this->mainMenu = new Menu(resolucao);
    this->player = new Player();
    this->enemy = new Enemy();
    this->player->loader();
    this->enemy->enemy_sprite_loader();
}

void Engine::initWindow(){
    this->window = new RenderWindow(VideoMode(resolucao.x, resolucao.y), "Teste", Style::Titlebar | Style::Close);
}

Engine::Engine(){
    this->initVariab();
    this->initWindow();
}

Engine::~Engine(){
    delete this->window;
    delete this->enemy;
    delete this->player;
}

const bool Engine::windowOpen() const{
    return window->isOpen();
}

void Engine::pollEvents(){
    while(window->pollEvent(event)){
        switch (event.type)
        {
            case Event::KeyReleased:
                switch (event.key.code){
                    case Keyboard::W:
                        mainMenu->moveUp();
                        break;
                    case Keyboard::S:
                        mainMenu->moveDown();
                        break;
                    default:
                        break;
                }
                break;
            case Event::Closed:
                window->close();
                break;
            default:
                break;
        }
    }
}

void Engine::update(){

    pollEvents();

    //Player
    dt += relogio.restart().asSeconds();
    float passo = 1.f/60.f;
    while(dt > passo){
       this->player->update(window, passo);
       dt -= passo;
    }
    //Enemy
    if(!enemy->spawn){
        enemy->initEnemies(resolucao);
    }
    else{
        this->enemy->updateEnemy(window, *player);
    }
}

void Engine::renderCharacters(){

    //Player
    player->show(window);
    //Enemy
    enemy->showEnemies(window);
};

void Engine::render(){
    this->window->clear();
    this->window->draw(this->backgroundSprite);
    while(menu == false){
        mainMenu->draw(window);
        if(this->mainMenu->getSelected() == 1){
            renderCharacters();
            menu = true;
        }
        delete this->mainMenu;
    }
    renderCharacters();
    this->window->display();
}
