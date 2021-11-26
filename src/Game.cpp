#include <Game.hpp>

class Collider;

void Engine::initVariab(){
    pGraphics = Graphics::getGraphics();
    pEvents = EventHandler::getInstance();

    pInputs = new InputHandler;
    pEvents->setInputHandler(pInputs);

    player1 = newPlayer();
    player2 = newPlayer();
    newEnemy();
    
    player1->loader();
    enemy->sprite_loader();
    loadFirstState();
}

Engine::Engine(){
    initVariab();
}

Engine::~Engine(){
    if(enemy)
        delete enemy;
    if(player1)
        delete player1;
    if(player2)
        delete player2;
    if(lvl1)
        delete lvl1;
    if(lvl2)
        delete lvl2;

    State* st = NULL;
    while (possibleStates.size() != 0) {
        st = possibleStates.back();
        delete (st);
        possibleStates.pop_back();
    }
    possibleStates.clear();
}

void Engine::loadFirstState(){
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
        pNewState = new NewGameMenu(pInputs, this);
        if(pNewState == NULL){
            throw 0;
        }
        possibleStates.push_back(pNewState);
        pNewState= new Playing(pInputs, this);
        if(pNewState == NULL){
            throw 0;
        }
    } catch (int err) {
        if (err == 0) {
            cout << "Error allocating states " << endl;
            exit(1);
        }
    }
    states.push(possibleStates.front());
}

void Engine::initLvl(){
    // lvl1 = new Map("../assets/Maps/Tiles.txt");
    lvl1->initMap(LVL1PATH);
    // lvl1->loadTileMap();
}

void Engine::update(){

    
    pEvents->pollEvents();
    
    if((enemy->getLife() <= 0) && (enemy != NULL)) {
        listE.remove(static_cast<Entity*>(enemy));
        delete enemy;
        newEnemy();
    }

    enemy->setPlayer(player1);

    deltatime += timer.restart().asSeconds();
    float passo = 1.f/60.f;
    while(deltatime > passo){
       listE.update(pGraphics->getWindow(), deltatime);
       deltatime -= passo;
    }
    collider.CheckCollision(&listE);
}

Player* Engine::getPlayer1(){
    return player1;
}
Player* Engine::getPlayer2(){
    return player2;
}

void Engine::renderCharacters(){
    listE.show(pGraphics->getWindow());
}

void Engine::render(){
    pGraphics->getWindow()->clear();
    pGraphics->drawBackGround();
    // lvl1->loadTileMap(pGraphics->getWindow());
    renderCharacters();
    pGraphics->getWindow()->display();
}

void Engine::execState(){

    initLvl();
    // while(pGraphics->getWindow()->isOpen()){

    //     pEvents->pollEvents();

    //     pGraphics->getWindow()->clear();

    //     execCurrentState();
        
    //     pGraphics->getWindow()->display();
    // }
}

Player* Engine::newPlayer() {
    Player* aux = new Player();
    listE.add(static_cast<Entity*>(aux));
    return aux;
}

void Engine::newEnemy(){
    Enemy* aux = new Enemy();
    enemy = aux;
    enemy->setPosition({0.f, 0.f});
    listE.add(static_cast<Entity*>(aux));
}