#include <Game.hpp>

class Collider;

void Engine::initVariab(){
    pGraphics = Graphics::getGraphics();
    pEvents = EventHandler::getInstance();

    pInputs = new InputHandler;
    pEvents->setInputHandler(pInputs);

    newPlayer();
    newEnemy();
    
    player->loader();
    enemy->sprite_loader();
    lvl1 = new Map("../assets/Maps/Tiles.txt");
    lvl1->initMap("../assets/Maps/Fase1/lvl.txt");
    loadPossibleStates();
}

Engine::Engine(){
    initVariab();
}

Engine::~Engine(){
    if(enemy)
        delete enemy;
    if(player)
        delete player;
    // if(player2)
    //     delete player2;
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
    
    if((enemy->getLife() <= 0) && (enemy != NULL)) {
        listE.remove(static_cast<Entity*>(enemy));
        delete enemy;
        newEnemy();
    }

    enemy->setPlayer(player);

    deltatime += timer.restart().asSeconds();
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

void Engine::render(){
    pGraphics->getWindow()->clear();
    pGraphics->drawBackGround();
    lvl1->loadTileMap(pGraphics->getWindow());
    renderCharacters();
    pGraphics->getWindow()->display();
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

void Engine::newEnemy(){
    Enemy* aux = new Enemy();
    enemy = aux;
    enemy->setPosition({0.f, 0.f});
    listE.add(static_cast<Entity*>(aux));
}