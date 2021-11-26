#pragma once 

#include "State.hpp"
#include "StateMachine.hpp"

class InputHandler;
class Engine;

namespace sm{
class Playing: public State{
private:
    Engine* pGame;
public:
    Playing(InputHandler* pIH, Engine* pG);
    ~Playing();

    void render();
    void update();

    void restartState();

};
}