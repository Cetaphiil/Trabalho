#pragma once

#include "stdafix.hpp"
#include "Fase.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "WraithInf.hpp"
#include "WraithSup.hpp"
#include "WraithQueen.hpp"
#include "Spike.hpp"
#include "LandMine.hpp"
#include "Platform.hpp"
#include "EntityList.hpp"
#include "Wall.hpp"


class Engine;

class LvlConstructor{
    private:
        Fase *lvl;
        Player *pP1, *pP2;
        const Vector2f platSize{128.0f, 128.0f};
        EntityList* pListE;
    
    public:
        LvlConstructor();
        ~LvlConstructor();

        Fase* levelBuilder(Player* p1, Player* p2, int lvl, EntityList* listE);

    private:
        void newPlat(Vector2f posit, int whatlvl, int type, int kind);
        void setP1(Vector2f posit);
        void setP2(Vector2f posit);
        void newWall(Vector2f posit, int kind);
        void newLandMine(Vector2f posit, int kind);
        void newSpike(Vector2f posit, int kind);
        void newWraithInf(Vector2f posit, int kind);
        void newWraithSup(Vector2f posit, int kind);
        void newWraithQueen(Vector2f posit, int kind);
};