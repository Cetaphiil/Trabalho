#ifndef NEWGAME_H_P_P_
#define NEWGAME_H_P_P_

#include "State.hpp"
class InputManager;

class Engine;

class NewGameState : public Menu, public State {
private:
    Engine* pGame;

public:
    NewGameState(InputManager* IM = NULL, Engine* pG = NULL);
    ~NewGameState();

    void update();
    void render();
    
    void restartState();

    void execState();

    void startNewLevel(bool isOnePLayer);
};



#endif