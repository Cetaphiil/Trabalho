#pragma once

#include "GraphicHandler.hpp"
#include "InputHandler.hpp"
#include "stdafix.hpp"

using namespace sf;

class EventHandler {
public:

enum class EventType {
    Unknown = -1,
    KeyPressed = 0,
    KeyReleased,
    TextEntered,
};

enum class Key {
    Unknown = -1,
    A,
    D,
    S,
    W,
    Escape,
    Enter,
    Backspace
};

class Event {
    private:

        sf::Event ev;

    public:
        Event();
        Event(sf::Event& event);
        ~Event();

        void setEvent(sf::Event event);

        EventType getEventType() const;
        Key getKeyInput() const;
        char getCharString() const;
};

private:

    Graphics* pGraphic;
    InputHandler* pInput;
    RenderWindow* pWindow;

    // Singleton design pattern
    static EventHandler* instance;
    EventHandler();

public:
    ~EventHandler();

    static EventHandler* getInstance();
    
    void setGraphicHandler();
    void setInputHandler(InputHandler* pIH);
   

    void pollEvents();
};