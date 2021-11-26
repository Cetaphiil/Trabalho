#include "Playing.hpp"
#include "InputHandler.hpp"
#include "Game.hpp"

using namespace sm;

Playing::Playing(InputHandler* pIH, Engine* pG): State(static_cast<StateMachine*>(pG)), pGame(pG){
}

Playing::~Playing(){
    pGame = NULL;
}

void Playing::update(){
    pGame->update();
}

void Playing::render(){
}

// void Playing::exec(){

// }

void Playing::restartState(){

}