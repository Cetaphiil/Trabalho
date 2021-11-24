#include "Menu.hpp"

Menu::Menu(InputHandler* pIH): pGraphics(Graphics::getGraphics()), controls(new MenuControl(pIH, this)), max_Number_Buttons(0){
}

Menu::~Menu(){
    Text* cB;
    while(buttons.size() != 0){
        cB = buttons.back();
        if(cB != NULL){
            delete cB;
        }
        buttons.pop_back();
    };
}

void Menu::moveUp() {
    if (selected - 1 >= 0){
        buttons[selected]->setFillColor(Color::Cyan);
        selected--;
        buttons[selected]->setFillColor(Color::Red);
    }
};

void Menu::moveDown() {
    if (selected + 1 < max_Number_Buttons){
        buttons[selected]->setFillColor(Color::Cyan);
        selected++;
        buttons[selected]->setFillColor(Color::Red);
    }
};

void Menu::setMaxButtons(int max){
    max_Number_Buttons = max;
}