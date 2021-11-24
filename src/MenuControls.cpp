#include "MenuControls.hpp"
#include "InputHandler.hpp"
#include "Menu.hpp"
#include "stdafix.hpp"

MenuControl::MenuControl(InputHandler* pIH, Menu* pM): Listener(pIH), pMenu(pM) { };

MenuControl::~MenuControl() {
    pMenu = NULL;
};

void MenuControl::execAction(int key) {
    
    switch (key){
        case 22:
            pMenu->moveUp();
            break;
        case 18:
            pMenu->moveDown();
            break;
        case 58:
            pMenu->run();
            break;
        case 36:
            pMenu->pGraphics->getWindow()->close();
            break;
    }
};