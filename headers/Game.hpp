#ifndef GAME_H_P_P_
#define GAME_H_P_P_

#include "lib.hpp"
#include "Menu.hpp"
#include "Enemy.hpp"
#include "TileMap.hpp"
#include "Projectile.hpp"
#include "Lista.hpp"
#include "CollisionHandler.hpp"
#include "EntityList.hpp"

using namespace sf;

class Engine{
private:
        Event event{};
        bool menu = false; //mover
        Vector2i resolucao {1280, 720};

        Texture backgroundTexture;
        Sprite backgroundSprite;

        float deltatime = 0;

        void initVariab();

        EntityList list;

        Collider collider;

    public:
        Engine();
        ~Engine();

        void pollEvents(RenderWindow *window);

        void renderCharacters(RenderWindow *window);

        Player *player;

        Enemy *enemy;

        Map *lvl1, *lvl2;

        Projectile *projectile;

        Clock timer;

        void enemy_shot (Clock cooldown);

        void update(RenderWindow *window);
        void render(RenderWindow *window);

        void newPlayer();
        void newEnemy();
        void newProjectile();
        void newObject();
};

#endif