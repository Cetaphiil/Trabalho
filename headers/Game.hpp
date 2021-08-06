#ifndef GAME_H_P_P_
#define GAME_H_P_P_

#include <lib.hpp>

using namespace sf;
using namespace std;

class Engine
{
    private:
        RenderWindow *window;
        Event event;
        Vector2f resolucao;

        Texture backgroundTexture;
        Sprite backgroundSprite;

        Menu mainMenu;

        Player player;

        Enemy enemy;

        void initVariab();
        void initWindow();
    public:
        Engine();
        virtual ~Engine();

        const bool windowOpen() const;

        void pollEvents();
        
        void update();
        void render();
        void renderCharacters();
};

#endif