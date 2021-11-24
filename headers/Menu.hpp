#pragma once

#include <vector>
#include <iterator>
#include "GraphicHandler.hpp"
#include "MenuControls.hpp"

using namespace std;
using namespace sf;

class Menu{
    public:
        Graphics* pGraphics;
    protected:

        MenuControl* controls;
        vector<Text*> buttons;
        vector<Text*>::iterator it;
        int max_Number_Buttons;
        Font font;
        int selected;
        bool stateMenu = true;

    public:
        Menu(InputHandler* pIH);
        virtual ~Menu();

        virtual void run() = 0;
        
        void moveUp();
        void moveDown();
        
        void setMaxButtons(int max);
};
