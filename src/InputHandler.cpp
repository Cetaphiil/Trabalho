#include "InputHandler.hpp"

#include "Listener.hpp"

#include "cstring"

InputHandler::InputHandler() {}

InputHandler::~InputHandler() {
    listenerList.clear();
}

void InputHandler::dockIn(Listener* pL) {
    listenerList.push_back(pL);
}

void InputHandler::unDock(Listener* pL) {
    listenerList.remove(pL);
}
void InputHandler::handleKeyInput(int key) {
    for(it = listenerList.begin(); it != listenerList.end(); it++){
        (*it)->execAction(key);
    }
}

void InputHandler::handleTextInput(char string) {
       stringInput.push_back(string);
}

String InputHandler::getStringInput() {
    return stringInput;
}