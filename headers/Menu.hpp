#ifndef MENU_H_P_P_
#define MENU_H_P_P_

#include "lib.hpp"
using namespace std;
using namespace sf;

#define MAX_NUMBER_BUTTONS 4

class Menu {
    protected:
        int selected;
        Texture back;
        Font mainFont;
        Text buttons[MAX_NUMBER_BUTTONS];
    public:
        Menu(Vector2i resolucao);
        ~Menu();

        void moveUp();
        void moveDown();
        void draw(RenderTarget *target);
        int getSelected() const;
};

#endif 