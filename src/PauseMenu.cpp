#include "PauseMenu.hpp"
#include "Game.hpp"


using namespace sm;

PauseMenu::PauseMenu(InputHandler* pIH, Engine* pG): Menu(pIH), State(static_cast<StateMachine*>(pG)), pGame(pG){
    
    setMaxButtons(static_cast<int>(MAX_NUMBER_BUTTONS_PAUSEMENU));

    font = pGraphics->getMainfont();
    
    for(int i = 0; i < max_Number_Buttons; i++){
        Text* newButton;
            newButton = new Text;
            newButton->setFont(font);
            newButton->setFillColor(Color::Cyan);
            if(i == 0){
                newButton->setString("Resume");
                newButton->setFillColor(Color::Red);
                newButton->setPosition(Vector2f((pGraphics->getWindow()->getSize().x / 2), (pGraphics->getWindow()->getSize().y/ (MAX_NUMBER_BUTTONS_MAINMENU+1) * 1)));
            }else if(i == 1){
                newButton->setString("Save");
                newButton->setPosition(Vector2f((pGraphics->getWindow()->getSize().x / 2), (pGraphics->getWindow()->getSize().y/ (MAX_NUMBER_BUTTONS_MAINMENU+1) * 2)));
            }else if (i == 2){
                newButton->setString("Exit");
                newButton->setPosition(Vector2f((pGraphics->getWindow()->getSize().x / 2), (pGraphics->getWindow()->getSize().y/ (MAX_NUMBER_BUTTONS_MAINMENU+1) * 3)));
            }
        buttons.push_back(newButton);
    }
   
    selected = 0;
}

PauseMenu::~PauseMenu(){
    buttons.clear();
}

void PauseMenu::update(float dt){
    stateMenu = true;
};

void PauseMenu::restartState(){
    selected = 0;
}

void PauseMenu::render() {
    pGraphics->drawBackGround();
    for(it = buttons.begin(); it != buttons.end(); ++it){
       Text* button = (*it);
        pGraphics->getWindow()->draw(*button);
    }
};

void PauseMenu::run(){
    if (stateMenu) {
        stateMenu = false;
        switch (selected) {
        case 0:
            changeState(stateID::playing);
            break;
        case 1:
            break;
        case 2:
            changeState(stateID::mainMenu);
            break;
        default:
            break;
        }
    }
};

