#pragma once
#include "stdafix.hpp"
#include "State.hpp"
#include "Menu.hpp"
#include "LvlConstructor.hpp"
#include "EntityList.hpp"

#define MAX_NUMBER_BUTTONS 3

class InputHandler;
class Engine;

namespace sm{

class NewGameMenu : public Menu, public State {
private:
    Engine* pGame;
    EntityList* pLE;

public:
    NewGameMenu(InputHandler* pIH = NULL, Engine* pG = NULL, EntityList *listE = NULL);
    ~NewGameMenu();

    void update(float dt);
    void render();
    
    void restartState();

    void run();
    void BuildLevel(int qP);
};
}