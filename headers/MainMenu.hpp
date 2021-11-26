#pragma once

#include "State.hpp"
#include "StateMachine.hpp"
#include "Menu.hpp"
#include "GraphicHandler.hpp"

#define MAX_NUMBER_BUTTONS_MAINMENU 5

class InputHandler;

class Engine;

namespace sm{

class MainMenu : public Menu, public State {
    private:
        Engine* pGame;
    public:
        MainMenu(InputHandler* pIH = NULL, Engine* pGame = NULL);
        ~MainMenu();

        void render();
        void update();
        void restartState();

        void run();
};
}