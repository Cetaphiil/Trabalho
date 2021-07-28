#include <Game.hpp>
void Engine::initVariab(){
    this->window = nullptr;
    this->resolucao.x = 800;
    this->resolucao.y = 600;
};

void Engine::initWindow(){
    this->window = new RenderWindow(VideoMode(resolucao.x, resolucao.y), "Teste", Style::Titlebar | Style::Close);
};

Engine::Engine(){
    this->initVariab();
    this->initWindow();
};

Engine::~Engine(){
    delete this->window;
};

const bool Engine::windowOpen() const{
    return this->window->isOpen();
};

void Engine::pollEvents(){

    while(this->window->pollEvent(this->event)){
        switch (this->event.type)
        {
        case Event::Closed:
            this->window->close();
            break;
        case Event::KeyPressed:
            if(this->event.key.code == Keyboard::D){
                this->enemy.enemyPosit.x = this->enemy.enemyPosit.x+1;
                this->enemy.updatePosit(this->enemy.enemyPosit);
                this->enemy.getEnemies();
                Engine::render();
            }
            break;
        default:
            break;
        }
    }
};

void Engine::update(){

    this->pollEvents();

};

void Engine::render(){

    this->window->clear();
    this->window->draw(this->enemy);
    this->window->display();

};
