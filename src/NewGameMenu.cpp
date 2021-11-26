#include "NewGameMenu.hpp"
#include "Game.hpp"
#include "InputHandler.hpp"

using namespace sm;

NewGameMenu::NewGameMenu(InputHandler* pIH, Engine* pG): Menu(pIH), State(static_cast<StateMachine*>(pG)), pGame(pG){
    
    font = pGraphics->getMainFont();
    for (int i = 0; i < 3; i++)
    { 
        Text* newButton;
            newButton = new Text;
            newButton->setFont(font);
            newButton->setFillColor(Color::Cyan);
            if(i == 0){
                newButton->setString("1 player.");
                newButton->setFillColor(Color::Red);
                newButton->setPosition(Vector2f((pGraphics->getWindow()->getSize().x / 2), (pGraphics->getWindow()->getSize().y/ (MAX_NUMBER_BUTTONS_MAINMENU+1) * 1)));
            }else if(i == 1){
                newButton->setString("2 players.");
                newButton->setPosition(Vector2f((pGraphics->getWindow()->getSize().x / 2), (pGraphics->getWindow()->getSize().y/ (MAX_NUMBER_BUTTONS_MAINMENU+1) * 2)));
            }else if (i == 2){
                newButton->setString("exit");
                newButton->setPosition(Vector2f((pGraphics->getWindow()->getSize().x / 2), (pGraphics->getWindow()->getSize().y/ (MAX_NUMBER_BUTTONS_MAINMENU+1) * 3)));
            }
        buttons.push_back(newButton);
    }

    selected = 0;
}

NewGameMenu::~NewGameMenu(){
    buttons.clear();
}

void NewGameMenu::run(){
    if(stateMenu){
        stateMenu = false;
    switch (selected)
    {
        case 0:
            lvlD = LVL1PATH;
            BuildLevel(lvlD);
            break;
        case 1:
            // BuildLevel(1);
            break;
        case 2:
            pGame->popTopState();
            break;
        default:
            break;
        }
    }
};

void NewGameMenu::update(){
    stateMenu = true;
};

void NewGameMenu::render(){
    pGraphics->drawBackGround();
    for(it = buttons.begin(); it != buttons.end(); ++it){
        Text* button = (*it);
        pGraphics->getWindow()->draw(*button);
    }
};

void NewGameMenu::restartState(){
    selected = 0;
};

void NewGameMenu::BuildLevel(const char* lvlDir){
    map(static_cast<string>(lvlDir));

};