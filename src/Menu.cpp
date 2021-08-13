#include <Menu.hpp>

Menu::Menu(Vector2i resolucao){

    mainFont.loadFromFile("../assets/fonts/slant_regular.ttf");

    buttons[0].setFont(mainFont);
    buttons[0].setFillColor(Color::Red);
    buttons[0].setString("Start");
    buttons[0].setPosition(Vector2f((resolucao.x / 2), (resolucao.y/ (MAX_NUMBER_BUTTONS+1) * 1)));

    buttons[1].setFont(mainFont);
    buttons[1].setFillColor(Color::Cyan);
    buttons[1].setString("Start");
    buttons[1].setPosition(Vector2f((resolucao.x / 2), (resolucao.y/ (MAX_NUMBER_BUTTONS+1) * 2)));

    buttons[2].setFont(mainFont);
    buttons[2].setFillColor(Color::Cyan);
    buttons[2].setString("Start");
    buttons[2].setPosition(Vector2f((resolucao.x / 2), (resolucao.y/ (MAX_NUMBER_BUTTONS+1) * 3)));

    buttons[3].setFont(mainFont);
    buttons[3].setFillColor(Color::Cyan);
    buttons[3].setString("Start");
    buttons[3].setPosition(Vector2f((resolucao.x / 2), (resolucao.y/ (MAX_NUMBER_BUTTONS+1) * 4)));

    selected = 0;
};

Menu::~Menu(){
    for(auto & button : buttons){
        button.setString("\0");
    }
};

void Menu::moveUp() {
    if (selected - 1 >= 0){
        buttons[selected].setFillColor(Color::Cyan);
        selected --;
        buttons[selected].setFillColor(Color::Red);
    }
};

void Menu::moveDown() {
    if (selected + 1 < MAX_NUMBER_BUTTONS-1){
        buttons[selected].setFillColor(Color::Cyan);
        selected ++;
        buttons[selected].setFillColor(Color::Red);
    }
};

int Menu::getSelected() const {
    return selected;
};

void Menu::draw(RenderTarget *target) {
    for(int i=0; i<MAX_NUMBER_BUTTONS-1; i++){
       target->draw(buttons[i]);
    }
};