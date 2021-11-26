#pragma once

#include "stdafix.hpp"

namespace sm{

class StateMachine;

class State
{
private:
    StateMachine *pSMachine;

public:
    State(StateMachine* pStateMachine = NULL);
    virtual ~State();

    void setStateMachine(StateMachine* pStateMachine);

    virtual void update() = 0;
    virtual void render () = 0;
    virtual void restartState() = 0;
};

}