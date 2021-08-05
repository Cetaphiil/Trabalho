#ifndef GAME_H_P_P_
#define GAME_H_P_P_

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <stdio.h>
#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <time.h>
#include <random>

#include <Menu.hpp>
#include <Enemy.hpp>
#include <Objeto.h>

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