#pragma once

#include "State.hpp"
#include <vector>

using namespace std;

namespace sm{

    class StateMachine{
        protected:
            vector<State*> states;
            StateID currentState;
        public:
            StateMachine();
            virtual ~StateMachine();

            void changeCurrentState(StateID id);
            void execCurrentState();
            StateID getCurrentState() const;

    };

}
