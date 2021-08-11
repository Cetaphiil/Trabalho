#ifndef MENU_H_P_P_
#define MENU_H_P_P_

#include "lib.hpp"
using namespace std;
using namespace sf;

class Menu {
    protected:
        Vector2f tamanhoBotoes = {150.f, 50.f};
        Texture back;
        RectangleShape botoes;
        Text startButton;
        Font mainFont;
    public:
        Menu();

        void initMenu(Vector2f resolucao);
        void updateMenu(RenderWindow *window);
        void renderMenu(RenderWindow *window);
};

#endif 