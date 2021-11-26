#pragma once
#include "stdafix.hpp"
#include "State.hpp"
#include "TileMap.hpp"
#include "Menu.hpp"
class InputHandler;
class Engine;

namespace sm{

class NewGameMenu : public Menu, public State {
private:
    Engine* pGame;
    Map map;
    const char* lvlD;

public:
    NewGameMenu(InputHandler* pIH = NULL, Engine* pG = NULL);
    ~NewGameMenu();

    void update();
    void render();
    
    void restartState();

    void run();
    void BuildLevel(const char* lvlDir);
};
}