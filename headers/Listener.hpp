#pragma once

#include "stdafix.hpp"

#include "Inputhandler.hpp"

class Listener{
    private:
    InputHandler* pIH;
    public:
    Listener(InputHandler* pI);
    virtual ~Listener();

    virtual void execAction(int key) = 0;
};
