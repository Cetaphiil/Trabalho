#pragma once

#include "stdafix.hpp"

namespace sm{

class StateMachine;

enum stateID {
    mainMenu = 0,
    newGame = 1,
    playing = 2,
    pauseMenu,
    loadGame,
    leaderboard,
    endGame
};

class State
{
private:
    StateMachine *pSMachine;

public:
    State(StateMachine* pStateMachine = NULL);
    virtual ~State();

    void setStateMachine(StateMachine* pStateMachine);
    void changeState(sm::stateID id);
    virtual void update(float dt) = 0;
    virtual void render () = 0;
    virtual void restartState() = 0;
};

}