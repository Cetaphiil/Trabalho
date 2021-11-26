#pragma once

#include "stdafix.hpp"
#include <list>

#include "background.hpp"

#define WIDTH 1280
#define HEIGHT 720

using namespace sf;

class Graphics{
    private:
        Vector2i resolution;
        RenderWindow *window;
        Font mainFont;
        View mainView;
        Background back;

        // Singleton desing pattern
        static Graphics* instance;
        Graphics();
        
    public:
        virtual ~Graphics();

        static List* add_sprite(List* list);
        void load_Textures(const char **idle_file_names,List **sprite_list);
        Font getMainFont(){ return mainFont; };

        RenderWindow* getWindow() const;

        void setViewPosition(FloatRect pos);

        static Graphics* getGraphics();

        void drawBackGround();        

        Font getMainfont() { return mainFont; };
};