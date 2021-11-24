#include "EventHandler.hpp"

EventHandler* EventHandler::instance = NULL;

EventHandler* EventHandler::getInstance(){
    if(instance == NULL){
        instance = new EventHandler();
    }
    return instance;
}

EventHandler::Event::Event(){

}

EventHandler::Event::~Event(){

}

EventHandler::Event::Event(sf::Event& event): ev(event) {

}

void EventHandler::Event::setEvent(sf::Event event){
    ev = event;
}

EventHandler::EventHandler(): pGraphic(NULL), pInput(NULL), pWindow(NULL){
        setGraphicHandler();
}

EventHandler::~EventHandler(){
    if(pInput != NULL)
        delete pInput;
    
    pGraphic = NULL;
    pInput = NULL;
    pWindow = NULL;
}

EventHandler::EventType EventHandler::Event::getEventType() const {
    switch (ev.type) {
        case sf::Event::EventType::KeyPressed:
            return EventType::KeyPressed;
            break;
        case sf::Event::EventType::KeyReleased:
            return EventType::KeyReleased;
            break;
        case sf::Event::EventType::TextEntered:
            return EventType::TextEntered;
            break;
        default:
            return EventType::Unknown;
            break;
      }
}

EventHandler::Key EventHandler::Event::getKeyInput() const {
      return static_cast<EventHandler::Key>(ev.key.code);
}

char EventHandler::Event::getCharString() const {
    if (ev.text.unicode < 128)
        return static_cast<char> (ev.text.unicode);
    else 
        return '\0';
}

void EventHandler::setGraphicHandler(){
    pGraphic = Graphics::getGraphics();
    if(pGraphic != NULL)
        pWindow = pGraphic->getWindow();
}

void EventHandler::setInputHandler(InputHandler* pIH){
    pInput = pIH;
}

void EventHandler::pollEvents(){
    sf::Event ev;
    while (pWindow->pollEvent(ev)) {
        Event ev_obj = Event(ev);
        if (ev_obj.getEventType() == EventType::KeyReleased && (pInput != NULL)){
                pInput->handleKeyInput(static_cast<int>(ev_obj.getKeyInput()));

        }
        else if (ev_obj.getEventType() == EventType::TextEntered)
            pInput->handleTextInput(ev_obj.getCharString());
    }

}