#ifndef ENEMY_H_P_P_
#define ENEMY_H_P_P_

#include <lib.hpp>

class Enemy : public Personagem{
    protected:

        List **enemy_sprite_list;
        Lista_diretorio **enemy_sprite_diretorio;
        char **enemy_spriteName;

    public:

        Vector2f enemyPosit;
        Enemy();
        void initEnemie();

        void showEnemies(RenderWindow *window);
        void updateEnemy(RenderWindow *window, Player player);
        Sprite getEnemies();
};

#endif