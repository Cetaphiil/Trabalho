#include "StateMachine.hpp"

class MainMenu;

using namespace sm;

StateMachine::StateMachine() {
}

StateMachine::~StateMachine() {
    while (!states.empty()) {
        states.pop();
    }
}

void StateMachine::popTopState(){
    states.pop();
}

void StateMachine::changeTopState(State* current) {
    states.push(current);
    states.top()->restartState();;
}

void StateMachine::execCurrentState() {
    states.top()->update();
    states.top()->render();
}