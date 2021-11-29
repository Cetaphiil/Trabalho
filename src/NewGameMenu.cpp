#include "NewGameMenu.hpp"
#include "Game.hpp"
#include "InputHandler.hpp"

using namespace sm;

NewGameMenu::NewGameMenu(InputHandler* pIH, Engine* pG, EntityList *listE): Menu(pIH), State(static_cast<StateMachine*>(pG)), pGame(pG){
    
    setMaxButtons(static_cast<int>(MAX_NUMBER_BUTTONS));

    pLE = listE;

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
    switch (selected)
    {
        case 0:
            BuildLevel(1);
            break;
        case 1:
            BuildLevel(2);
            break;
        case 2:
            changeState(stateID::mainMenu);
            break;
        default:
            break;
        }
    }

    stateMenu = false;
};

void NewGameMenu::update(float dt){
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

void NewGameMenu::BuildLevel(int qP){
    Fase* pLevel = NULL;
    Player* player1 = pGame->getP1();

    player1->restart();
    Player* player2 = NULL;
    if (qP == 2) {
        player2 = pGame->getP2();
        player2->restart();
    }
    if (pGame->getwhatLvl() == 1) {
        LvlConstructor* lvlBuild = new LvlConstructor();
        pLevel = lvlBuild->levelBuilder(player1, player2, 1, pLE);
        delete (lvlBuild);
    } else if (pGame->getwhatLvl() == 2) {
        LvlConstructor* lvlBuild = new LvlConstructor();
        pLevel = lvlBuild->levelBuilder(player1, player2, 2, pLE);
        delete (lvlBuild);
    }

    pGame->setLvl(pLevel);
    pGame->changeTopState(stateID::playing);

};