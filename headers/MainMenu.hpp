#pragma once

#include "State.hpp"
#include "StateMachine.hpp"
#include "Menu.hpp"
#include "GraphicHandler.hpp"
#include "BackGround.hpp"

#define MAX_NUMBER_BUTTONS_MAINMENU 5

class InputHandler;

class Engine;

namespace sm{

class MainMenu : public Menu, public State {
    private:
        Engine* pGame;
        Background backMain;
    public:
        MainMenu(InputHandler* pIH = NULL, Engine* pGame = NULL);
        ~MainMenu();

        void render();
        void update(float dt);
        void restartState();

        void run();
};
}