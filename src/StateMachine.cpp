#include "StateMachine.hpp"

class MainMenu;

using namespace sm;

StateMachine::StateMachine() {
}

StateMachine::~StateMachine() {
    State* st = NULL;
    while (states.size() != 0) {
        st = states.back();
        delete (st);
        states.pop_back();
    }
    states.clear();
}

void StateMachine::changeCurrentState(StateID id) {
    currentState = id;
    states[currentState]->restartState();
}

void StateMachine::execCurrentState() {
    states[currentState]->update();
    states[currentState]->render();
}

StateID StateMachine::getCurrentState() const{
    return currentState;
}