#include <MainMenu.hpp>
#include "Game.hpp"
#include "InputHandler.hpp"

using namespace sm;

MainMenu::MainMenu(InputHandler* pIH, Engine* pG): Menu(pIH) ,State(static_cast<StateMachine*>(pG)), pGame(pG){
    
    setMaxButtons(static_cast<int>(MAX_NUMBER_BUTTONS_MAINMENU));
    backMain.loader(1);
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
    backMain.show(pGraphics->getGraphics()->getWindow());
    for(it = buttons.begin(); it != buttons.end(); ++it){
        Text* button = (*it);
        pGraphics->getWindow()->draw(*button);
    }
};

void MainMenu::update(float dt){
    stateMenu = true;
};

void MainMenu::run(){
    if (stateMenu) {
        stateMenu = false;
        switch (selected) {
        case 0:
            pGame->setwhatLvl(1);
            pGraphics->loadBack(pGame->getwhatLvl());
            changeState(stateID::newGame);
            break;
        case 1:
            pGame->setwhatLvl(2);
            pGraphics->loadBack(pGame->getwhatLvl());
            changeState(stateID::newGame);
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