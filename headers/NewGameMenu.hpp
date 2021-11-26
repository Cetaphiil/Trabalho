#pragma once
#include "State.hpp"
#include "Menu.hpp"
class InputHandler;
class Engine;

namespace sm{

class NewGameMenu : public Menu, public State {
private:
    Engine* pGame;

public:
    NewGameMenu(InputHandler* pIH = NULL, Engine* pG = NULL);
    ~NewGameMenu();

    void update();
    void render();
    
    void restartState();

    void run();
    void BuildLevel(int players);
};
}