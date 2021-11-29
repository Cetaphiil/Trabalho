#include "Playing.hpp"
#include "InputHandler.hpp"
#include "Game.hpp"

using namespace sm;

Playing::Playing(InputHandler* pIH, Engine* pG): State(static_cast<StateMachine*>(pG)), pGame(pG){

    pFase = NULL;
}

Playing::~Playing(){
    pGame = NULL;
}

void Playing::update(float dt){
    pFase->execLvl(dt);
}

void Playing::render(){
    pFase->drawAllEntities();
}

void Playing::endFase(bool faseEnd) {
    pFase = NULL;
    if (lvlEnd) {
        if (pGame->getwhatLvl() == 2) {
            changeState(stateID::mainMenu);
        } else {
            pGame->setwhatLvl(2);
            changeState(stateID::newGame);
        }
    } else {
        changeState(stateID::mainMenu);
    }
}

void Playing::restartState(){
    pFase = pGame->getLvl();
}