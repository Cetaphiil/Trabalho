#include <Game.hpp>

class Collider;

using namespace sm;

void Engine::initVariab(){
    pGraphics = Graphics::getGraphics();
    pEvents = EventHandler::getInstance();

    pInputs = new InputHandler;
    pEvents->setInputHandler(pInputs);

    p1 = newPlayer();
    p2 = NULL;

    collider = new Collider(&listE);
    
    listE.loader();
    loadStates();

}

Engine::Engine(){
    initVariab();
}

Engine::~Engine(){
   listE.freeAll();
}

void Engine::loadStates(){

    State* pNewState = NULL;
    try {
        pNewState = new MainMenu(pInputs, this);
        if (pNewState == NULL){
            throw 0;
        }
        states.push_back(pNewState);
        pNewState = new NewGameMenu(pInputs, this, &listE);
        if(pNewState == NULL){
            throw 0;
        }
        states.push_back(pNewState);
        pNewState= new Playing(pInputs, this);
        if(pNewState == NULL){
            throw 0;
        }
        states.push_back(pNewState);
        pNewState = new PauseMenu(pInputs, this);
        if(pNewState == NULL){
            throw 0;
        }
        states.push_back(pNewState);
    } catch (int err) {
        if (err == 0) {
            cout << "Error initializing states " << endl;
            exit(1);
        }
    }
    changeTopState(stateID::mainMenu);
}

void Engine::update(){
    deltatime = timer.restart().asSeconds();
    if (deltatime > 0.0167)
        deltatime = 0.0167;
    float passo = 1.f/60.f;
    while(deltatime > passo){
        pEvents->pollEvents();
        deltatime -= passo;
    }
}

void Engine::renderCharacters(){
    listE.show(pGraphics->getWindow());
}

void Engine::execState(){
    float dt;
    timer.restart();

    while(pGraphics->getWindow()->isOpen()){

        checkColision();

        pEvents->pollEvents();

        dt = timer.restart().asSeconds();
        if (dt > 0.0167)
            dt = 0.0167;

        pGraphics->getWindow()->clear();

        execCurrentState(dt);

        pGraphics->getWindow()->display();

    }
}

Player* Engine::newPlayer() {
    Player* aux = new Player();
    aux->setPosition({0.f, 3.f});
    listE.add(static_cast<Entity*>(aux));
    return aux;
}

Player* Engine::getP1(){
    return p1;
}
Player* Engine::getP2(){
    return p2;
}

Fase* Engine::getLvl() const{
    if(plvl != NULL)
        return plvl;
    return NULL;
}

void Engine::setLvl(Fase* pL){
    if(pL != NULL)
        plvl = pL;
}

void Engine::setwhatLvl(int wl){
    lvl = wl;
}
int Engine::getwhatLvl(){
    return lvl;
}
void Engine::checkColision() {
    collider->CheckCollision();
}