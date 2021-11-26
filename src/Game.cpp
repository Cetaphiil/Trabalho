#include <Game.hpp>

class Collider;

void Engine::initVariab(){
    pGraphics = Graphics::getGraphics();
    pEvents = EventHandler::getInstance();

    pInputs = new InputHandler;
    pEvents->setInputHandler(pInputs);

    newPlayer();
    for(int i = 0; i < 3; i++)
        newEnemy();
    for(int i = 0; i < 3; i++)
        newObject(9);
    for(int i = 0; i < 3; i++)
        newObject(10);
    
    listE.loader();

    lvl1 = new Map("../assets/Maps/Tiles.txt");
    lvl1->initMap("../assets/Maps/Fase1/lvl.txt");
    loadPossibleStates();
}

Engine::Engine(){
    initVariab();
}

Engine::~Engine(){

    listE.freeAll();

    if(lvl1)
        delete lvl1;
    if(lvl2)
        delete lvl2;
}

void Engine::loadPossibleStates(){
    State* pNewState = NULL;
    try {
        pNewState = new MainMenu(pInputs, this);
        if (pNewState == NULL)
            throw 0;
        states.push_back(pNewState);
    } catch (int err) {
        if (err == 0) {
            cout << "Error allocating states " << endl;
            exit(1);
        }
    }
    changeCurrentState(StateID::mainMenu);
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

void Engine::newPlayer() {
    Player* aux = new Player();
    player = aux;
    player->setPosition({0.f, 0.f});
    listE.add(static_cast<Entity*>(aux));
}

void Engine::newEnemy() {
    Enemy* aux = new Enemy();
    aux->setPosition({0.f, 0.f});
    aux->setPlayer(player);
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
            landMine = new LandMine(kind);
            listE.add(static_cast<Entity*>(landMine));
            default:
            break;
    }
}
