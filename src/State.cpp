#include "State.hpp"
#include "StateMachine.hpp"

using namespace sm;

State::State(StateMachine* pSM): pSMachine(pSM) { }

State::~State() {
    pSMachine = NULL;
}

void State::setStateMachine(StateMachine* pStateMachine) {
    this->pSMachine = pStateMachine;
}