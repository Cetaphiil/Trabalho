#include "Listener.hpp"

Listener::Listener(InputHandler *pI){
    this->pIH = pI;
    pIH->dockIn(this);
}

Listener::~Listener(){
    pIH->unDock(this);
    pIH = NULL;
}