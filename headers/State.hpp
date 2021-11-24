#ifndef STATE_H_P_P_
#define STATE_H_P_P_

#include "stdafix.hpp"

namespace sm{

class StateMachine;




class State
{
    public:
    
private:
    StateMachine *pSMachine;

public:
    State(StateMachine* pStateMachine = NULL);
    virtual ~State();

    void setStateMachine(StateMachine* pStateMachine);
    void changeState(StateID id);

    virtual void update() = 0;
    virtual void render () = 0;
    virtual void restartState() = 0;
};

}
#endif