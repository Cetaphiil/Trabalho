#include <MainMenu.hpp>
#include "Game.hpp"
#include "InputHandler.hpp"

using namespace sm;

MainMenu::MainMenu(InputHandler* pIH, Engine* pG): Menu(pIH) ,State(static_cast<StateMachine*>(pG)), pGame(pG){
    
    setMaxButtons(static_cast<int>(MAX_NUMBER_BUTTONS_MAINMENU));

    font = pGraphics->getMainfont();
    
    for(int i = 0; i < max_Number_Buttons; i++){
        Text* newButton;
            newButton = new Text;
            newButton->setFont(font);
            newButton->setFillColor(Color::Cyan);
            if(i == 0){
                newButton->setString("Start in Level 1");
                newButton->setFillColor(Color::Red);
                newButton->setPosition(Vector2f((pGraphics->getWindow()->getSize().x / 2), (pGraphics->getWindow()->getSize().y/ (MAX_NUMBER_BUTTONS_MAINMENU+1) * 1)));
            }else if(i == 1){
                newButton->setString("Start in Level 2");
                newButton->setPosition(Vector2f((pGraphics->getWindow()->getSize().x / 2), (pGraphics->getWindow()->getSize().y/ (MAX_NUMBER_BUTTONS_MAINMENU+1) * 2)));
            }else if (i == 2){
                newButton->setString("Load");
                newButton->setPosition(Vector2f((pGraphics->getWindow()->getSize().x / 2), (pGraphics->getWindow()->getSize().y/ (MAX_NUMBER_BUTTONS_MAINMENU+1) * 3)));
            }else if (i == 3){
                newButton->setString("Score");
                newButton->setPosition(Vector2f((pGraphics->getWindow()->getSize().x / 2), (pGraphics->getWindow()->getSize().y/ (MAX_NUMBER_BUTTONS_MAINMENU+1) * 4)));
            }else{
                newButton->setString("Exit");
                newButton->setPosition(Vector2f((pGraphics->getWindow()->getSize().x / 2), (pGraphics->getWindow()->getSize().y/ (MAX_NUMBER_BUTTONS_MAINMENU+1) * 5)));
            }
        buttons.push_back(newButton);
    }
    
    

   
    selected = 0;
};

MainMenu::~MainMenu(){
    buttons.clear();
};

void MainMenu::render() {
    pGraphics->drawBackGround();
    for(it = buttons.begin(); it != buttons.end(); ++it){
        Text* button = (*it);
        pGraphics->getWindow()->draw(*button);
    }
};

void MainMenu::update(){
    stateMenu = true;
};

void MainMenu::run(){
    if (stateMenu) {
        stateMenu = false;
        switch (selected) {
        case 0:
            pGame->changeTopState(pGame->possibleStates.back());
            // pGame->setCurrentLevel(1);
            break;
        case 1:
            // pGame->setCurrentLevel(2);
            // changeState(StateID::NewGame);
            break;
        case 2:
            // changeState(StateID::Load);
            break;
        case 3:
            // changeState(StateID::ScoreBoard);
            break;
        case 4:
            pGraphics->getWindow()->close();
            break;
        default:
            break;
        }
    }
};

void MainMenu::restartState(){
    selected = 0;
};