#ifndef GAME_H_P_P_
#define GAME_H_P_P_

#include "lib.hpp"
#include "Menu.hpp"
#include "Enemy.hpp"
#include "TileMap.hpp"
#include "Projectile.hpp"
#include "Lista.hpp"

using namespace sf;

class Engine
{
private:
        Event event{};
        bool menu = false;
        Vector2i resolucao {1280, 720};

        Texture backgroundTexture;
        Sprite backgroundSprite;

        float deltatime = 0;

        void initVariab();
    public:
        Engine();
        virtual ~Engine();

        void pollEvents(RenderWindow *window);

        void renderCharacters(RenderWindow *window);

        Player *player;

        Enemy *enemy;

        Map *lvl1, *lvl2;

        Projectile *projectile;

        Clock timer;

        Lista<Character> *character_list;

        void enemy_shot (Clock cooldown);

        void update(RenderWindow *window);
        void render(RenderWindow *window);
};

#endif