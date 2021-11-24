#pragma once

#include "stdafix.hpp"
#include <list>

using namespace std;
using namespace sf;

class Listener;

class InputHandler {
private:
    list<Listener*> listenerList;
    list<Listener*>::iterator it;
    string stringInput;

public:
    InputHandler();
    ~InputHandler();

    void dockIn(Listener* pL);
    void unDock(Listener* pL);
    void handleKeyInput(int key);
    void handleTextInput(char string);
    String getStringInput();
    void deleteString();
};