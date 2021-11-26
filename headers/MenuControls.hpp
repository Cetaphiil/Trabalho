#ifndef MENUCONTROLS_H_P_P_
#define MENUCONTROLS_H_P_P_

#include "stdafix.hpp"
#include "Listener.hpp"   

class Menu;

class InputHandler;

class MenuControl : public Listener{
private:
    Menu* pMenu;

public:
    MenuControl(InputHandler* pIM, Menu* pM = NULL);
    ~MenuControl();

    void execAction(int key);

};

#endif