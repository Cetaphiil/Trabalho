#pragma once

#include "State.hpp"
#include <stack>

using namespace std;

namespace sm{

    class StateMachine{
        protected:
            vector<State*> states;
            stateID currentState;
        public:
            StateMachine();
            virtual ~StateMachine();

            void changeTopState(stateID id);
            void execCurrentState(float dt);
    };

}
