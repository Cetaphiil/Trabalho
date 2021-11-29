#pragma once

#include "State.hpp"
#include "StateMachine.hpp"
#include "Menu.hpp"
#include "GraphicHandler.hpp"

#define MAX_NUMBER_BUTTONS_PAUSEMENU 3

class InputHandler;

class Engine;

using namespace sf;

namespace sm{

class PauseMenu: public Menu, public State{
private:
    Engine* pGame;
public:
    PauseMenu(InputHandler* pIH = NULL, Engine* pGame = NULL);
    ~PauseMenu();

    void render();
    void update(float dt);
    void restartState();

    void run();
};

}