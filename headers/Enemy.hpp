#ifndef ENEMY_H_P_P_
#define ENEMY_H_P_P_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <time.h>

#include <Player.h>

using namespace sf;

class Enemy{
    protected:
        int life = 10, damage = 5;
        Vector2f speed, aceleration;
        Clock keyPressTime;
        Sprite enemySprite;
        Texture enemyTexture;
        Transform target;
        List **enemy_sprite_list;
        char **enemy_sprite_name;
    public:
        List* enemy_sprite_list_add(List* list_enemy);
        void enemy_sprite_loader();

        void load_enemy_idle();
        void load_enemy_walk();
        void load_enemy_dead();
        void load_enemy_Spell();

        Vector2f enemyPosit;
        Enemy();

        void initEnemies(Vector2f resolucao);

        void showEnemies(RenderWindow *window);
        void updateEnemy(RenderWindow *window, Player player);
        Sprite getEnemies();
};

#endif