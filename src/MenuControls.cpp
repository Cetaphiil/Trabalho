#include "MenuControls.hpp"
#include "InputHandler.hpp"
#include "Menu.hpp"
#include "stdafix.hpp"

MenuControl::MenuControl(InputHandler* pIH, Menu* pM): Listener(pIH), pMenu(pM) { };

MenuControl::~MenuControl() {
    pMenu = NULL;
};

void MenuControl::execAction() {
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        pMenu->moveUp();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        pMenu->moveDown();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        pMenu->run();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        pMenu->pGraphics->getWindow()->close();
};