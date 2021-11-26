#pragma once

#include "StateMachine.hpp"
#include "MainMenu.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "TileMap.hpp"
#include "GraphicHandler.hpp"
#include "EventHandler.hpp"
#include "InputHandler.hpp"
#include "CollisionHandler.hpp"
#include "EntityList.hpp"
#include "Spike.hpp"
#include "LandMine.hpp"

using namespace sf;

using namespace sm;

class Engine: public StateMachine
{
    private:
        Graphics* pGraphics;
        EventHandler* pEvents;
        InputHandler* pInputs;
        Collider collider;
        EntityList listE;


        float deltatime = 0;

        void initVariab();

    public:
        Engine();
        virtual ~Engine();

        void renderCharacters();

        Player *player;

        Map *lvl1, *lvl2;

        Clock timer;
        
        void loadPossibleStates();

        void execState();
        
        void update();

        void newPlayer();
        void newEnemy();
        void newProjectile();
        void newObject(int kind);
};