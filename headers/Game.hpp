#pragma once

#include "StateMachine.hpp"
#include "MainMenu.hpp"
#include "PauseMenu.hpp"
#include "NewGameMenu.hpp"
#include "Playing.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "TileMap.hpp"
#include "GraphicHandler.hpp"
#include "EventHandler.hpp"
#include "InputHandler.hpp"
#include "CollisionHandler.hpp"
#include "EntityList.hpp"
#include "stdafix.hpp"
#include "Spike.hpp"
#include "LandMine.hpp"

using namespace sf;

using namespace sm;

class Engine: public StateMachine
{
    public:
        vector<State*> possibleStates;

    private:
        Graphics* pGraphics;
        EventHandler* pEvents;
        InputHandler* pInputs;
        float deltatime = 0;

        int playerAtGame;

        Collider collider;

        EntityList listE;

        void initVariab();

    public:
        Engine();
        virtual ~Engine();

        void renderCharacters();

        void initLvl();

        Player *player1, *player2;

        Map *lvl1, *lvl2;

        Clock timer;
        
        void loadStates();

        void execState();
        
        void exec();

        void update();
        void render();

        Player* newPlayer();
        
        void newEnemy();
        void newProjectile();
        void newObject(int kind);
};