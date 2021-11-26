#include <Game.hpp>

class Collider;

void Engine::initVariab(){
    pGraphics = Graphics::getGraphics();
    pEvents = EventHandler::getInstance();

    pInputs = new InputHandler;
    pEvents->setInputHandler(pInputs);

    newPlayer();
    newPlayer();
    newEnemy();
    
    listE.loader();
    loadStates();
}

Engine::Engine(){
    initVariab();
}

Engine::~Engine(){
   listE.freeAll();

    State* st = NULL;
    while (possibleStates.size() != 0) {
        st = possibleStates.back();
        delete (st);
        possibleStates.pop_back();
    }
    possibleStates.clear();
}

void Engine::loadStates(){
    State* pNewState = NULL;
    try {
        pNewState = new MainMenu(pInputs, this);
        if (pNewState == NULL){
            throw 0;
        }
        possibleStates.push_back(pNewState);
        pNewState = new PauseMenu(pInputs, this);
        if(pNewState == NULL){
            throw 0;
        }
        possibleStates.push_back(pNewState);
        // pNewState = new NewGameMenu(pInputs, this);
        // if(pNewState == NULL){
        //     throw 0;
        // }
        // possibleStates.push_back(pNewState);
        // pNewState= new Playing(pInputs, this);
        // if(pNewState == NULL){
        //     throw 0;
        // }
    } catch (int err) {
        if (err == 0) {
            cout << "Error allocating states " << endl;
            exit(1);
        }
    }
    states.push(possibleStates.front());
}

void Engine::update(){

    
    pEvents->pollEvents();
    
    deltatime = timer.restart().asSeconds();
    if (deltatime > 0.0167)
        deltatime = 0.0167;

    float passo = 1.f/60.f;
    while(deltatime > passo){
       listE.update(pGraphics->getWindow(), deltatime);
       deltatime -= passo;
    }
    collider.CheckCollision(&listE);
}

void Engine::renderCharacters(){
    listE.show(pGraphics->getWindow());
}

void Engine::execState(){

    while(pGraphics->getWindow()->isOpen()){

        pEvents->pollEvents();

        pGraphics->getWindow()->clear();

        execCurrentState();
        
        pGraphics->getWindow()->display();
    }
}

Player* Engine::newPlayer() {
    Player* aux = new Player();
    aux->setPosition({0.f, 3.f});
    listE.add(static_cast<Entity*>(aux));
    return aux;
}

void Engine::newEnemy(){
    Enemy* aux = new Enemy();
    aux->setPosition({0.f, 0.f});
    aux->setPlayer(player1);
    listE.add(static_cast<Entity*>(aux));
}

void Engine::newObject(int kind) {
    switch (kind) {
        case 9:
            Spike *spike;
            spike = new Spike(kind);
            listE.add(static_cast<Entity*>(spike));

        case 10:
            LandMine *landMine;
            landMine = new LandMine(kind, Vector2f{0.f,0.f});
            listE.add(static_cast<Entity*>(landMine));
            default:
            break;
    }
}