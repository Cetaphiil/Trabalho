#pragma once

#include "State.hpp"
#include <stack>

using namespace std;

namespace sm{

    class StateMachine{
        protected:
            stack<State*> states;
            state_id currentState;
        public:
            StateMachine();
            virtual ~StateMachine();

            void popTopState();
            void changeTopState(State* current);
            void execCurrentState();
    };

}
