#ifndef PAUSEMENU_H_P_P_
#define PAUSEMENU_H_P_P_

#include "GraphicHandler.hpp"

#define MAX_NUMBER_BUTTONS_PAUSEMENU 3

using namespace sf;

class PauseMenu: public Graphics{
private:
    int selected;
    Font font;
    bool paused;
    Text buttons[MAX_NUMBER_BUTTONS_PAUSEMENU];

public:
    PauseMenu();
    ~PauseMenu();

    void moveUp();
    void moveDown();
    void draw();

    int getSelected() const;
};

#endif