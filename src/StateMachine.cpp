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

void StateMachine::changeTopState(stateID id) {
    currentState = id;
    states[currentState]->restartState();
}

void StateMachine::execCurrentState(float dt) {

    states[currentState]->update(dt);

    states[currentState]->render();
}