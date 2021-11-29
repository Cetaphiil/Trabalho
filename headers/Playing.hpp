#pragma once 

#include "State.hpp"
#include "StateMachine.hpp"
#include "Fase.hpp"

class InputHandler;
class Engine;

namespace sm{

class Playing: public State{
private:
    Engine* pGame;
    Fase* pFase;
public:
    Playing(InputHandler* pIH, Engine* pG);
    ~Playing();

    void render();
    void update(float dt);

    void endFase(bool faseEnd);

    void restartState();

};
}