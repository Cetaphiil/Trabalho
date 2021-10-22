#ifndef MENU_H_P_P_
#define MENU_H_P_P_

#include "background.hpp"

using namespace std;
using namespace sf;

#define MAX_NUMBER_BUTTONS 4

class Menu {
    protected:
        int selected;
        Background background;
        Font mainFont;
        Text buttons[MAX_NUMBER_BUTTONS];
    public:
        Menu(Vector2i resolucao);
        ~Menu();

        void moveUp();
        void moveDown();
        void draw(RenderWindow *window);
        int getSelected() const;
};

#endif 