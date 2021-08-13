#ifndef GAME_H_P_P_
#define GAME_H_P_P_

#include "lib.hpp"
#include "Menu.hpp"
#include "Enemy.hpp"

using namespace sf;

class Engine
{
    private:
//        RenderWindow *window{};
//        Event event{};
        bool menu = false;
        Vector2i resolucao {1280, 720};

        Texture backgroundTexture;
        Sprite backgroundSprite;

        Player *player;

        Enemy *enemy;

        Menu *mainMenu;

        Clock relogio;
        float dt = 0;

        void initVariab();
//        void initWindow();
    public:
        Engine();
        virtual ~Engine();

//        const bool windowOpen() const;

//        void pollEvents();

        void renderCharacters(RenderWindow *window);


        void update(RenderWindow *window);
        void render(RenderWindow *window);
};

#endif